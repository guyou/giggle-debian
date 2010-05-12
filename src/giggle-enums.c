
/* Generated data (by glib-mkenums) */

#include "giggle-enums.h"
/* enumerations from "giggle-remote-branch.h" */
#include "giggle-remote-branch.h"
GType
giggle_remote_direction_get_type(void) {
	static GType etype = 0;
	if(!etype) {
		static const GEnumValue values[] = {
			{GIGGLE_REMOTE_DIRECTION_PUSH, "GIGGLE_REMOTE_DIRECTION_PUSH", "push"},
			{GIGGLE_REMOTE_DIRECTION_PULL, "GIGGLE_REMOTE_DIRECTION_PULL", "pull"},
			{0, NULL, NULL}
		};

		etype = g_enum_register_static("GiggleRemoteDirection", values);
	}
	
	return etype;
}
/* enumerations from "giggle-git-list-files.h" */
#include "giggle-git-list-files.h"
GType
giggle_git_list_files_status_get_type(void) {
	static GType etype = 0;
	if(!etype) {
		static const GEnumValue values[] = {
			{GIGGLE_GIT_FILE_STATUS_OTHER, "GIGGLE_GIT_FILE_STATUS_OTHER", "other"},
			{GIGGLE_GIT_FILE_STATUS_CACHED, "GIGGLE_GIT_FILE_STATUS_CACHED", "cached"},
			{GIGGLE_GIT_FILE_STATUS_UNMERGED, "GIGGLE_GIT_FILE_STATUS_UNMERGED", "unmerged"},
			{GIGGLE_GIT_FILE_STATUS_DELETED, "GIGGLE_GIT_FILE_STATUS_DELETED", "deleted"},
			{GIGGLE_GIT_FILE_STATUS_CHANGED, "GIGGLE_GIT_FILE_STATUS_CHANGED", "changed"},
			{GIGGLE_GIT_FILE_STATUS_KILLED, "GIGGLE_GIT_FILE_STATUS_KILLED", "killed"},
			{0, NULL, NULL}
		};

		etype = g_enum_register_static("GiggleGitListFilesStatus", values);
	}
	
	return etype;
}

/* Generated data ends here */

