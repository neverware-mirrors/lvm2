/*
 * Copyright (C) 2001-2004 Sistina Software, Inc. All rights reserved.
 * Copyright (C) 2004-2016 Red Hat, Inc. All rights reserved.
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

/*
 * Put all long args that don't have a corresponding short option first.
 */
/* *INDENT-OFF* */
arg(ARG_UNUSED, '-', "", 0, 0, 0, NULL)  /* place holder for unused 0 value */

arg(abort_ARG, '\0', "abort", 0, 0, 0,
    "#pvmove\n"
    "Abort any pvmove operations in progress. If a pvmove was started\n"
    "with the --atomic option, then all LVs will remain on the source PV.\n"
    "Otherwise, segments that have been moved will remain on the\n"
    "destination PV, while unmoved segments will remain on the source PV.\n"
    "#lvpoll\n"
    "Stop processing a poll operation in lvmpolld.\n")

arg(activationmode_ARG, '\0', "activationmode", activationmode_VAL, 0, 0,
    "Determines if LV activation is allowed when PVs are missing,\n"
    "e.g. because of a device failure.\n"
    "\\fBcomplete\\fP only allows LVs with no missing PVs to be activated,\n"
    "and is the most restrictive mode.\n"
    "\\fBdegraded\\fP allows RAID LVs with missing PVs to be activated.\n"
    "(This does not include the \"mirror\" type, see \"raid1\" instead.)\n"
    "\\fBpartial\\fP allows any LV with missing PVs to be activated, and\n"
    "should only be used for recovery or repair.\n"
    "For default, see lvm.conf/activation_mode.\n")

arg(addtag_ARG, '\0', "addtag", tag_VAL, ARG_GROUPABLE, 0,
    "Adds a tag to a PV, VG or LV. This option can be repeated to add\n"
    "multiple tags at once. See lvm(8) for information about tags.\n")

arg(aligned_ARG, '\0', "aligned", 0, 0, 0,
    "Use with --separator to align the output columns\n")

arg(alloc_ARG, '\0', "alloc", alloc_VAL, 0, 0,
    "Determines the allocation policy when a command needs to allocate\n"
    "Physical Extents (PEs) from the VG. Each VG and LV has an allocation policy\n"
    "which can be changed with vgchange/lvchange, or overriden on the\n"
    "command line.\n"
    "\\fBnormal\\fP applies common sense rules such as not placing parallel stripes\n"
    "on the same PV.\n"
    "\\fBinherit\\fP applies the VG policy to an LV.\n"
    "\\fBcontiguous\\fP requires new PEs be placed adjacent to existing PEs.\n"
    "\\fBcling\\fP places new PEs on the same PV as existing PEs in the same\n"
    "stripe of the LV.\n"
    "If there are sufficient PEs for an allocation, but normal does not\n"
    "use them, \\fBanywhere\\fP will use them even if it reduces performance,\n"
    "e.g. by placing two stripes on the same PV.\n"
    "Optional positional PV args on the command line can also be used to limit\n"
    "which PVs the command will use for allocation.\n")

arg(atomic_ARG, '\0', "atomic", 0, 0, 0,
    "Makes a pvmove operation atomic, ensuring that all affected LVs are\n"
    "moved to the destination PV, or none are if the operation is aborted.\n")

arg(atversion_ARG, '\0', "atversion", string_VAL, 0, 0,
    "Specify an LVM version in x.y.z format where x is the major version,\n"
    "the y is the minor version and z is the patchlevel (e.g. 2.2.106).\n"
    "When configuration is displayed, the configuration settings recognized\n"
    "at this LVM version will be considered only. This can be used\n"
    "to display a configuration that a certain LVM version understands and\n"
    "which does not contain any newer settings for which LVM would\n"
    "issue a warning message when checking the configuration.\n")

arg(binary_ARG, '\0', "binary", 0, 0, 0,
    "Use binary values \"0\" or \"1\" instead of descriptive literal values\n"
    "for columns that have exactly two valid values to report (not counting\n"
    "the \"unknown\" value which denotes that the value could not be determined).\n")

arg(bootloaderareasize_ARG, '\0', "bootloaderareasize", sizemb_VAL, 0, 0,
    "Create a separate bootloader area of specified size besides PV's data\n"
    "area. The bootloader area is an area of reserved space on the PV from\n"
    "which LVM will not allocate any extents and it's kept untouched. This is\n"
    "primarily aimed for use with bootloaders to embed their own data or metadata.\n"
    "The start of the bootloader area is always aligned, see also --dataalignment\n"
    "and --dataalignmentoffset. The bootloader area size may eventually\n"
    "end up increased due to the alignment, but it's never less than the\n"
    "size that is requested. To see the bootloader area start and size of\n"
    "an existing PV use pvs -o +pv_ba_start,pv_ba_size.\n")

arg(cache_long_ARG, '\0', "cache", 0, 0, 0,
    "#pvscan\n"
    "Scan one or more devices and send the metadata to lvmetad.\n"
    "#vgscan\n"
    "Scan all devices and send the metadata to lvmetad.\n"
    "#lvscan\n"
    "Scan the devices used by an LV and send the metadata to lvmetad.\n")

arg(cachemode_ARG, '\0', "cachemode", cachemode_VAL, 0, 0,
    "Specifies when writes to a cache LV should be considered complete.\n"
    "\\fBwriteback\\fP considers a write complete as soon as it is\n"
    "stored in the cache pool.\n"
    "\\fBwritethough\\fP considers a write complete only when it has\n"
    "been stored in both the cache pool and on the origin LV.\n"
    "While writethrough may be slower for writes, it is more\n"
    "resilient if something should happen to a device associated with the\n"
    "cache pool LV. With writethrough, all reads are served\n"
    "from the origin LV (all reads miss the cache) and all writes are\n"
    "forwarded to the origin LV; additionally, write hits cause cache\n"
    "block invalidates. See lvmcache(7) for more information.\n")

arg(cachepool_ARG, '\0', "cachepool", lv_VAL, 0, 0,
    "The name of a cache pool LV.\n")

arg(commandprofile_ARG, '\0', "commandprofile", string_VAL, 0, 0,
    "The command profile to use for command configuration.\n"
    "See lvm.conf(5) for more information about profiles.\n")

