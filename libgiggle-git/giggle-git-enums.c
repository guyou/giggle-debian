
/* Generated data (by glib-mkenums) */

#include "giggle-git-enums.h"
/* enumerations from "giggle-git-config.h" */
#include "giggle-git-config.h"
GType
giggle_git_config_field_get_type(void) {
	static GType etype = 0;
	if(!etype) {
		static const GEnumValue values[] = {
			{GIGGLE_GIT_CONFIG_FIELD_NAME, "GIGGLE_GIT_CONFIG_FIELD_NAME", "name"},
			{GIGGLE_GIT_CONFIG_FIELD_EMAIL, "GIGGLE_GIT_CONFIG_FIELD_EMAIL", "email"},
			{GIGGLE_GIT_CONFIG_FIELD_MAIN_WINDOW_MAXIMIZED, "GIGGLE_GIT_CONFIG_FIELD_MAIN_WINDOW_MAXIMIZED", "main-window-maximized"},
			{GIGGLE_GIT_CONFIG_FIELD_MAIN_WINDOW_GEOMETRY, "GIGGLE_GIT_CONFIG_FIELD_MAIN_WINDOW_GEOMETRY", "main-window-geometry"},
			{GIGGLE_GIT_CONFIG_FIELD_MAIN_WINDOW_VIEW, "GIGGLE_GIT_CONFIG_FIELD_MAIN_WINDOW_VIEW", "main-window-view"},
			{GIGGLE_GIT_CONFIG_FIELD_SHOW_GRAPH, "GIGGLE_GIT_CONFIG_FIELD_SHOW_GRAPH", "show-graph"},
			{GIGGLE_GIT_CONFIG_FIELD_FILE_VIEW_PATH, "GIGGLE_GIT_CONFIG_FIELD_FILE_VIEW_PATH", "file-view-path"},
			{GIGGLE_GIT_CONFIG_FIELD_FILE_VIEW_HPANE_POSITION, "GIGGLE_GIT_CONFIG_FIELD_FILE_VIEW_HPANE_POSITION", "file-view-hpane-position"},
			{GIGGLE_GIT_CONFIG_FIELD_FILE_VIEW_VPANE_POSITION, "GIGGLE_GIT_CONFIG_FIELD_FILE_VIEW_VPANE_POSITION", "file-view-vpane-position"},
			{GIGGLE_GIT_CONFIG_FIELD_HISTORY_VIEW_VPANE_POSITION, "GIGGLE_GIT_CONFIG_FIELD_HISTORY_VIEW_VPANE_POSITION", "history-view-vpane-position"},
			{0, NULL, NULL}
		};

		etype = g_enum_register_static("GiggleGitConfigField", values);
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

