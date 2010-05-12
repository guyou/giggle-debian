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

#ifndef __GIGGLE_BRANCHES_VIEW_H__
#define __GIGGLE_BRANCHES_VIEW_H__

#include "giggle-short-list.h"

G_BEGIN_DECLS

#define GIGGLE_TYPE_BRANCHES_VIEW            (giggle_branches_view_get_type ())
#define GIGGLE_BRANCHES_VIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIGGLE_TYPE_BRANCHES_VIEW, GiggleBranchesView))
#define GIGGLE_BRANCHES_VIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIGGLE_TYPE_BRANCHES_VIEW, GiggleBranchesViewClass))
#define GIGGLE_IS_BRANCHES_VIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIGGLE_TYPE_BRANCHES_VIEW))
#define GIGGLE_IS_BRANCHES_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIGGLE_TYPE_BRANCHES_VIEW))
#define GIGGLE_BRANCHES_VIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIGGLE_TYPE_BRANCHES_VIEW, GiggleBranchesViewClass))

typedef GiggleShortList      GiggleBranchesView;
typedef GiggleShortListClass GiggleBranchesViewClass;

GType              giggle_branches_view_get_type          (void);
GtkWidget *        giggle_branches_view_new               (void);

G_END_DECLS

#endif /* __GIGGLE_BRANCHES_VIEW_H__ */