arg(config_ARG, '\0', "config", string_VAL, 0, 0,
    "Config settings for the command. These override lvm.conf settings.\n"
    "The String arg uses the same format as lvm.conf,\n"
    "or may use section/field syntax.\n"
    "See lvm.conf(5) for more information about config.\n")

arg(configreport_ARG, '\0', "configreport", configreport_VAL, ARG_GROUPABLE, 1,
    "See lvmreport(7).\n")

arg(configtype_ARG, '\0', "typeconfig", configtype_VAL, 0, 0,
    "See lvmreport(7).\n")

arg(corelog_ARG, '\0', "corelog", 0, 0, 0,
    "An alias for --mirrorlog core.\n")

arg(dataalignment_ARG, '\0', "dataalignment", sizekb_VAL, 0, 0,
    "Align the start of the data to a multiple of this number.\n"
    "Also specify an appropriate Physical Extent size when creating a VG.\n"
    "To see the location of the first Physical Extent of an existing PV,\n"
    "use pvs -o +pe_start. In addition, it may be shifted by an alignment offset.\n"
    "See lvm.conf/data_alignment_offset_detection and --dataalignmentoffset.\n")

arg(dataalignmentoffset_ARG, '\0', "dataalignmentoffset", sizekb_VAL, 0, 0,
    "Shift the start of the data area by this additional offset.\n")

arg(deltag_ARG, '\0', "deltag", tag_VAL, ARG_GROUPABLE, 0,
    "Deletes a tag from a PV, VG or LV. This option can be repeated to delete\n"
    "multiple tags at once. See lvm(8) for information about tags.\n")

arg(detachprofile_ARG, '\0', "detachprofile", 0, 0, 0,
    "Detaches a metadata profile from a VG or LV.\n"
    "See lvm.conf(5) for more information about profiles.\n")

arg(discards_ARG, '\0', "discards", discards_VAL, 0, 0,
    "Specifies how the device-mapper thin pool layer in the kernel should\n"
    "handle discards.\n"
    "\\fBignore\\fP causes the thin pool to ignore discards.\n"
    "\\fBnopassdown\\fP causes the thin pool to process discards itself to\n"
    "allow reuse of unneeded extents in the thin pool.\n"
    "\\fBpassdown\\fP causes the thin pool to process discards itself\n"
    "(like nopassdown) and pass the discards to the underlying device.\n")

arg(driverloaded_ARG, '\0', "driverloaded", bool_VAL, 0, 0,
    "If set to no, the command will not attempt to use device-mapper.\n"
    "For testing and debugging.\n")

arg(errorwhenfull_ARG, '\0', "errorwhenfull", bool_VAL, 0, 0,
    "Specifies thin pool behavior when data space is exhausted.\n"
    "When yes, device-mapper will immediately return an error\n"
    "when a thin pool is full and an I/O request requires space.\n"
    "When no, device-mapper will queue these I/O requests for a\n"
    "period of time to allow the thin pool to be extended.\n"
    "Errors are returned if no space is available after the timeout.\n"
    "(Also see dm-thin-pool kernel module option no_space_timeout.)\n")

arg(force_long_ARG, '\0', "force", 0, ARG_COUNTABLE, 0, NULL)

arg(foreign_ARG, '\0', "foreign", 0, 0, 0,
    "Report/display foreign VGs that would otherwise be skipped.\n"
    "See lvmsystemid(7) for more information about foreign VGs.\n")

arg(handlemissingpvs_ARG, '\0', "handlemissingpvs", 0, 0, 0,
    "Allows a polling operation to continue when PVs are missing,\n"
    "e.g. for repairs due to faulty devices.\n")

arg(ignoreadvanced_ARG, '\0', "ignoreadvanced", 0, 0, 0,
    "Exclude advanced configuration settings from the output.\n")

arg(ignorelocal_ARG, '\0', "ignorelocal", 0, 0, 0,
    "Ignore local section.\n")

arg(ignorelockingfailure_ARG, '\0', "ignorelockingfailure", 0, 0, 0,
    "Allows a command to continue with read-only metadata\n"
    "operations after locking failures.\n")

arg(ignoremonitoring_ARG, '\0', "ignoremonitoring", 0, 0, 0,
    "Do not interact with dmeventd unless --monitor is specified.\n"
    "Do not use this if dmeventd is already monitoring a device.\n")

arg(ignoreskippedcluster_ARG, '\0', "ignoreskippedcluster", 0, 0, 0,
    "Use to avoid exiting with an non-zero status code if the command is run\n"
    "without clustered locking and clustered VGs are skipped.\n")

arg(ignoreunsupported_ARG, '\0', "ignoreunsupported", 0, 0, 0,
    "Exclude unsupported configuration settings from the output. These settings are\n"
    "either used for debugging and development purposes only or their support is not\n"
    "yet complete and they are not meant to be used in production. The \\fBcurrent\\fP\n"
    "and \\fBdiff\\fP types include unsupported settings in their output by default,\n"
    "all the other types ignore unsupported settings.\n")

arg(labelsector_ARG, '\0', "labelsector", number_VAL, 0, 0,
    "By default the PV is labelled with an LVM2 identifier in its second\n"
    "sector (sector 1). This lets you use a different sector near the\n"
    "start of the disk (between 0 and 3 inclusive - see LABEL_SCAN_SECTORS\n"
    "in the source). Use with care.\n")

arg(lockopt_ARG, '\0', "lockopt", string_VAL, 0, 0,
    "Used to pass options for special cases to lvmlockd.\n"
    "See lvmlockd(8) for more information.\n")

arg(lockstart_ARG, '\0', "lockstart", 0, 0, 0,
    "Start the lockspace of a shared VG in lvmlockd.\n"
    "lvmlockd locks becomes available for the VG, allowing LVM to use the VG.\n"
    "See lvmlockd(8) for more information.\n")

arg(lockstop_ARG, '\0', "lockstop", 0, 0, 0,
    "Stop the lockspace of a shared VG in lvmlockd.\n"
    "lvmlockd locks become unavailable for the VG, preventing LVM from using the VG.\n"
    "See lvmlockd(8) for more information.\n")

