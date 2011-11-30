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

#ifndef __GIGGLE_DIFF_VIEW_H__
#define __GIGGLE_DIFF_VIEW_H__

#include <glib-object.h>
#include <gtk/gtk.h>
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourcelanguagemanager.h>

#include "libgiggle/giggle-revision.h"

G_BEGIN_DECLS

#define GIGGLE_TYPE_DIFF_VIEW            (giggle_diff_view_get_type ())
#define GIGGLE_DIFF_VIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIGGLE_TYPE_DIFF_VIEW, GiggleDiffView))
#define GIGGLE_DIFF_VIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIGGLE_TYPE_DIFF_VIEW, GiggleDiffViewClass))
#define GIGGLE_IS_DIFF_VIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIGGLE_TYPE_DIFF_VIEW))
#define GIGGLE_IS_DIFF_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIGGLE_TYPE_DIFF_VIEW))
#define GIGGLE_DIFF_VIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIGGLE_TYPE_DIFF_VIEW, GiggleDiffViewClass))

enum {
	STYLE_CHUNK,
	STYLE_FILE,
	STYLE_ALL,
} giggle_diff_style;

typedef struct GiggleDiffView      GiggleDiffView;
typedef struct GiggleDiffViewClass GiggleDiffViewClass;

struct GiggleDiffView {
	GtkSourceView parent_instance;
};

struct GiggleDiffViewClass {
	GtkSourceViewClass parent_class;
};

GType              giggle_diff_view_get_type          (void);
GtkWidget *        giggle_diff_view_new               (void);

void               giggle_diff_view_set_revisions     (GiggleDiffView *diff_view,
						       GiggleRevision *revision1,
						       GiggleRevision *revision2,
						       GList          *files);
void               giggle_diff_view_diff_current      (GiggleDiffView *diff_view,
						       GList          *files);
void               giggle_diff_view_set_current_hunk  (GiggleDiffView *diff_view,
						       int             hunk_index);
void               giggle_diff_view_set_current_style (GiggleDiffView *diff_view,
						       gint            style);
int                giggle_diff_view_get_current_hunk  (GiggleDiffView *diff_view);

int                giggle_diff_view_get_current_style (GiggleDiffView *diff_view);

int                giggle_diff_view_get_n_hunks       (GiggleDiffView *diff_view);

void               giggle_diff_view_scroll_to_file    (GiggleDiffView *diff_view,
						       const char     *filename);

const char *       giggle_diff_view_get_current_file  (GiggleDiffView *diff_view);

int                giggle_diff_view_get_current_file_nb (GiggleDiffView *diff_view);

G_END_DECLS

#endif /* __GIGGLE_DIFF_VIEW_H__ */
