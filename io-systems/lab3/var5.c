#include <linux/module.h>
#include <linux/version.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/moduleparam.h>
#include <linux/proc_fs.h>
#include <linux/in.h>
#include <net/arp.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/tcp.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gleb and Shust");
MODULE_DESCRIPTION("Lab 3 var 5");
MODULE_VERSION("0.1");

static int open(struct net_device *);
static int stop(struct net_device *);
static struct net_device_stats *get_stats(struct net_device *);
static netdev_tx_t start_xmit(struct sk_buff *, struct net_device *);
static ssize_t proc_read(struct file *, char __user *, size_t, loff_t *);

static char *link = "enp0s3";
module_param(link, charp, 0);

static struct proc_dir_entry *entry;
static struct net_device_stats stats;
static struct net_device *child = NULL;
struct priv
{
    struct net_device *parent;
};

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read = proc_read};

static struct net_device_ops crypto_net_device_ops = {
    .ndo_open = open,
    .ndo_stop = stop,
    .ndo_get_stats = get_stats,
    .ndo_start_xmit = start_xmit};

static char check_frame(struct sk_buff *skb, unsigned char data_shift)
{
    struct iphdr *iph = (struct iphdr *)skb_network_header(skb);
    unsigned char *proto = (unsigned char *)iph + (iph->ihl * 4);

    // total len in IP header - IP header size (does not include upper protocols like UDP, TCP)
    unsigned char *user_data_ptr = proto + data_shift;
    int data_len = ntohs(iph->tot_len) - (iph->ihl * 4);

    if (data_len < 70)
    {
        int tot_len = ntohs(iph->tot_len);
        printk(KERN_INFO "Total len: %d, Data length: %d", tot_len, data_len);
        return 1;
    }
    return 0;
}

static rx_handler_result_t handle_frame(struct sk_buff **pskb)
{
    if (check_frame(*pskb, 0))
    {
        stats.rx_packets++;
        stats.rx_bytes += (*pskb)->len;
    }
    else
    {
        stats.rx_dropped++;
    }

    (*pskb)->dev = child;
    return RX_HANDLER_ANOTHER;
}

static int open(struct net_device *dev)
{
    netif_start_queue(dev);
    printk(KERN_INFO "[%s]: device opened", dev->name);
    return 0;
}

static int stop(struct net_device *dev)
{
    netif_stop_queue(dev);
    printk(KERN_INFO "[%s]: device closed", dev->name);
    return 0;
}

static netdev_tx_t start_xmit(struct sk_buff *skb, struct net_device *dev)
{
    struct priv *priv = netdev_priv(dev);

    if (check_frame(skb, 14))
    {
        stats.tx_packets++;
        stats.tx_bytes += skb->len;
    }

    if (priv->parent)
    {
        skb->dev = priv->parent;
        skb->priority = 1;
        dev_queue_xmit(skb);
        return 0;
    }
    return NETDEV_TX_OK;
}

static struct net_device_stats *get_stats(struct net_device *dev)
{
    return &stats;
}

static ssize_t proc_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
    char str[128];

    int length = sprintf(str, "[%s]: success packets: %lu, dropped packets: %lu\n", THIS_MODULE->name, stats.rx_packets, stats.rx_dropped);
    if (length < 0)
        return -EFAULT;

    if (*off > 0 || len < length)
        return 0;

    if (copy_to_user(buf, str, length) != 0)
        return -EFAULT;

    *off += length;
    return length;
}

static void setup(struct net_device *dev)
{
    int i;
    ether_setup(dev);
    memset(netdev_priv(dev), 0, sizeof(struct priv));
    dev->netdev_ops = &crypto_net_device_ops;

    // fill in the MAC address with a phoney
    for (i = 0; i < ETH_ALEN; i++)
        dev->dev_addr[i] = (char)i;
}

static int __init vni_init(void)
{
    int err = 0;
    struct priv *priv;
    if ((child = alloc_netdev(sizeof(struct priv), THIS_MODULE->name, NET_NAME_UNKNOWN, setup)) == NULL)
        goto failed_alloc_dev;

    priv = netdev_priv(child);
    priv->parent = __dev_get_by_name(&init_net, link); //parent interface
    if (!priv->parent)
        goto failed_init_dev;

    if (priv->parent->type != ARPHRD_ETHER && priv->parent->type != ARPHRD_LOOPBACK)
        goto failed_init_dev;

    // copy IP, MAC and other information
    memcpy(child->dev_addr, priv->parent->dev_addr, ETH_ALEN);
    memcpy(child->broadcast, priv->parent->broadcast, ETH_ALEN);
    if ((err = dev_alloc_name(child, child->name)))
        goto failed_init_dev;

    if ((err = register_netdev(child)) < 0)
        goto failed_init_dev;

    rtnl_lock();
    if ((err = netdev_rx_handler_register(priv->parent, &handle_frame, NULL)) < 0)
        goto failed_register_handler;
    rtnl_unlock();

    if ((entry = proc_create(THIS_MODULE->name, 0444, NULL, &fops)) == NULL)
        goto failed_init_dev;

    printk(KERN_INFO "[%s]: Initialized, created link to %s", THIS_MODULE->name, child->name);
    return 0;

failed_register_handler:
    rtnl_unlock();
    unregister_netdev(child);
failed_init_dev:
    free_netdev(child);
failed_alloc_dev:
    printk(KERN_INFO "[%s]: FAILED initialization", THIS_MODULE->name);
    return -EFAULT;
}

static void __exit vni_exit(void)
{
    struct priv *priv = netdev_priv(child);
    if (priv->parent)
    {
        rtnl_lock();
        netdev_rx_handler_unregister(priv->parent);
        rtnl_unlock();
    }
    unregister_netdev(child);
    free_netdev(child);
    proc_remove(entry);
    printk(KERN_INFO "[%s] Uninitialized", THIS_MODULE->name);
}

module_init(vni_init);
module_exit(vni_exit);
