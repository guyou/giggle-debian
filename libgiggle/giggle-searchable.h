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

#ifndef __GIGGLE_SEARCHABLE_H__
#define __GIGGLE_SEARCHABLE_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define GIGGLE_TYPE_SEARCHABLE            (giggle_searchable_get_type ())
#define GIGGLE_SEARCHABLE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIGGLE_TYPE_SEARCHABLE, GiggleSearchable))
#define GIGGLE_IS_SEARCHABLE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIGGLE_TYPE_SEARCHABLE))
#define GIGGLE_SEARCHABLE_GET_IFACE(obj)  (G_TYPE_INSTANCE_GET_INTERFACE ((obj), GIGGLE_TYPE_SEARCHABLE, GiggleSearchableIface))

typedef struct GiggleSearchableIface GiggleSearchableIface;
typedef struct GiggleSearchable      GiggleSearchable; /* dummy */

typedef enum {
	GIGGLE_SEARCH_DIRECTION_NEXT,
	GIGGLE_SEARCH_DIRECTION_PREV
} GiggleSearchDirection;

struct GiggleSearchableIface {
	GTypeInterface iface;

	gboolean (* search) (GiggleSearchable      *searchable,
			     const gchar           *search_term,
			     GiggleSearchDirection  direction,
			     gboolean               full_search,
	                     gboolean               case_insensitive);
	void     (* cancel) (GiggleSearchable      *searchable);
};

GType      giggle_searchable_get_type (void);
gboolean   giggle_searchable_search   (GiggleSearchable      *searchable,
				       const gchar           *search_term,
				       GiggleSearchDirection  direction,
                                       gboolean               full_search,
                                       gboolean               case_sensitive);

void       giggle_searchable_cancel   (GiggleSearchable      *searchable);


G_END_DECLS

#endif /* __GIGGLE_SEARCHABLE_H__ */
