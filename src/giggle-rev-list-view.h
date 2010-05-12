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

#ifndef __GIGGLE_REV_LIST_VIEW_H__
#define __GIGGLE_REV_LIST_VIEW_H__

#include <glib-object.h>
#include <gtk/gtk.h>
#include "libgiggle/giggle-revision.h"

G_BEGIN_DECLS

#define GIGGLE_TYPE_REV_LIST_VIEW            (giggle_rev_list_view_get_type ())
#define GIGGLE_REV_LIST_VIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIGGLE_TYPE_REV_LIST_VIEW, GiggleRevListView))
#define GIGGLE_REV_LIST_VIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIGGLE_TYPE_REV_LIST_VIEW, GiggleRevListViewClass))
#define GIGGLE_IS_REV_LIST_VIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIGGLE_TYPE_REV_LIST_VIEW))
#define GIGGLE_IS_REV_LIST_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIGGLE_TYPE_REV_LIST_VIEW))
#define GIGGLE_REV_LIST_VIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIGGLE_TYPE_REV_LIST_VIEW, GiggleRevListViewClass))

typedef struct _GiggleRevListView      GiggleRevListView;
typedef struct _GiggleRevListViewClass GiggleRevListViewClass;

struct _GiggleRevListView {
	GtkTreeView parent_instance;
};

struct _GiggleRevListViewClass {
	GtkTreeViewClass parent_class;

	void (* selection_changed)  (GiggleRevListView *list,
				     GiggleRevision    *revision1,
				     GiggleRevision    *revision2);
	void (* revision_activated) (GiggleRevListView *list,
				     GiggleRevision    *revision);
};

GType              giggle_rev_list_view_get_type          (void);
GtkWidget *        giggle_rev_list_view_new               (void);

void               giggle_rev_list_view_set_model         (GiggleRevListView *list,
							   GtkTreeModel       *model);

gboolean           giggle_rev_list_view_get_graph_visible (GiggleRevListView *list);
void               giggle_rev_list_view_set_graph_visible (GiggleRevListView *list,
							   gboolean           show_graph);

GList *            giggle_rev_list_view_get_selection     (GiggleRevListView *list);
int                giggle_rev_list_view_set_selection     (GiggleRevListView *list,
							   GList             *revisions);

G_END_DECLS

#endif /* __GIGGLE_REV_LIST_VIEW_H__ */