arg(locktype_ARG, '\0', "locktype", locktype_VAL, 0, 0,
    "#vgchange\n"
    "Change the VG lock type to or from a shared lock type used with lvmlockd.\n"
    "See lvmlockd(8) for more information.\n"
    "#vgcreate\n"
    "Specify the VG lock type directly in place of using --shared.\n"
    "See lvmlockd(8) for more information.\n")

arg(logonly_ARG, '\0', "logonly", 0, 0, 0,
    "Suppress command report and display only log report.\n")

arg(maxrecoveryrate_ARG, '\0', "maxrecoveryrate", sizekb_VAL, 0, 0,
    "Sets the maximum recovery rate for a RAID LV.  The rate value\n"
    "is an amount of data per second for each device in the array.\n"
    "Setting the rate to 0 means it will be unbounded.\n")

arg(merge_ARG, '\0', "merge", 0, 0, 0,
    "An alias for --mergethin, --mergemirrors, or --mergesnapshot,\n"
    "depending on the type of LV.\n")

arg(mergemirrors_ARG, '\0', "mergemirrors", 0, 0, 0,
    "Merge LV images that were split from a raid1 LV.\n"
    "See --splitmirrors with --trackchanges.\n")

arg(mergesnapshot_ARG, '\0', "mergesnapshot", 0, 0, 0,
    "Merge COW snapshot LV into its origin.\n"
    "When merging a snapshot, if both the origin and snapshot LVs are not open,\n"
    "the merge will start immediately. Otherwise, the merge will start the\n"
    "first time either the origin or snapshot LV are activated and both are\n"
    "closed. Merging a snapshot into an origin that cannot be closed, for\n"
    "example a root filesystem, is deferred until the next time the origin\n"
    "volume is activated. When merging starts, the resulting LV will have the\n"
    "origin's name, minor number and UUID. While the merge is in progress,\n"
    "reads or writes to the origin appear as being directed to the snapshot\n"
    "being merged. When the merge finishes, the merged snapshot is removed.\n"
    "Multiple snapshots may be specified on the command line or a @tag may be\n"
    "used to specify multiple snapshots be merged to their respective origin.\n")

arg(mergethin_ARG, '\0', "mergethin", 0, 0, 0,
    "Merge thin LV into its origin LV.\n"
    "The origin thin LV takes the content of the thin snapshot,\n"
    "and the thin snapshot LV is removed.\n")

arg(mergedconfig_ARG, '\0', "mergedconfig", 0, 0, 0,
    "When the command is run with --config\n"
    "and/or --commandprofile (or using LVM_COMMAND_PROFILE\n"
    "environment variable), --profile, or --metadataprofile,\n"
    "merge all the contents of the \"config cascade\" before displaying it.\n"
    "Without merging, only the configuration at the front of the\n"
    "cascade is displayed.\n"
    "See lvm.conf(5) for more information about config.\n")

arg(metadatacopies_ARG, '\0', "metadatacopies", metadatacopies_VAL, 0, 0,
    "For commands starting with 'pv', this is an alias for --pvmetadatacopies.\n"
    "For commands starting with 'vg', this is an alias for --vgmetadatacopies.\n")

arg(metadataignore_ARG, '\0', "metadataignore", bool_VAL, 0, 0,
    "Specifies the metadataignore property of a PV.\n"
    "If yes, metadata areas on the PV are ignored, and lvm will\n"
    "not store metadata in the metadata areas of the PV.\n"
    "If no, lvm will store metadata on the PV.\n")

arg(metadataprofile_ARG, '\0', "metadataprofile", string_VAL, 0, 0,
    "The metadata profile to use for command configuration.\n"
    "See lvm.conf(5) for more information about profiles.\n")

arg(metadatasize_ARG, '\0', "metadatasize", sizemb_VAL, 0, 0,
    "The approximate amount of space used for each VG metadata area.\n"
    "The size may be rounded.\n")

arg(minor_ARG, '\0', "minor", number_VAL, ARG_GROUPABLE, 0,
    "A block device minor number.\n")

arg(minrecoveryrate_ARG, '\0', "minrecoveryrate", sizekb_VAL, 0, 0,
    "Sets the minimum recovery rate for a RAID LV.  The rate value\n"
    "is an amount of data per second for each device in the array.\n"
    "Setting the rate to 0 means it will be unbounded.\n")

arg(mirrorlog_ARG, '\0', "mirrorlog", mirrorlog_VAL, 0, 0,
    "Specifies the type of mirror log for LVs with the \"mirror\" type\n"
    "(does not apply to the \"raid1\" type.)\n"
    "\\fBdisk\\fP is a persistent log and requires a small amount of\n"
    "storage space, usually on a separate device from the data being mirrored.\n"
    "\\fBcore\\fP is not persistent; the log is kept only in memory.\n"
    "In this case, the mirror must be synchronized (by copying LV data from\n"
    "the first device to others) each time the LV is activated, e.g. after reboot.\n"
    "\\fBmirrored\\fP is a persistent log that is itself mirrored.\n")

arg(mirrorsonly_ARG, '\0', "mirrorsonly", 0, 0, 0, NULL)

arg(mknodes_ARG, '\0', "mknodes", 0, 0, 0,
    "Also checks the LVM special files in /dev that are needed for active\n"
    "LVs and creates any missing ones and removes unused ones.\n")

arg(monitor_ARG, '\0', "monitor", bool_VAL, 0, 0,
    "Start (yes) or stop (no) monitoring an LV with dmeventd.\n"
    "dmeventd monitors kernel events for an LV, and performs\n"
    "automated maintenance for the LV in reponse to specific events.\n"
    "See dmeventd(8) for more information.\n")

arg(nameprefixes_ARG, '\0', "nameprefixes", 0, 0, 0,
    "Add an \"LVM2_\" prefix plus the field name to the output. Useful\n"
    "with --noheadings to produce a list of field=value pairs that can\n"
    "be used to set environment variables (for example, in udev rules).\n")

arg(noheadings_ARG, '\0', "noheadings", 0, 0, 0,
    "Suppress the headings line that is normally the first line of output.\n"
    "Useful if grepping the output.\n")

