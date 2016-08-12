/*
 * Copyright (C) 2001-2004 Sistina Software, Inc. All rights reserved.  
 * Copyright (C) 2004-2015 Red Hat, Inc. All rights reserved.
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

#ifndef _LVM_COMMAND_H
#define _LVM_COMMAND_H

struct cmd_context;

/* command functions */
typedef int (*command_fn) (struct cmd_context * cmd, int argc, char **argv);

/*
 * Command defintion
 *
 * A command is defined in terms of a command name,
 * required options (+args), optional options (+args),
 * required positional args, optional positional args.
 *
 * A positional arg always has non-zero pos_arg.def.types.
 * The first positional arg has pos_arg.pos of 1.
 */

/* Number of string constants accepted after an option. */
#define MAX_STR_SET 16

/* arg_def flags */
#define ARG_DEF_FLAG_NEW 1
#define ARG_DEF_FLAG_MAY_REPEAT 2

/* arg_def types, can be multiple */
enum {
	ARG_DEF_TYPE_NONE       = 0,
	ARG_DEF_TYPE_BOOL       = 1 << 0,
	ARG_DEF_TYPE_NUM_ANY    = 1 << 1,
	ARG_DEF_TYPE_STR_ANY    = 1 << 2,
	ARG_DEF_TYPE_NUM_CONST  = 1 << 3,
	ARG_DEF_TYPE_STR_CONST  = 1 << 4,
	ARG_DEF_TYPE_STR_SET    = 1 << 5,
	ARG_DEF_TYPE_NAME_ANY   = 1 << 6,
	ARG_DEF_TYPE_NAME_PV    = 1 << 7,
	ARG_DEF_TYPE_NAME_VG    = 1 << 8,
	ARG_DEF_TYPE_NAME_LV    = 1 << 9,
	ARG_DEF_TYPE_TAG        = 1 << 10,
	ARG_DEF_TYPE_SELECT     = 1 << 11,
};

/* arg_def lv_types, can be multiple */
enum {
	ARG_DEF_LV_ANY       = 0,
	ARG_DEF_LV_LINEAR    = 1 << 0,
	ARG_DEF_LV_STRIPED   = 1 << 1,
	ARG_DEF_LV_SNAPSHOT  = 1 << 2,
	ARG_DEF_LV_MIRROR    = 1 << 3,
	ARG_DEF_LV_RAID      = 1 << 4,
	ARG_DEF_LV_RAID0     = 1 << 5,
	ARG_DEF_LV_RAID1     = 1 << 6,
	ARG_DEF_LV_RAID4     = 1 << 7,
	ARG_DEF_LV_RAID5     = 1 << 8,
	ARG_DEF_LV_RAID6     = 1 << 9,
	ARG_DEF_LV_RAID10    = 1 << 10,
	ARG_DEF_LV_THIN      = 1 << 11,
	ARG_DEF_LV_THINPOOL  = 1 << 12,
	ARG_DEF_LV_CACHE     = 1 << 13,
	ARG_DEF_LV_CACHEPOOL = 1 << 14,
};

/* Description a value that follows an option or exists in a position. */

struct arg_def {
	uint32_t types;      /* ARG_DEF_TYPE_, can be multiple */
	uint32_t lv_types;   /* ARG_DEF_LV_, can be multiple */
	uint64_t num;        /* a literal number for ARG_DEF_TYPE_NUM_CONST */
	const char *str;     /* a literal string for ARG_DEF_TYPE_STR_CONST */
	const char *str_set[MAX_STR_SET]; /* literal strings for ARG_DEF_TYPE_STR_SET */
	uint32_t flags;      /* ARG_DEF_FLAG_ */
};

/* Description of an option and the value that follows it. */

struct opt_arg {
	int opt;             /* option, e.g. foo_ARG */
	struct arg_def def;  /* defines accepted values */
};

/* Description of a position and the value that exists there. */

struct pos_arg {
	int pos;             /* position, e.g. first is 1 */
	struct arg_def def;  /* defines accepted values */
};

/*
 * CMD_RO_ARGS needs to accomodate a list of options,
 * of which one is required after which the rest are
 * optional.
 */
#define CMD_RO_ARGS 64          /* required opt args */
#define CMD_OO_ARGS 150         /* optional opt args */
#define CMD_RP_ARGS 8           /* required positional args */
#define CMD_OP_ARGS 8           /* optional positional args */

/*
 * one or more from required_opt_args is required,
 * then the rest are optional.
 */
#define CMD_FLAG_ONE_REQUIRED_OPT 1

/* a register of the lvm commands */
struct command {
	const char *name;
	const char *desc;
	const char *usage;
	command_fn fn;

	unsigned int flags;

	unsigned int cmd_flags; /* CMD_FLAG_ */

	/* definitions of opt/pos args */

	/* required args following an --opt */
	struct opt_arg required_opt_args[CMD_RO_ARGS];

	/* optional args following an --opt */
	struct opt_arg optional_opt_args[CMD_OO_ARGS];

	/* required positional args */
	struct pos_arg required_pos_args[CMD_RP_ARGS];

	/* optional positional args */
	struct pos_arg optional_pos_args[CMD_OP_ARGS];

	int ro_count;
	int oo_count;
	int rp_count;
	int op_count;

	/* used for processing current position */
	int pos_count;
};

#endif
