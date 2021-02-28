#include <linux/module.h>
#include <linux/fs.h>		
#include <linux/errno.h>	
#include <linux/types.h>	
#include <linux/fcntl.h>	
#include <linux/vmalloc.h>
#include <linux/genhd.h>
#include <linux/blkdev.h>
#include <linux/bio.h>
#include <linux/string.h>
#include "var5.h"

#define DEV_NAME "var5"
#ifndef SECTOR_SIZE
#error Error: cannot find SECTOR_SIZE. Probably you should include var5.h
#endif
#ifndef MEMSIZE
#error Error: cannot find MEMSIZE. Probably you should include var5.h
#endif

struct mydiskdrive_dev
{
	int sectors;
	u8 *data;
	spinlock_t lock;
	struct request_queue *queue;
	struct gendisk *gd;

} device;

int major;

static int my_open(struct block_device *x, fmode_t mode)	 
{
	return 0;
}

static void my_release(struct gendisk *disk, fmode_t mode)
{
}

static struct block_device_operations fops =
{
	.owner = THIS_MODULE,
	.open = my_open,
	.release = my_release,
};

static int rb_transfer(struct request *req)
{
	int dir = rq_data_dir(req);
	int ret = 0;

	sector_t start_sector = blk_rq_pos(req);
	unsigned int sector_cnt = blk_rq_sectors(req);

	struct bio_vec bv;
	#define BV_PAGE(bv) ((bv).bv_page)
	#define BV_OFFSET(bv) ((bv).bv_offset)
	#define BV_LEN(bv) ((bv).bv_len)

	struct req_iterator iter;
	sector_t sector_offset = 0;
	unsigned int sectors;
	u8 *buffer;

	rq_for_each_segment(bv, req, iter)
	{
		buffer = page_address(BV_PAGE(bv)) + BV_OFFSET(bv);
		if (BV_LEN(bv) % (SECTOR_SIZE) != 0)
		{
			printk(KERN_ERR "[%s] bio size is not a multiple ofsector size", DEV_NAME);
			ret = -EIO;
		}

		sectors = BV_LEN(bv) / SECTOR_SIZE;
		printk(KERN_DEBUG "[%s]: Sector: %llu, Sector Offset: %llu; Buffer: %p; Length: %u sectors",\
		DEV_NAME, (unsigned long long)(start_sector), (unsigned long long) (sector_offset), buffer, sectors);
		
		if (dir == WRITE)
		{
			memcpy((device.data) + ((start_sector+sector_offset) * SECTOR_SIZE), buffer ,sectors * SECTOR_SIZE);		
		}
		else
		{
			memcpy(buffer, (device.data) + ((start_sector+sector_offset) * SECTOR_SIZE), sectors * SECTOR_SIZE);	
		}
		sector_offset += sectors;
	}
	
	if (sector_offset != sector_cnt)
	{
		printk(KERN_ERR "[%s]: bio info doesn't match with the request info", DEV_NAME);
		ret = -EIO;
	}

	return ret;
}

static void dev_request(struct request_queue *q)
{
	struct request *req;
	int error;
	while ((req = blk_fetch_request(q)) != NULL)
	{
		error = rb_transfer(req);
		__blk_end_request_all(req, error);
	}
}

int disk_init(void)
{
	device.data = vmalloc(MEMSIZE * SECTOR_SIZE);
	copy_mbr_n_br(device.data);

	return MEMSIZE;	
}

void disk_cleanup(void)
{
	vfree(device.data);
}

static int __init bdev_init(void)
{
	device.sectors = disk_init();

	if ((major = register_blkdev(0, DEV_NAME)) < 0)
		goto failed_register;

	spin_lock_init(&device.lock);

	if (!(device.queue = blk_init_queue(dev_request, &device.lock)))
		goto failed_queue;

	if (!(device.gd = alloc_disk(8)))
		goto failed_gendisk;
	
	device.gd->major = major;
	device.gd->first_minor = 0;
	device.gd->fops = &fops;
	device.gd->private_data = &device;
	device.gd->queue = device.queue;
	sprintf(device.gd->disk_name, DEV_NAME);

	printk(KERN_INFO "[%s]: initialized, major %d", DEV_NAME, major);
	set_capacity(device.gd, device.sectors);  
	add_disk(device.gd);
	return 0;

failed_gendisk:
	blk_cleanup_queue(device.queue);
failed_queue:
	unregister_blkdev(major, DEV_NAME);
failed_register:
	disk_cleanup();
	printk(KERN_ERR "[%s]: failed initialization", DEV_NAME);
	return -1;
}

static void __exit bdev_exit(void)
{
	del_gendisk(device.gd);
	put_disk(device.gd);
	blk_cleanup_queue(device.queue);
	unregister_blkdev(major, DEV_NAME);
	disk_cleanup();
}

module_init(bdev_init);
module_exit(bdev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gleb and Shust");
MODULE_DESCRIPTION("Lab 2 var 5");
MODULE_VERSION("0.1");
