/*
 * Copyright (C) 2002-2004 Sistina Software, Inc. All rights reserved.  
 * Copyright (C) 2004-2007 Red Hat, Inc. All rights reserved.
 *
 * This file is part of LVM2.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU Lesser General Public License v.2.1.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef _LVM_LABEL_H
#define _LVM_LABEL_H

#include "uuid.h"
#include "device.h"
#include "toolcontext.h"

#define LABEL_ID "LABELONE"
#define LABEL_SIZE SECTOR_SIZE	/* Think very carefully before changing this */
#define LABEL_SCAN_SECTORS 4L
#define LABEL_SCAN_SIZE (LABEL_SCAN_SECTORS << SECTOR_SHIFT)

struct labeller;

void allow_reads_with_lvmetad(void);

/*
 * This is the amount of data read from each device
 * at the start of label scan.  It's meant to be big
 * enough to cover all the headers and metadata that
 * need to be read during label scan for common cases.
 */
#define ASYNC_SCAN_SIZE (128 * 1024)

struct label_read_data {
	struct dev_async_io *aio;
	char *buf; /* points to aio->buf */
	struct device *dev;
	struct dm_list list;
	int buf_len; /* same as aio->buf_len */
	int try_sync;
	int process_done;
};

/* On disk - 32 bytes */
struct label_header {
	int8_t id[8];		/* LABELONE */
	uint64_t sector_xl;	/* Sector number of this label */
	uint32_t crc_xl;	/* From next field to end of sector */
	uint32_t offset_xl;	/* Offset from start of struct to contents */
	int8_t type[8];		/* LVM2 001 */
} __attribute__ ((packed));

/* In core */
struct label {
	char type[8];
	uint64_t sector;
	struct labeller *labeller;
	struct device *dev;
	void *info;
};

struct labeller;

struct label_ops {
	/*
	 * Is the device labelled with this format ?
	 */
	int (*can_handle) (struct labeller * l, void *buf, uint64_t sector);

	/*
	 * Write a label to a volume.
	 */
	int (*write) (struct label * label, void *buf);

	/*
	 * Read a label from a volume.
	 */
	int (*read) (struct labeller * l, struct device * dev,
		     void *label_buf,
		     struct label_read_data *ld, struct label ** label);

	/*
	 * Additional consistency checks for the paranoid.
	 */
	int (*verify) (struct labeller * l, void *buf, uint64_t sector);

	/*
	 * Populate label_type etc.
	 */
	int (*initialise_label) (struct labeller * l, struct label * label);

	/*
	 * Destroy a previously read label.
	 */
	void (*destroy_label) (struct labeller * l, struct label * label);

	/*
	 * Destructor.
	 */
	void (*destroy) (struct labeller * l);
};

struct labeller {
	struct label_ops *ops;
	const struct format_type *fmt;
};

int label_init(void);
void label_exit(void);

int label_register_handler(struct labeller *handler);

struct labeller *label_get_handler(const char *name);

int label_remove(struct device *dev);
int label_read(struct device *dev, struct label **label, uint64_t scan_sector);
int label_write(struct device *dev, struct label *label);
int label_verify(struct device *dev);
struct label *label_create(struct labeller *labeller);
void label_destroy(struct label *label);

int label_scan_async(struct cmd_context *cmd);
int label_scan_sync(struct cmd_context *cmd);
int label_scan_devs_async(struct cmd_context *cmd, struct dm_list *devs);
int label_scan_devs_sync(struct cmd_context *cmd, struct dm_list *devs);
struct label_read_data *get_label_read_data(struct cmd_context *cmd, struct device *dev);

/*
 * FIXME: get rid of these force variations by making label_scan
 * never skip scanning when info is cached.
 * _force versions don't skip scanning label when info exists
 * in lvmcache.
 */
int label_scan_async_force(struct cmd_context *cmd);
int label_scan_sync_force(struct cmd_context *cmd);

#endif
