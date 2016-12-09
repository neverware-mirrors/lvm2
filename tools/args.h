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
arg(ARG_UNUSED, '-', "", 0, 0, 0)  /* place holder for unused 0 value */

arg(abort_ARG, '\0', "abort", 0, 0, 0)
arg(activationmode_ARG, '\0', "activationmode", activationmode_VAL, 0, 0)
arg(addtag_ARG, '\0', "addtag", tag_VAL, ARG_GROUPABLE, 0)
arg(aligned_ARG, '\0', "aligned", 0, 0, 0)
arg(alloc_ARG, '\0', "alloc", alloc_VAL, 0, 0)
arg(atomic_ARG, '\0', "atomic", 0, 0, 0)
arg(atversion_ARG, '\0', "atversion", string_VAL, 0, 0)
arg(binary_ARG, '\0', "binary", 0, 0, 0)
arg(bootloaderareasize_ARG, '\0', "bootloaderareasize", sizemb_VAL, 0, 0)
arg(cache_long_ARG, '\0', "cache", 0, 0, 0)
arg(cachemode_ARG, '\0', "cachemode", cachemode_VAL, 0, 0)
arg(cachepool_ARG, '\0', "cachepool", lv_VAL, 0, 0)
arg(commandprofile_ARG, '\0', "commandprofile", string_VAL, 0, 0)
arg(config_ARG, '\0', "config", string_VAL, 0, 0)
arg(configreport_ARG, '\0', "configreport", configreport_VAL, ARG_GROUPABLE, 1)
arg(configtype_ARG, '\0', "typeconfig", configtype_VAL, 0, 0)
arg(corelog_ARG, '\0', "corelog", 0, 0, 0)
arg(dataalignment_ARG, '\0', "dataalignment", sizekb_VAL, 0, 0)
arg(dataalignmentoffset_ARG, '\0', "dataalignmentoffset", sizekb_VAL, 0, 0)
arg(deltag_ARG, '\0', "deltag", tag_VAL, ARG_GROUPABLE, 0)
arg(detachprofile_ARG, '\0', "detachprofile", 0, 0, 0)
arg(discards_ARG, '\0', "discards", discards_VAL, 0, 0)
arg(driverloaded_ARG, '\0', "driverloaded", bool_VAL, 0, 0)
arg(errorwhenfull_ARG, '\0', "errorwhenfull", bool_VAL, 0, 0)
arg(force_long_ARG, '\0', "force", 0, ARG_COUNTABLE, 0)
arg(foreign_ARG, '\0', "foreign", 0, 0, 0)
arg(handlemissingpvs_ARG, '\0', "handlemissingpvs", 0, 0, 0)
arg(ignoreadvanced_ARG, '\0', "ignoreadvanced", 0, 0, 0)
arg(ignorelocal_ARG, '\0', "ignorelocal", 0, 0, 0)
arg(ignorelockingfailure_ARG, '\0', "ignorelockingfailure", 0, 0, 0)
arg(ignoremonitoring_ARG, '\0', "ignoremonitoring", 0, 0, 0)
arg(ignoreskippedcluster_ARG, '\0', "ignoreskippedcluster", 0, 0, 0)
arg(ignoreunsupported_ARG, '\0', "ignoreunsupported", 0, 0, 0)
arg(labelsector_ARG, '\0', "labelsector", number_VAL, 0, 0)
arg(lockopt_ARG, '\0', "lockopt", string_VAL, 0, 0)
arg(lockstart_ARG, '\0', "lockstart", 0, 0, 0)
arg(lockstop_ARG, '\0', "lockstop", 0, 0, 0)
arg(locktype_ARG, '\0', "locktype", locktype_VAL, 0, 0)
arg(logonly_ARG, '\0', "logonly", 0, 0, 0)
arg(maxrecoveryrate_ARG, '\0', "maxrecoveryrate", sizekb_VAL, 0, 0)
arg(merge_ARG, '\0', "merge", 0, 0, 0)
arg(mergemirrors_ARG, '\0', "mergemirrors", 0, 0, 0)
arg(mergesnapshot_ARG, '\0', "mergesnapshot", 0, 0, 0)
arg(mergethin_ARG, '\0', "mergethin", 0, 0, 0)
arg(mergedconfig_ARG, '\0', "mergedconfig", 0, 0, 0)
arg(metadatacopies_ARG, '\0', "metadatacopies", metadatacopies_VAL, 0, 0)
arg(metadataignore_ARG, '\0', "metadataignore", bool_VAL, 0, 0)
arg(metadataprofile_ARG, '\0', "metadataprofile", string_VAL, 0, 0)
arg(metadatasize_ARG, '\0', "metadatasize", sizemb_VAL, 0, 0)
arg(minor_ARG, '\0', "minor", number_VAL, ARG_GROUPABLE, 0)
arg(minrecoveryrate_ARG, '\0', "minrecoveryrate", sizekb_VAL, 0, 0)
arg(mirrorlog_ARG, '\0', "mirrorlog", mirrorlog_VAL, 0, 0)
arg(mirrorsonly_ARG, '\0', "mirrorsonly", 0, 0, 0)
arg(mknodes_ARG, '\0', "mknodes", 0, 0, 0)
arg(monitor_ARG, '\0', "monitor", bool_VAL, 0, 0)
arg(nameprefixes_ARG, '\0', "nameprefixes", 0, 0, 0)
arg(noheadings_ARG, '\0', "noheadings", 0, 0, 0)
arg(nohistory_ARG, '\0', "nohistory", 0, 0, 0)
arg(nolocking_ARG, '\0', "nolocking", 0, 0, 0)
arg(norestorefile_ARG, '\0', "norestorefile", 0, 0, 0)
arg(nosuffix_ARG, '\0', "nosuffix", 0, 0, 0)
arg(nosync_ARG, '\0', "nosync", 0, 0, 0)
arg(notifydbus_ARG, '\0', "notifydbus", 0, 0, 0)
arg(noudevsync_ARG, '\0', "noudevsync", 0, 0, 0)
arg(originname_ARG, '\0', "originname", lv_VAL, 0, 0)
arg(physicalvolumesize_ARG, '\0', "setphysicalvolumesize", sizemb_VAL, 0, 0)
arg(poll_ARG, '\0', "poll", bool_VAL, 0, 0)
arg(polloperation_ARG, '\0', "polloperation", polloperation_VAL, 0, 0)
arg(pooldatasize_ARG, '\0', "pooldatasize", sizemb_VAL, 0, 0)
arg(poolmetadata_ARG, '\0', "poolmetadata", lv_VAL, 0, 0)
arg(poolmetadatasize_ARG, '\0', "poolmetadatasize", sizemb_VAL, 0, 0)
arg(poolmetadataspare_ARG, '\0', "poolmetadataspare", bool_VAL, 0, 0)
arg(profile_ARG, '\0', "profile", string_VAL, 0, 0)
arg(pvmetadatacopies_ARG, '\0', "pvmetadatacopies", pvmetadatacopies_VAL, 0, 0)
arg(raidrebuild_ARG, '\0', "raidrebuild", pv_VAL, ARG_GROUPABLE, 0)
arg(raidmaxrecoveryrate_ARG, '\0', "raidmaxrecoveryrate", sizekb_VAL, 0, 0)
arg(raidminrecoveryrate_ARG, '\0', "raidminrecoveryrate", sizekb_VAL, 0, 0)
arg(raidsyncaction_ARG, '\0', "raidsyncaction", syncaction_VAL, 0, 0)
arg(raidwritebehind_ARG, '\0', "raidwritebehind", number_VAL, 0, 0)
arg(raidwritemostly_ARG, '\0', "raidwritemostly", writemostly_VAL, ARG_GROUPABLE, 0)
arg(readonly_ARG, '\0', "readonly", 0, 0, 0)
arg(refresh_ARG, '\0', "refresh", 0, 0, 0)
arg(removemissing_ARG, '\0', "removemissing", 0, 0, 0)
arg(rebuild_ARG, '\0', "rebuild", pv_VAL, ARG_GROUPABLE, 0)
arg(repair_ARG, '\0', "repair", 0, 0, 0)
arg(replace_ARG, '\0', "replace", pv_VAL, ARG_GROUPABLE, 0)
arg(reportformat_ARG, '\0', "reportformat", reportformat_VAL, 0, 0)
arg(restorefile_ARG, '\0', "restorefile", string_VAL, 0, 0)
arg(restoremissing_ARG, '\0', "restoremissing", 0, 0, 0)
arg(resync_ARG, '\0', "resync", 0, 0, 0)
arg(rows_ARG, '\0', "rows", 0, 0, 0)
arg(segments_ARG, '\0', "segments", 0, 0, 0)
arg(separator_ARG, '\0', "separator", string_VAL, 0, 0)
arg(shared_ARG, '\0', "shared", 0, 0, 0)
arg(sinceversion_ARG, '\0', "sinceversion", string_VAL, 0, 0)
arg(split_ARG, '\0', "split", 0, 0, 0)
arg(splitcache_ARG, '\0', "splitcache", 0, 0, 0)
arg(splitmirrors_ARG, '\0', "splitmirrors", number_VAL, 0, 0)
arg(splitsnapshot_ARG, '\0', "splitsnapshot", 0, 0, 0)
arg(showdeprecated_ARG, '\0', "showdeprecated", 0, 0, 0)
arg(showunsupported_ARG, '\0', "showunsupported", 0, 0, 0)
arg(startpoll_ARG, '\0', "startpoll", 0, 0, 0)
arg(stripes_long_ARG, '\0', "stripes", number_VAL, 0, 0)
arg(swapmetadata_ARG, '\0', "swapmetadata", 0, 0, 0)
arg(syncaction_ARG, '\0', "syncaction", syncaction_VAL, 0, 0)
arg(sysinit_ARG, '\0', "sysinit", 0, 0, 0)
arg(systemid_ARG, '\0', "systemid", string_VAL, 0, 0)
arg(thinpool_ARG, '\0', "thinpool", lv_VAL, 0, 0)
arg(trackchanges_ARG, '\0', "trackchanges", 0, 0, 0)
arg(trustcache_ARG, '\0', "trustcache", 0, 0, 0)
arg(type_ARG, '\0', "type", segtype_VAL, 0, 0)
arg(unbuffered_ARG, '\0', "unbuffered", 0, 0, 0)
arg(uncache_ARG, '\0', "uncache", 0, 0, 0)
arg(cachepolicy_ARG, '\0', "cachepolicy", string_VAL, 0, 0)
arg(cachesettings_ARG, '\0', "cachesettings", string_VAL, ARG_GROUPABLE, 0)
arg(unconfigured_ARG, '\0', "unconfigured", 0, 0, 0)
arg(units_ARG, '\0', "units", units_VAL, 0, 0)
arg(unquoted_ARG, '\0', "unquoted", 0, 0, 0)
arg(usepolicies_ARG, '\0', "usepolicies", 0, 0, 0)
arg(validate_ARG, '\0', "validate", 0, 0, 0)
arg(version_ARG, '\0', "version", 0, 0, 0)
arg(vgmetadatacopies_ARG, '\0', "vgmetadatacopies", vgmetadatacopies_VAL, 0, 0)
arg(virtualoriginsize_ARG, '\0', "virtualoriginsize", sizemb_VAL, 0, 0)
arg(withsummary_ARG, '\0', "withsummary", 0, 0, 0)
arg(withcomments_ARG, '\0', "withcomments", 0, 0, 0)
arg(withspaces_ARG, '\0', "withspaces", 0, 0, 0)
arg(withversions_ARG, '\0', "withversions", 0, 0, 0)
arg(writebehind_ARG, '\0', "writebehind", number_VAL, 0, 0)
arg(writemostly_ARG, '\0', "writemostly", writemostly_VAL, ARG_GROUPABLE, 0)

