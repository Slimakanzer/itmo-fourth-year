#ifndef MAIN_H_
#define MAIN_H_
#include <linux/string.h>

#define SECTOR_SIZE 512 // sector size in bytes
#define MEMSIZE 0x19000 // N sectors by 512b
#define MBR_SIZE SECTOR_SIZE
#define MBR_DISK_SIGNATURE_OFFSET 440
#define MBR_DISK_SIGNATURE_SIZE 4
#define PARTITION_TABLE_OFFSET 446
#define PARTITION_ENTRY_SIZE 16 
#define PARTITION_TABLE_SIZE 64 
#define MBR_SIGNATURE_OFFSET 510
#define MBR_SIGNATURE_SIZE 2
#define MBR_SIGNATURE 0xAA55
#define BR_SIZE SECTOR_SIZE
#define BR_SIGNATURE_OFFSET 510
#define BR_SIGNATURE_SIZE 2
#define BR_SIGNATURE 0xAA55

/* 
 * Goto:
 * https://habr.com/ru/post/347002/
 * https://www.opennet.ru/base/dev/hdd_struct.txt.html
 * 
 */
typedef struct
{
	unsigned char boot_type;
	unsigned char start_head;
	unsigned char start_sec:6;
	unsigned char start_cyl_hi:2;
	unsigned char start_cyl;
	unsigned char part_type;
	unsigned char end_head;
	unsigned char end_sec:6;
	unsigned char end_cyl_hi:2;
	unsigned char end_cyl;
	unsigned int abs_start_sec;
	unsigned int sec_in_part;
} PartEntry;

typedef PartEntry PartTable[4];

static PartTable def_part_table =
{
	{
		boot_type: 0x0,
		start_head: 0x0,
		start_sec: 0x2,
		start_cyl: 0x0,
		part_type: 0x83,
		end_head: 0x7,
		end_sec: 0x20,
		end_cyl: 0x9F,
		abs_start_sec: 0x1,
		sec_in_part: 0x9FFF
	},
	{
		boot_type: 0x0,
		start_head: 0x8,
		start_sec: 0x1,
		start_cyl: 0x0,
		part_type: 0x05,
		end_head: 0x13,
		end_sec: 0x20,
		end_cyl: 0x9F,
		abs_start_sec: 0xA000,
		sec_in_part: 0xF000
	}
};

static unsigned int def_log_part_ebr_sectors_offset[] = {0xA000, 0xF000, 0x14000};

static const PartTable def_log_part_table[] =
{
	{
		{
			boot_type: 0x00,
			start_head: 0x8,
			start_sec: 0x02, 
			start_cyl: 0x00,
			part_type: 0x83,
			end_head: 0xB,
			end_sec: 0x20,
			end_cyl: 0x9F,
			abs_start_sec: 0x1,
			sec_in_part: 0x4FFF
		},
		{
			boot_type: 0x00,
			start_head: 0xC,
			start_sec: 0x01,
			start_cyl: 0x00,
			part_type: 0x05,
			end_head: 0xF,
			end_sec: 0x20,
			end_cyl: 0x9F,
			abs_start_sec: 0x5000,
			sec_in_part: 0x5000
		}
	},
	{
		{
			boot_type: 0x00,
			start_head: 0xC,
			start_sec: 0x02,
			start_cyl: 0x00,
			part_type: 0x83,
			end_head: 0xF,
			end_sec: 0x20,
			end_cyl: 0x9F,
			abs_start_sec: 0x1,
			sec_in_part: 0x4FFF
		},
		{
			boot_type: 0x00,
			start_head: 0x10,
			start_sec: 0x01,
			start_cyl: 0x00,
			part_type: 0x05,
			end_head: 0x13,
			end_sec: 0x20,
			end_cyl: 0x9F,
			abs_start_sec: 0x5000,
			sec_in_part: 0x5000
		}
	},
	{
		{
			boot_type: 0x00,
			start_head: 0x10,
			start_sec: 0x02,
			start_cyl: 0x00,
			part_type: 0x83,
			end_head: 0x13,
			end_sec: 0x20,
			end_cyl: 0x9F,
			abs_start_sec: 0x1,
			sec_in_part: 0x4FFF
		}
	}
};

static void copy_mbr(u8 *disk)
{
	memset(disk, 0x0, MBR_SIZE);
	*(unsigned long *)(disk + MBR_DISK_SIGNATURE_OFFSET) = 0x36E5756D;
	memcpy(disk + PARTITION_TABLE_OFFSET, &def_part_table, PARTITION_TABLE_SIZE);
	*(unsigned short *)(disk + MBR_SIGNATURE_OFFSET) = MBR_SIGNATURE;
}

static void copy_br(u8 *disk, int abs_start_sector, const PartTable *part_table)
{
	disk += (abs_start_sector * SECTOR_SIZE);
	memset(disk, 0x0, BR_SIZE);
	memcpy(disk + PARTITION_TABLE_OFFSET, part_table, PARTITION_TABLE_SIZE);
	*(unsigned short *)(disk + BR_SIGNATURE_OFFSET) = BR_SIGNATURE;
}

static void copy_mbr_n_br(u8 *disk)
{
	int i;

	copy_mbr(disk);
	for (i = 0; i < ARRAY_SIZE(def_log_part_table); i++)
	{
		copy_br(disk, def_log_part_ebr_sectors_offset[i], &def_log_part_table[i]);
	}
}

#endif