/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2007 Imendio AB
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <config.h>

#include "giggle-tree-view-helpers.h"

#include <gdk/gdkkeysyms.h>
#include <gtk/gtktreeselection.h>

static void
remote_editor_tree_selection_get_branches (GtkTreeModel *model,
					   GtkTreePath  *path,
					   GtkTreeIter  *iter,
					   GList       **branches)
{
	*branches = g_list_prepend (*branches, gtk_tree_row_reference_new (model, path));
}

static void
remote_editor_remove_branch (GtkTreeRowReference *ref)
{
	GtkTreeModel *model;
	GtkTreeIter   iter;

	model = gtk_tree_row_reference_get_model (ref);
	gtk_tree_model_get_iter (model, &iter,
				 gtk_tree_row_reference_get_path (ref));
	gtk_list_store_remove (GTK_LIST_STORE (model), &iter);

	gtk_tree_row_reference_free (ref);
}

gboolean
tree_view_delete_selection_on_list_store (GtkWidget   *treeview,
					  GdkEventKey *event)
{
	if (event->keyval == GDK_Delete) {
		GtkTreeSelection* sel;
		sel = gtk_tree_view_get_selection (GTK_TREE_VIEW (treeview));

		if (gtk_tree_selection_count_selected_rows (sel) > 0) {
			GList* branches = NULL;
			gtk_tree_selection_selected_foreach (sel,
							     (GtkTreeSelectionForeachFunc)
								remote_editor_tree_selection_get_branches,
							     &branches);
			g_list_foreach (branches, (GFunc)remote_editor_remove_branch, NULL);
			g_list_free (branches);
			return TRUE;
		}
	}
	return FALSE;
}

