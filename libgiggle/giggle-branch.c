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
#include <gtk/gtk.h>

#include "giggle-branch.h"
#include "giggle-revision.h"
#include "giggle-ref.h"

G_DEFINE_TYPE (GiggleBranch, giggle_branch, GIGGLE_TYPE_REF)


static void
giggle_branch_class_init (GiggleBranchClass *class)
{
}

static void
giggle_branch_init (GiggleBranch *ref)
{
}

GiggleRef *
giggle_branch_new (const gchar *name)
{
	return g_object_new (GIGGLE_TYPE_BRANCH,
			     "name", name,
			     NULL);
}