arg(nohistory_ARG, '\0', "nohistory", 0, 0, 0,
    "Do not record history of LVs being removed.\n"
    "This has no effect unless the configuration setting\n"
    "metadata/record_lvs_history is enabled.\n")

arg(nolocking_ARG, '\0', "nolocking", 0, 0, 0,
    "Disable locking.\n")

arg(norestorefile_ARG, '\0', "norestorefile", 0, 0, 0,
    "In conjunction with --uuid, this allows a uuid to be specified\n"
    "without also requiring that a backup of the metadata be provided.\n")

arg(nosuffix_ARG, '\0', "nosuffix", 0, 0, 0,
    "Suppress the suffix on output sizes. Use with --units\n"
    "(except h and H) if processing the output.\n")

arg(nosync_ARG, '\0', "nosync", 0, 0, 0,
    "Causes the creation of mirror, raid1, raid4, raid5 and raid10 to skip the\n"
    "initial synchronization. In case of mirror, raid1 and raid10, any data\n"
    "written afterwards will be mirrored, but the original contents will not be\n"
    "copied. In case of raid4 and raid5, no parity blocks will be written,\n"
    "though any data written afterwards will cause parity blocks to be stored.\n"
    "This is useful for skipping a potentially long and resource intensive initial\n"
    "sync of an empty mirror/raid1/raid4/raid5 and raid10 LV.\n"
    "This option is not valid for raid6, because raid6 relies on proper parity\n"
    "(P and Q Syndromes) being created during initial synchronization in order\n"
    "to reconstruct proper user date in case of device failures.\n"
    "raid0 and raid0_meta do not provide any data copies or parity support\n"
    "and thus do not support initial synchronization.\n")

arg(notifydbus_ARG, '\0', "notifydbus", 0, 0, 0,
    "Send a notification to D-Bus. The command will exit with an error\n"
    "if LVM is not built with support for D-Bus notification, or if the\n"
    "notify_dbus config setting is disabled.\n")

arg(noudevsync_ARG, '\0', "noudevsync", 0, 0, 0,
    "Disables udev synchronisation. The process will not wait for notification\n"
    "from udev. It will continue irrespective of any possible udev processing\n"
    "in the background. Only use this if udev is not running or has rules that\n"
    "ignore the devices LVM creates.\n")

arg(originname_ARG, '\0', "originname", lv_VAL, 0, 0,
    "Specifies the name to use for the external origin LV when converting an LV\n"
    "to a thin LV. The LV being converted becomes a read-only external origin\n"
    "with this name.\n")

arg(physicalvolumesize_ARG, '\0', "setphysicalvolumesize", sizemb_VAL, 0, 0,
    "Overrides the automatically detected size of the PV.\n"
    "Use with care, or prior to reducing the physical size of the device.\n")

arg(poll_ARG, '\0', "poll", bool_VAL, 0, 0,
    "When yes, start the background transformation of an LV.\n"
    "An incomplete transformation, e.g. pvmove or lvconvert interrupted\n"
    "by reboot or crash, can be restarted from the last checkpoint with --poll y.\n"
    "When no, background transformation of an LV will not occur, and the\n"
    "transformation will not complete. It may not be appropriate to immediately\n"
    "poll an LV after activation, in which case --poll n can be used to defer\n"
    "polling until a later --poll y command.\n")

arg(polloperation_ARG, '\0', "polloperation", polloperation_VAL, 0, 0,
    "The command to perform from lvmpolld.\n")

/* Not used. */
arg(pooldatasize_ARG, '\0', "pooldatasize", sizemb_VAL, 0, 0, NULL)

arg(poolmetadata_ARG, '\0', "poolmetadata", lv_VAL, 0, 0,
    "The name of a an LV to use for storing pool metadata.\n")

arg(poolmetadatasize_ARG, '\0', "poolmetadatasize", sizemb_VAL, 0, 0,
    "The size of the pool metadata LV created by the command.\n")

arg(poolmetadataspare_ARG, '\0', "poolmetadataspare", bool_VAL, 0, 0,
    "Enable or disable the automatic creation and management of a\n"
    "spare pool metadata LV in the VG. A spare metadata LV is reserved\n"
    "space that can be used when repairing a pool.\n")

arg(profile_ARG, '\0', "profile", string_VAL, 0, 0,
    "An alias for --commandprofile or --metadataprofile, depending\n"
    "on the command.\n")

arg(pvmetadatacopies_ARG, '\0', "pvmetadatacopies", pvmetadatacopies_VAL, 0, 0,
    "The number of metadata areas to set aside on a PV for storing VG metadata.\n"
    "When 2, one copy of the VG metadata is stored at the front of the PV\n"
    "and a second copy is stored at the end.\n"
    "When 1, one copy of the VG metadata is stored at the front of the PV\n"
    "(starting in the 5th sector).\n"
    "When 0, no copies of the VG metadata are stored on the given PV.\n"
    "This may be useful in VGs containing many PVs (this places limitations\n"
    "on the ability to use vgsplit later.)\n")

arg(raidrebuild_ARG, '\0', "raidrebuild", pv_VAL, ARG_GROUPABLE, 0,
    "An alias for --rebuild.\n")

arg(raidmaxrecoveryrate_ARG, '\0', "raidmaxrecoveryrate", sizekb_VAL, 0, 0,
    "An alias for --maxrecoveryrate.\n")

arg(raidminrecoveryrate_ARG, '\0', "raidminrecoveryrate", sizekb_VAL, 0, 0,
    "An alias for --minrecoveryrate.\n")

arg(raidsyncaction_ARG, '\0', "raidsyncaction", syncaction_VAL, 0, 0,
    "An alias for --syncaction.\n")

arg(raidwritebehind_ARG, '\0', "raidwritebehind", number_VAL, 0, 0,
    "An alias for --writebehind.\n")

arg(raidwritemostly_ARG, '\0', "raidwritemostly", writemostly_VAL, ARG_GROUPABLE, 0,
    "An alias for --writemostly.\n")