/* Allow some variations */
arg(allocation_ARG, '\0', "allocation", bool_VAL, 0, 0)
arg(available_ARG, '\0', "available", activation_VAL, 0, 0)
arg(resizable_ARG, '\0', "resizable", bool_VAL, 0, 0)

/*
 * ... and now the short args.
 */
arg(activate_ARG, 'a', "activate", activation_VAL, 0, 0)
arg(all_ARG, 'a', "all", 0, 0, 0)
arg(autobackup_ARG, 'A', "autobackup", bool_VAL, 0, 0)
arg(activevolumegroups_ARG, 'A', "activevolumegroups", 0, 0, 0)
arg(background_ARG, 'b', "background", 0, 0, 0)
arg(backgroundfork_ARG, 'b', "background", 0, 0, 0)
arg(basevgname_ARG, 'n', "basevgname", string_VAL, 0, 0)
arg(blockdevice_ARG, 'b', "blockdevice", 0, 0, 0)
arg(chunksize_ARG, 'c', "chunksize", sizekb_VAL, 0, 0)
arg(clustered_ARG, 'c', "clustered", bool_VAL, 0, 0)
arg(colon_ARG, 'c', "colon", 0, 0, 0)
arg(columns_ARG, 'C', "columns", 0, 0, 0)
arg(contiguous_ARG, 'C', "contiguous", bool_VAL, 0, 0)
arg(debug_ARG, 'd', "debug", 0, ARG_COUNTABLE, 0)
arg(exported_ARG, 'e', "exported", 0, 0, 0)
arg(physicalextent_ARG, 'E', "physicalextent", 0, 0, 0)
arg(file_ARG, 'f', "file", string_VAL, 0, 0)
arg(force_ARG, 'f', "force", 0, ARG_COUNTABLE, 0)
arg(full_ARG, 'f', "full", 0, 0, 0)
arg(help_ARG, 'h', "help", 0, ARG_COUNTABLE, 0)
arg(cache_ARG, 'H', "cache", 0, 0, 0)
arg(history_ARG, 'H', "history", 0, 0, 0)
arg(help2_ARG, '?', "", 0, 0, 0)
arg(import_ARG, 'i', "import", 0, 0, 0)
arg(interval_ARG, 'i', "interval", number_VAL, 0, 0)
arg(iop_version_ARG, 'i', "iop_version", 0, 0, 0)
arg(stripes_ARG, 'i', "stripes", number_VAL, 0, 0)
arg(stripesize_ARG, 'I', "stripesize", sizekb_VAL, 0, 0)
arg(logicalvolume_ARG, 'l', "logicalvolume", number_VAL, 0, 0)
arg(maxlogicalvolumes_ARG, 'l', "maxlogicalvolumes", number_VAL, 0, 0)
arg(extents_ARG, 'l', "extents", numsignedper_VAL, 0, 0)
arg(list_ARG, 'l', "list", 0, 0, 0)
arg(lvmpartition_ARG, 'l', "lvmpartition", 0, 0, 0)
arg(size_ARG, 'L', "size", sizemb_VAL, 0, 0)
arg(persistent_ARG, 'M', "persistent", bool_VAL, 0, 0)
arg(major_ARG, 'j', "major", number_VAL, ARG_GROUPABLE, 0)
arg(setactivationskip_ARG, 'k', "setactivationskip", bool_VAL, 0, 0)
arg(ignoreactivationskip_ARG, 'K', "ignoreactivationskip", 0, 0, 0)
arg(maps_ARG, 'm', "maps", 0, 0, 0)
arg(mirrors_ARG, 'm', "mirrors", numsigned_VAL, 0, 0)
arg(metadatatype_ARG, 'M', "metadatatype", metadatatype_VAL, 0, 0)
arg(name_ARG, 'n', "name", string_VAL, 0, 0)
arg(nofsck_ARG, 'n', "nofsck", 0, 0, 0)
arg(novolumegroup_ARG, 'n', "novolumegroup", 0, 0, 0)
arg(oldpath_ARG, 'n', "oldpath", 0, 0, 0)
arg(options_ARG, 'o', "options", string_VAL, ARG_GROUPABLE, 0)
arg(sort_ARG, 'O', "sort", string_VAL, ARG_GROUPABLE, 0)
arg(maxphysicalvolumes_ARG, 'p', "maxphysicalvolumes", number_VAL, 0, 0)
arg(permission_ARG, 'p', "permission", permission_VAL, 0, 0)
arg(partial_ARG, 'P', "partial", 0, 0, 0)
arg(physicalvolume_ARG, 'P', "physicalvolume", 0, 0, 0)
arg(quiet_ARG, 'q', "quiet", 0, ARG_COUNTABLE, 0)
arg(readahead_ARG, 'r', "readahead", readahead_VAL, 0, 0)
arg(resizefs_ARG, 'r', "resizefs", 0, 0, 0)
arg(reset_ARG, 'R', "reset", 0, 0, 0)
arg(regionsize_ARG, 'R', "regionsize", sizemb_VAL, 0, 0)
arg(physicalextentsize_ARG, 's', "physicalextentsize", sizemb_VAL, 0, 0)
arg(snapshot_ARG, 's', "snapshot", 0, 0, 0)
arg(short_ARG, 's', "short", 0, 0, 0)
arg(stdin_ARG, 's', "stdin", 0, 0, 0)
arg(select_ARG, 'S', "select", string_VAL, ARG_GROUPABLE, 0)
arg(test_ARG, 't', "test", 0, 0, 0)
arg(thin_ARG, 'T', "thin", 0, 0, 0)
arg(uuid_ARG, 'u', "uuid", 0, 0, 0)
arg(uuidstr_ARG, 'u', "uuid", string_VAL, 0, 0)
arg(uuidlist_ARG, 'U', "uuidlist", 0, 0, 0)
arg(verbose_ARG, 'v', "verbose", 0, ARG_COUNTABLE, 0)
arg(volumegroup_ARG, 'V', "volumegroup", 0, 0, 0)
arg(virtualsize_ARG, 'V', "virtualsize", sizemb_VAL, 0, 0)
arg(wipesignatures_ARG, 'W', "wipesignatures", bool_VAL, 0, 0)
arg(allocatable_ARG, 'x', "allocatable", bool_VAL, 0, 0)
arg(resizeable_ARG, 'x', "resizeable", bool_VAL, 0, 0)
arg(yes_ARG, 'y', "yes", 0, 0, 0)
arg(zero_ARG, 'Z', "zero", bool_VAL, 0, 0)

/* this should always be last */
arg(ARG_COUNT, '-', "", 0, 0, 0)
/* *INDENT-ON* */
