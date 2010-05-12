
/* Generated data (by glib-mkenums) */

#include "giggle-enums.h"
/* enumerations from "giggle-error.h" */
#include "giggle-error.h"
GType
giggle_error_get_type(void) {
	static GType etype = 0;
	if(!etype) {
		static const GEnumValue values[] = {
			{GIGGLE_ERROR_DISPATCH_COMMAND_NOT_FOUND, "GIGGLE_ERROR_DISPATCH_COMMAND_NOT_FOUND", "found"},
			{0, NULL, NULL}
		};

		etype = g_enum_register_static("GiggleError", values);
	}
	
	return etype;
}
/* enumerations from "giggle-plugin.h" */
#include "giggle-plugin.h"
GType
giggle_plugin_error_get_type(void) {
	static GType etype = 0;
	if(!etype) {
		static const GEnumValue values[] = {
			{GIGGLE_PLUGIN_ERROR_NONE, "GIGGLE_PLUGIN_ERROR_NONE", "none"},
			{GIGGLE_PLUGIN_ERROR_MALFORMED, "GIGGLE_PLUGIN_ERROR_MALFORMED", "malformed"},
			{0, NULL, NULL}
		};

		etype = g_enum_register_static("GigglePluginError", values);
	}
	
	return etype;
}
/* enumerations from "giggle-remote.h" */
#include "giggle-remote.h"
GType
giggle_remote_mechanism_get_type(void) {
	static GType etype = 0;
	if(!etype) {
		static const GEnumValue values[] = {
			{GIGGLE_REMOTE_MECHANISM_GIT, "GIGGLE_REMOTE_MECHANISM_GIT", "git"},
			{GIGGLE_REMOTE_MECHANISM_GIT_SVN, "GIGGLE_REMOTE_MECHANISM_GIT_SVN", "git-svn"},
			{GIGGLE_REMOTE_MECHANISM_INVALID, "GIGGLE_REMOTE_MECHANISM_INVALID", "invalid"},
			{0, NULL, NULL}
		};

		etype = g_enum_register_static("GiggleRemoteMechanism", values);
	}
	
	return etype;
}
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
/* enumerations from "giggle-searchable.h" */
#include "giggle-searchable.h"
GType
giggle_search_direction_get_type(void) {
	static GType etype = 0;
	if(!etype) {
		static const GEnumValue values[] = {
			{GIGGLE_SEARCH_DIRECTION_NEXT, "GIGGLE_SEARCH_DIRECTION_NEXT", "next"},
			{GIGGLE_SEARCH_DIRECTION_PREV, "GIGGLE_SEARCH_DIRECTION_PREV", "prev"},
			{0, NULL, NULL}
		};

		etype = g_enum_register_static("GiggleSearchDirection", values);
	}
	
	return etype;
}

/* Generated data ends here */