arg(readonly_ARG, '\0', "readonly", 0, 0, 0,
    "Run the command in a special read-only mode which will read on-disk\n"
    "metadata without needing to take any locks. This can be used to peek\n"
    "inside metadata used by a virtual machine image while the virtual\n"
    "machine is running.\n"
    "It can also be used to peek inside the metadata of clustered VGs\n"
    "when clustered locking is not configured or running. No attempt\n"
    "will be made to communicate with the device-mapper kernel driver, so\n"
    "this option is unable to report whether or not LVs are\n"
    "actually in use.\n")

arg(refresh_ARG, '\0', "refresh", 0, 0, 0,
    "If the LV is active, reload its metadata.\n"
    "This is not necessary in normal operation, but may be useful\n"
    "if something has gone wrong, or if some form of manual LV\n"
    "sharing is being used.\n")

arg(removemissing_ARG, '\0', "removemissing", 0, 0, 0,
    "Removes all missing PVs from the VG, if there are no LVs allocated\n"
    "on them. This resumes normal operation of the VG (new LVs may again\n"
    "be created, changed and so on).\n"
    "If this is not possible because LVs are referencing the missing PVs,\n"
    "this option can be combined with --force to have the command remove\n"
    "any partial LVs. In this case, any LVs and dependent snapshots that\n"
    "were partly on the missing disks are removed completely, including\n"
    "those parts on disks that are still present.\n"
    "If LVs spanned several disks, including ones that are lost, salvaging\n"
    "some data first may be possible by activating LVs in partial mode.\n")

arg(rebuild_ARG, '\0', "rebuild", pv_VAL, ARG_GROUPABLE, 0,
    "Selects a PV to rebuild in a raid LV. Multiple PVs can be rebuilt by\n"
    "repeating this option.\n"
    "Use this option in place of --resync or --syncaction repair when the\n"
    "PVs with corrupted data are known, and their data should be reconstructed\n"
    "rather than reconstructing default (rotating) data.\n")

arg(repair_ARG, '\0', "repair", 0, 0, 0,
    "Replace failed PVs in a raid or mirror LV, or run a repair\n"
    "utility on a thin pool.\n")

arg(replace_ARG, '\0', "replace", pv_VAL, ARG_GROUPABLE, 0,
    "Replace a specific PV in a raid LV with another PV.\n"
    "The new PV to use can be optionally specified after the LV.\n"
    "Multiple PVs can be replaced by repeating this option.\n")

arg(reportformat_ARG, '\0', "reportformat", reportformat_VAL, 0, 0,
    "Overrides current output format for reports which is defined globally by\n"
    "the report/output_format setting in lvm.conf.\n"
    "\\fBbasic\\fP is the original format with columns and rows.\n"
    "If there is more than one report per command, each report is prefixed\n"
    "with the report name for identification. \\fBjson\\fP produces report\n"
    "output in JSON format.\n")

arg(restorefile_ARG, '\0', "restorefile", string_VAL, 0, 0,
    "In conjunction with --uuid, this reads the file (produced by\n"
    "vgcfgbackup), extracts the location and size of the data on the PV,\n"
    "and ensures that the metadata produced by the program is consistent\n"
    "with the contents of the file, i.e. the physical extents will be in\n"
    "the same place and not be overwritten by new metadata. This provides\n"
    "a mechanism to upgrade the metadata format or to add/remove metadata\n"
    "areas. Use with care.\n")

arg(restoremissing_ARG, '\0', "restoremissing", 0, 0, 0,
    "Add a PV back into a VG after the PV was missing and then returned,\n"
    "e.g. due to a transient failure. The PV is not reinitialized.\n")

arg(resync_ARG, '\0', "resync", 0, 0, 0,
    "Initiates mirror synchronization. Synchronization generally happens\n"
    "automatically, but this option forces it to run.\n"
    "Also see --rebuild to synchronize a specific PV.\n"
    "During synchronization, data is read from the primary mirror device\n"
    "and copied to the others. This can take considerable time, during\n"
    "which the LV is without a complete redundant copy of the data.\n")

arg(rows_ARG, '\0', "rows", 0, 0, 0,
    "Output columns as rows.\n")

arg(segments_ARG, '\0', "segments", 0, 0, 0,
    "#pvs\n"
    "Produces one line of output for each contiguous allocation of space on each\n"
    "PV, showing the start (pvseg_start) and length (pvseg_size) in units of\n"
    "physical extents.\n"
    "#lvs\n"
    "Use default columns that emphasize segment information.\n")

arg(separator_ARG, '\0', "separator", string_VAL, 0, 0,
    "String to use to separate each column. Useful if grepping the output.\n")

arg(shared_ARG, '\0', "shared", 0, 0, 0,
    "Report/display shared VGs that would otherwise be skipped because\n"
    "lvmlockd is not being used on the host.\n"
    "See lvmlockd(8) for more information about shared VGs.\n")

arg(sinceversion_ARG, '\0', "sinceversion", string_VAL, 0, 0,
    "Specify an LVM version in x.y.z format where x is the major version,\n"
    "the y is the minor version and z is the patchlevel (e.g. 2.2.106).\n"
    "This option is currently applicable only with --type new\n"
    "to display all configuration settings introduced since given version.\n")

/* Not used */
arg(split_ARG, '\0', "split", 0, 0, 0, NULL)

arg(splitcache_ARG, '\0', "splitcache", 0, 0, 0,
    "Separates a cache pool from a cache LV, and keeps the unused cache pool LV.\n"
    "Before the separation, the cache is flushed. Also see --uncache.\n")

arg(splitmirrors_ARG, '\0', "splitmirrors", number_VAL, 0, 0,
    "Splits the specified number of images from a raid1 or mirror LV\n"
    "and uses them to create a new LV. If --trackchanges is also specified,\n"
    "changes to the raid1 LV are tracked while the split LV remains detached.\n")

arg(splitsnapshot_ARG, '\0', "splitsnapshot", 0, 0, 0,
    "Separates a COW snapshot from its origin LV. The LV that is split off\n"
    "contains the chunks that differ from the origin LV along with metadata\n"
    "describing them. This LV can be wiped and then destroyed with lvremove.\n")

arg(showdeprecated_ARG, '\0', "showdeprecated", 0, 0, 0,
    "Include deprecated configuration settings in the output. These settings\n"
    "are deprecated after a certain version. If a concrete version is specified\n"
    "with --atversion, deprecated settings are automatically included\n"
    "if the specified version is lower than the version in which the settings were\n"
    "deprecated. The current and diff types include deprecated settings\n"
    "in their output by default, all the other types ignore deprecated settings.\n")

