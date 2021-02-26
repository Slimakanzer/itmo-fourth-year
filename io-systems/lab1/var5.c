#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/fs.h> 		
#include <linux/cdev.h> 	
#include <linux/slab.h> 
#include <linux/string.h>
#include <linux/uaccess.h>

#define MAX_VALUES 100
#define BUFSIZE 1000

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gleb and Shust");
MODULE_DESCRIPTION("Lab 1 var 5");
MODULE_VERSION("0.1");

static int dev_open(struct inode*, struct file*);
static int dev_close(struct inode*, struct file*);
static ssize_t dev_write(struct file*, const char __user*, size_t, loff_t*);
static ssize_t dev_read(struct file*, char __user*, size_t, loff_t*);
static ssize_t proc_read(struct file*, char __user*, size_t, loff_t*);
static void read(char *buf, int * const length);

static const char d_name[] = "var5";
static const char d_greeting[] = "[VAR5]: ";
static struct proc_dir_entry* entry;
static int values[MAX_VALUES];
static int values_idx;
static dev_t d_number;
static struct cdev c_dev; 
static struct class *cl;
static int dev_major;
static int dev_minor;

static struct file_operations fops =
{
	.owner = THIS_MODULE,
	.read = proc_read,
};

static struct file_operations dops =
{
	.owner = THIS_MODULE,
	.open = dev_open,
	.release = dev_close,
	.read = dev_read,
	.write = dev_write
};

static int dev_open(struct inode *i, struct file *f)
{
	return 0;
}

static int dev_close(struct inode *i, struct file *f)
{
	return 0;
}

static ssize_t dev_write(struct file *f, const char __user *ubuf,  size_t len, loff_t *off)
{
	char buf[BUFSIZE];

	if (*off > 0 || len > BUFSIZE)
	{
		printk(KERN_INFO "[VAR5 (%d %d)]: error occour, buffer to long\n", dev_major, dev_minor);
		return -EFAULT;
	}

	if (copy_from_user(buf, ubuf, len))
		return -EFAULT;

	int i;
	int num = 0;
	for (i = 0; i < len; i++)
	{
		char ch = buf[i];
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			num++;
	}

	if (values_idx >= MAX_VALUES)
		return -EFAULT; 

	values[values_idx++] = num;

	int str_len = strlen(buf);
	*off = str_len;
	return str_len;
}

static ssize_t dev_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
	char str[MAX_VALUES * sizeof(int) + sizeof(d_greeting)];
	int length;
	read(str, &length);

	printk(KERN_INFO "[VAR5 %d %d]: %s", dev_major, dev_minor, str);
	return 0;
}

static ssize_t proc_read(struct file *f, char __user *buf,  size_t len, loff_t *off) 
{
	char str[MAX_VALUES * sizeof(int) + sizeof(d_greeting)];
	int length;
	read(str, &length);

	if (*off > 0 || len < length)
	{
		printk(KERN_INFO "[VAR5 (%d %d)]: FAILED to read proc file: invalid offset", dev_major, dev_minor);
		return 0;
	}

	if (copy_to_user(buf, str, length) != 0)
	{
		printk(KERN_INFO "[VAR5 (%d %d)]: FAILED to read proc file: failed copy to user buffer", dev_major, dev_minor);
		return -EFAULT;
	}

	*off = length;
	return length;
}

static void read(char *buf, int * const length)
{
	char *str_ptr = buf;
	str_ptr += sprintf(buf, d_greeting);

	int i;
	for (i = 0; i < values_idx; i++)
	{
		str_ptr += sprintf(str_ptr, "%d ", values[i]);
	}
	*(str_ptr++) = '\n';
	*(str_ptr++) = '\0';

	*length = str_ptr - buf;
}

static char *set_devnode(struct device *dev, umode_t *mode)
{
	if (mode != NULL)
		*mode = 0666;
	return NULL;
}

static int __init init(void)
{
    if (alloc_chrdev_region(&d_number, 0, 1, d_name) != 0)
		return -EFAULT;

    if ((cl = class_create(THIS_MODULE, d_name)) == NULL)
		goto dev_region_destroy;

	cl->devnode = set_devnode;

    if (device_create(cl, NULL, d_number, NULL, d_name) == NULL)
		goto class_destroy;

    cdev_init(&c_dev, &dops);

    if (cdev_add(&c_dev, d_number, 1) < 0)
		goto dev_destroy;
	
	if ((entry = proc_create(d_name, 0444, NULL, &fops)) == NULL)
		goto dev_destroy;

	dev_major = MAJOR(d_number);
	dev_minor = MINOR(d_number);

	printk(KERN_INFO "[VAR5 (%d %d)]: initialized\n", dev_major, dev_minor);
	return 0;

dev_destroy:
	device_destroy(cl, d_number);
class_destroy:
	class_destroy(cl);
dev_region_destroy:
	unregister_chrdev_region(d_number, 1);
	return -EFAULT;
}
 
static void __exit exit(void)
{
	cdev_del(&c_dev);
	device_destroy(cl, d_number);
	class_destroy(cl);
	unregister_chrdev_region(d_number, 1);
	proc_remove(entry);
	printk(KERN_INFO "[VAR5 (%d %d)]: exit\n", dev_major, dev_minor);
}

module_init(init);
module_exit(exit);