arg(showunsupported_ARG, '\0', "showunsupported", 0, 0, 0,
    "Include unsupported configuration settings in the output. These settings\n"
    "are either used for debugging or development purposes only, or their support\n"
    "is not yet complete and they are not meant to be used in production. The\n"
    "current and diff types include unsupported settings in their\n"
    "output by default, all the other types ignore unsupported settings.\n")

arg(startpoll_ARG, '\0', "startpoll", 0, 0, 0,
    "Start polling an LV to continue processing a conversion.\n")

arg(stripes_long_ARG, '\0', "stripes", number_VAL, 0, 0,
    "Specifies the number of stripes in a striped LV. This is the number of\n"
    "PVs (devices) that a striped LV is spread across. Data that\n"
    "appears sequential in the LV is spread across multiple devices in units of\n"
    "the stripe size (see --stripesize). This does not apply to\n"
    "existing allocated space, only newly allocated space can be striped.\n")

arg(swapmetadata_ARG, '\0', "swapmetadata", 0, 0, 0,
    "Remove the metadata LV in a pool and replace it with another specified LV.\n"
    "The removed LV is preserved and given the name of the LV that replaced it.\n"
    "Used for repair only.\n")

arg(syncaction_ARG, '\0', "syncaction", syncaction_VAL, 0, 0,
    "Initiate different types of RAID synchronization.\n"
    "This causes the RAID LV to read all data and parity\n"
    "blocks in the array and check for discrepancies\n"
    "(mismatches between mirrors or incorrect parity values).\n"
    "\\fBcheck\\fP will count but not correct discrepancies.\n"
    "\\fBrepair\\fP will correct discrepancies.\n"
    "See lvs for reporting discrepancies found or repaired.\n")
    
arg(sysinit_ARG, '\0', "sysinit", 0, 0, 0,
    "Indicates that vgchange/lvchange is being invoked from early system initialisation\n"
    "scripts (e.g. rc.sysinit or an initrd), before writable filesystems are\n"
    "available. As such, some functionality needs to be disabled and this option\n"
    "acts as a shortcut which selects an appropriate set of options. Currently,\n"
    "this is equivalent to using --ignorelockingfailure, --ignoremonitoring,\n"
    "--poll n, and setting env var LVM_SUPPRESS_LOCKING_FAILURE_MESSAGES.\n"
    "When used in conjunction with lvmetad enabled and running,\n"
    "vgchange/lvchange skip autoactivation, and defer to pvscan autoactivation.\n")

arg(systemid_ARG, '\0', "systemid", string_VAL, 0, 0,
    "#vgcreate\n"
    "Specifies the system ID that will be given to the new VG, overriding the\n"
    "system ID of the host running the command. A VG is normally created\n"
    "without this option, in which case the new VG is given the system ID of\n"
    "the host creating it. Using this option requires caution because the\n"
    "system ID of the new VG may not match the system ID of the host running\n"
    "the command, leaving the VG inaccessible to the host.\n"
    "See lvmsystemid(7) for more information.\n"
    "#vgchange\n"
    "Changes the system ID of the VG.  Using this option requires caution\n"
    "because the VG may become foreign to the host running the command,\n"
    "leaving the host unable to access it.\n"
    "See lvmsystemid(7) for more information.\n")

arg(thinpool_ARG, '\0', "thinpool", lv_VAL, 0, 0,
    "The name of a thin pool LV.\n")

arg(trackchanges_ARG, '\0', "trackchanges", 0, 0, 0,
    "Can be used with --splitmirrors on a raid1 LV. This causes\n"
    "changes to the original raid1 LV to be tracked while the split images\n"
    "remain detached. This allows the read-only detached image(s) to be\n"
    "merged efficiently back into the raid1 LV later. Only the regions with\n"
    "changed data are resynchronized during merge. (This option only applies\n"
    "when using the raid1 LV type.)\n")

/* FIXME: hide this? */
arg(trustcache_ARG, '\0', "trustcache", 0, 0, 0,
    "Avoids certain device scanning during command processing. Do not use.\n")

arg(type_ARG, '\0', "type", segtype_VAL, 0, 0,
    "Specifies an LV type, or \"segment type\".\n")

arg(unbuffered_ARG, '\0', "unbuffered", 0, 0, 0,
    "Produce output immediately without sorting or aligning the columns properly.\n")

arg(uncache_ARG, '\0', "uncache", 0, 0, 0,
    "Separates a cache pool from a cache LV, and deletes the unused cache pool LV.\n"
    "Before the separation, the cache is flushed. Also see --splitcache.\n")

arg(cachepolicy_ARG, '\0', "cachepolicy", string_VAL, 0, 0,
    "Specifies the cache policy for a cache LV.\n"
    "See lvmcache(7) for more information.\n")

arg(cachesettings_ARG, '\0', "cachesettings", string_VAL, ARG_GROUPABLE, 0,
    "Specifies tunable values for a cache LV in \"Key = Value\" form.\n"
    "Repeat this option to specify multiple values.\n"
    "(The default values should usually be adequate.)\n"
    "The special string value \\fBdefault\\fP switches\n"
    "settings back to their default kernel values and removes\n"
    "them from the list of settings stored in LVM metadata.\n"
    "See lvmcache(7) for more information.\n")

arg(unconfigured_ARG, '\0', "unconfigured", 0, 0, 0,
    "Internal option used for generating config file during build.\n")

arg(units_ARG, '\0', "units", units_VAL, 0, 0,
    "All sizes are output in these units: (h)uman-readable, (b)ytes, (s)ectors,\n"
    "(k)ilobytes, (m)egabytes, (g)igabytes, (t)erabytes, (p)etabytes, (e)xabytes.\n"
    "Capitalise to use multiples of 1000 (S.I.) instead of 1024. Can also specify\n"
    "custom units e.g. --units 3M.\n")

arg(unquoted_ARG, '\0', "unquoted", 0, 0, 0,
    "When used with --nameprefixes, output values in the field=value\n"
    "pairs are not quoted.\n")

arg(usepolicies_ARG, '\0', "usepolicies", 0, 0, 0,
    "Perform an operation according to the policy configured in lvm.conf.\n"
    "or a profile.\n")

arg(validate_ARG, '\0', "validate", 0, 0, 0,
    "Validate current configuration used and exit with appropriate\n"
    "return code. The validation is done only for the configuration\n"
    "at the front of the \"config cascade\". To validate the whole\n"
    "merged configuration tree, also use --mergedconfig.\n"
    "The validation is done even if lvm.conf config/checks is disabled.\n")

arg(version_ARG, '\0', "version", 0, 0, 0,
    "Display version information.\n")

arg(vgmetadatacopies_ARG, '\0', "vgmetadatacopies", vgmetadatacopies_VAL, 0, 0,
    "Number of copies of the VG metadata that are kept.\n"
    "VG metadata is kept in VG metadata areas on PVs in the VG,\n"
    "i.e. reserved space at the start and/or end of the PVs.\n"
    "Keeping a copy of the VG metadata on every PV can reduce performance\n"
    "in VGs containing a large number of PVs.\n"
    "When this number is set to a non-zero value, LVM will automatically\n"
    "choose PVs on which to store metadata, using the metadataignore flags\n"
    "on PVs to achieve the specified number.\n"
    "The number can also be replaced with special string values:\n"
    "\\fBunmanaged\\fP causes LVM to not automatically manage the PV\n"
    "metadataignore flags.\n"
    "\\fBall\\fP causes LVM to first clear the metadataignore flags on\n"
    "all PVs, and then to become unmanaged.\n")

arg(virtualoriginsize_ARG, '\0', "virtualoriginsize", sizemb_VAL, 0, 0,
    "An alias for --virtualsize.\n")

arg(withsummary_ARG, '\0', "withsummary", 0, 0, 0,
    "Display a one line comment for each configuration node.\n")

arg(withcomments_ARG, '\0', "withcomments", 0, 0, 0,
    "Display a full comment for each configuration node. For deprecated\n"
    "settings, also display comments about deprecation.\n")

arg(withspaces_ARG, '\0', "withspaces", 0, 0, 0,
    "Where appropriate, add more spaces in output for better readability.\n")

arg(withversions_ARG, '\0', "withversions", 0, 0, 0,
    "Also display a comment containing the version of introduction for\n"
    "each configuration node. If the setting is deprecated, also display\n"
    "the version since which it is deprecated.\n")

arg(writebehind_ARG, '\0', "writebehind", number_VAL, 0, 0,
    "The maximum number of outstanding writes that are allowed to\n"
    "devices in a RAID1 LV that is marked write-mostly.\n"
    "Once this value is exceeded, writes become synchronous (i.e. all writes\n"
    "to the constituent devices must complete before the array signals the\n"
    "write has completed). Setting the value to zero clears the preference\n"
    "and allows the system to choose the value arbitrarily.\n")

arg(writemostly_ARG, '\0', "writemostly", writemostly_VAL, ARG_GROUPABLE, 0,
    "Mark a device in a RAID1 LV as write-mostly.  All reads\n"
    "to these drives will be avoided unless absolutely necessary. This keeps\n"
    "the number of I/Os to the drive to a minimum. The default behavior is to\n"
    "set the write-mostly attribute for the specified PV.\n"
    "It is also possible to remove the write-mostly flag by adding the\n"
    "suffix \\fB:n\\fP at the end of the PV name, or to toggle the value with\n"
    "the suffix \\fB:t\\fP. Repeat this option to change the attribute on\n"
    "multiple PVs.\n")

/* Allow some variations */
arg(allocation_ARG, '\0', "allocation", bool_VAL, 0, 0, NULL)
arg(available_ARG, '\0', "available", activation_VAL, 0, 0, NULL)
arg(resizable_ARG, '\0', "resizable", bool_VAL, 0, 0, NULL)

/*
 * ... and now the short args.
 */
arg(activate_ARG, 'a', "activate", activation_VAL, 0, 0,
    "Change the availability of LVs.\n"
    "\\fBy\\fP makes LVs available on the system.\n"
    "\\fBn\\fP makes LVs unavailable on the system.\n"
    "Using device-mapper in the kernel, a block device for the LV\n"
    "is added or removed on the system corresponding to the activation change.\n"
    "When a block device exists for the LV, data on the LV can be accessed.\n"
    "A symbolic link /dev/VGName/LVName pointing\n"
    "to the device node is created or removed on an activation change.\n"
    "All software and scripts should access the device through the symbolic\n"
    "link and present this as the name of the device.\n"
    "The location and name of the underlying device node may depend on\n"
    "the distribution and configuration (e.g. udev) and might change\n"
    "from release to release.\n"
    "\\fBay\\fP specifies autoactivation, in which case an LV is activated\n"
    "only if it matches an item in lvm.conf activation/auto_activation_volume_list.\n"
    "If the list is not set, all LVs are considered to match.\n"
    "Autoactivation should be used during system boot to make it possible\n"
    "to select which LVs should be automatically activated by the system.\n"
    "See lvmlockd(8) for more information about activation modes related\n"
    "to shared VGs (\\fBey|sh\\fP).\n"
    "See clvmd(8) for more information about activation modes related\n"
    "to clustered VGs (\\fBey|sh|ly\\fP).\n")

arg(all_ARG, 'a', "all", 0, 0, 0, NULL)
arg(autobackup_ARG, 'A', "autobackup", bool_VAL, 0, 0, NULL)
arg(activevolumegroups_ARG, 'A', "activevolumegroups", 0, 0, 0, NULL)
arg(background_ARG, 'b', "background", 0, 0, 0, NULL)
arg(backgroundfork_ARG, 'b', "background", 0, 0, 0, NULL)
arg(basevgname_ARG, 'n', "basevgname", string_VAL, 0, 0, NULL)
arg(blockdevice_ARG, 'b', "blockdevice", 0, 0, 0, NULL)
arg(chunksize_ARG, 'c', "chunksize", sizekb_VAL, 0, 0, NULL)
arg(clustered_ARG, 'c', "clustered", bool_VAL, 0, 0, NULL)
arg(colon_ARG, 'c', "colon", 0, 0, 0, NULL)
arg(columns_ARG, 'C', "columns", 0, 0, 0, NULL)
arg(contiguous_ARG, 'C', "contiguous", bool_VAL, 0, 0, NULL)
arg(debug_ARG, 'd', "debug", 0, ARG_COUNTABLE, 0, NULL)
arg(exported_ARG, 'e', "exported", 0, 0, 0, NULL)
arg(physicalextent_ARG, 'E', "physicalextent", 0, 0, 0, NULL)
arg(file_ARG, 'f', "file", string_VAL, 0, 0, NULL)
arg(force_ARG, 'f', "force", 0, ARG_COUNTABLE, 0, NULL)
arg(full_ARG, 'f', "full", 0, 0, 0, NULL)
arg(help_ARG, 'h', "help", 0, ARG_COUNTABLE, 0, NULL)
arg(cache_ARG, 'H', "cache", 0, 0, 0, NULL)
arg(history_ARG, 'H', "history", 0, 0, 0, NULL)
arg(help2_ARG, '?', "", 0, 0, 0, NULL)
arg(import_ARG, 'i', "import", 0, 0, 0, NULL)
arg(interval_ARG, 'i', "interval", number_VAL, 0, 0, NULL)
arg(iop_version_ARG, 'i', "iop_version", 0, 0, 0, NULL)
arg(stripes_ARG, 'i', "stripes", number_VAL, 0, 0, NULL)
arg(stripesize_ARG, 'I', "stripesize", sizekb_VAL, 0, 0, NULL)
arg(logicalvolume_ARG, 'l', "logicalvolume", number_VAL, 0, 0, NULL)
arg(maxlogicalvolumes_ARG, 'l', "maxlogicalvolumes", number_VAL, 0, 0, NULL)
arg(extents_ARG, 'l', "extents", numsignedper_VAL, 0, 0, NULL)
arg(list_ARG, 'l', "list", 0, 0, 0, NULL)
arg(lvmpartition_ARG, 'l', "lvmpartition", 0, 0, 0, NULL)
arg(size_ARG, 'L', "size", sizemb_VAL, 0, 0, NULL)
arg(persistent_ARG, 'M', "persistent", bool_VAL, 0, 0, NULL)
arg(major_ARG, 'j', "major", number_VAL, ARG_GROUPABLE, 0, NULL)
arg(setactivationskip_ARG, 'k', "setactivationskip", bool_VAL, 0, 0, NULL)
arg(ignoreactivationskip_ARG, 'K', "ignoreactivationskip", 0, 0, 0, NULL)
arg(maps_ARG, 'm', "maps", 0, 0, 0, NULL)
arg(mirrors_ARG, 'm', "mirrors", numsigned_VAL, 0, 0, NULL)
arg(metadatatype_ARG, 'M', "metadatatype", metadatatype_VAL, 0, 0, NULL)
arg(name_ARG, 'n', "name", string_VAL, 0, 0, NULL)
arg(nofsck_ARG, 'n', "nofsck", 0, 0, 0, NULL)
arg(novolumegroup_ARG, 'n', "novolumegroup", 0, 0, 0, NULL)
arg(oldpath_ARG, 'n', "oldpath", 0, 0, 0, NULL)
arg(options_ARG, 'o', "options", string_VAL, ARG_GROUPABLE, 0, NULL)
arg(sort_ARG, 'O', "sort", string_VAL, ARG_GROUPABLE, 0, NULL)
arg(maxphysicalvolumes_ARG, 'p', "maxphysicalvolumes", uint32_VAL, 0, 0, NULL)
arg(permission_ARG, 'p', "permission", permission_VAL, 0, 0, NULL)
arg(partial_ARG, 'P', "partial", 0, 0, 0, NULL)
arg(physicalvolume_ARG, 'P', "physicalvolume", 0, 0, 0, NULL)
arg(quiet_ARG, 'q', "quiet", 0, ARG_COUNTABLE, 0, NULL)
arg(readahead_ARG, 'r', "readahead", readahead_VAL, 0, 0, NULL)
arg(resizefs_ARG, 'r', "resizefs", 0, 0, 0, NULL)
arg(reset_ARG, 'R', "reset", 0, 0, 0, NULL)
arg(regionsize_ARG, 'R', "regionsize", sizemb_VAL, 0, 0, NULL)
arg(physicalextentsize_ARG, 's', "physicalextentsize", sizemb_VAL, 0, 0, NULL)
arg(snapshot_ARG, 's', "snapshot", 0, 0, 0, NULL)
arg(short_ARG, 's', "short", 0, 0, 0, NULL)
arg(stdin_ARG, 's', "stdin", 0, 0, 0, NULL)
arg(select_ARG, 'S', "select", string_VAL, ARG_GROUPABLE, 0, NULL)
arg(test_ARG, 't', "test", 0, 0, 0, NULL)
arg(thin_ARG, 'T', "thin", 0, 0, 0, NULL)
arg(uuid_ARG, 'u', "uuid", 0, 0, 0, NULL)
arg(uuidstr_ARG, 'u', "uuid", string_VAL, 0, 0, NULL)
arg(uuidlist_ARG, 'U', "uuidlist", 0, 0, 0, NULL)
arg(verbose_ARG, 'v', "verbose", 0, ARG_COUNTABLE, 0, NULL)
arg(volumegroup_ARG, 'V', "volumegroup", 0, 0, 0, NULL)
arg(virtualsize_ARG, 'V', "virtualsize", sizemb_VAL, 0, 0, NULL)
arg(wipesignatures_ARG, 'W', "wipesignatures", bool_VAL, 0, 0, NULL)
arg(allocatable_ARG, 'x', "allocatable", bool_VAL, 0, 0, NULL)
arg(resizeable_ARG, 'x', "resizeable", bool_VAL, 0, 0, NULL)
arg(yes_ARG, 'y', "yes", 0, 0, 0, NULL)
arg(zero_ARG, 'Z', "zero", bool_VAL, 0, 0, NULL)

/* this should always be last */
arg(ARG_COUNT, '-', "", 0, 0, 0, NULL)
/* *INDENT-ON* */
