/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2009 Mathias Hasselmann
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

#include "config.h"
#include "giggle-view-terminal.h"

#include <libgiggle/giggle-clipboard.h>

#include <glib/gi18n.h>
#include <vte/vte.h>

#define GET_PRIV(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GIGGLE_TYPE_VIEW_TERMINAL, GiggleViewTerminalPriv))

typedef struct {
	GtkWidget *notebook;
} GiggleViewTerminalPriv;

static void
giggle_view_terminal_clipboard_init (GiggleClipboardIface *iface);

G_DEFINE_TYPE_WITH_CODE (GiggleViewTerminal, giggle_view_terminal, GIGGLE_TYPE_VIEW,
			 G_IMPLEMENT_INTERFACE (GIGGLE_TYPE_CLIPBOARD,
						giggle_view_terminal_clipboard_init))

static void
view_terminal_tab_remove_cb (GtkNotebook *notebook,
			     GtkWidget   *child,
			     GiggleView  *view)
{
	if (0 == gtk_notebook_get_n_pages (notebook))
		gtk_action_set_visible (giggle_view_get_action (view), FALSE);
}

static void
view_terminal_dispose (GObject *object)
{
	GiggleViewTerminalPriv *priv = GET_PRIV (object);

	if (priv->notebook) {
		g_signal_handlers_disconnect_by_func (priv->notebook,
						      view_terminal_tab_remove_cb,
						      object);
		priv->notebook = NULL;
	}

	G_OBJECT_CLASS (giggle_view_terminal_parent_class)->dispose (object);
}

static void
giggle_view_terminal_class_init (GiggleViewTerminalClass *class)
{
	GObjectClass *object_class = G_OBJECT_CLASS (class);

	object_class->dispose = view_terminal_dispose;

	g_type_class_add_private (class, sizeof (GiggleViewTerminalPriv));
}

static void
giggle_view_terminal_init (GiggleViewTerminal *view)
{
	GiggleViewTerminalPriv *priv = GET_PRIV (view);

	priv->notebook = gtk_notebook_new ();
	/*FIXME:gtk_notebook_set_show_tabs (GTK_NOTEBOOK (priv->notebook), FALSE);*/
	gtk_container_add (GTK_CONTAINER (view), priv->notebook);
	gtk_widget_show (priv->notebook);

	g_signal_connect (priv->notebook, "remove",
			  G_CALLBACK (view_terminal_tab_remove_cb), view);
}

GtkWidget *
giggle_view_terminal_new (void)
{
	GtkAction *action;

	action = g_object_new (GTK_TYPE_RADIO_ACTION,
			       "name", "TerminalView",
			       "label", _("_Terminal"),
			       "tooltip", _("Issue git commands via terminal"),
			       "icon-name", "utilities-terminal",
			       "is-important", TRUE,
			       "visible", FALSE, NULL);

	return g_object_new (GIGGLE_TYPE_VIEW_TERMINAL,
			     "action", action, NULL);
}

static void
view_terminal_close_tab (GtkWidget *terminal)
{
	GtkWidget *notebook = gtk_widget_get_parent (terminal);
	gtk_container_remove (GTK_CONTAINER (notebook), terminal);
}

static void
view_terminal_title_changed_cb (GtkWidget *terminal,
				GtkWidget *label)
{
	const char *title;

	title = vte_terminal_get_window_title (VTE_TERMINAL (terminal));
	gtk_label_set_text (GTK_LABEL (label), title);
}

static GtkWidget *
view_terminal_create_label (GiggleViewTerminal *view,
			    GtkWidget          *terminal,
			    const char         *title)
{
	GtkWidget *label, *button, *image, *hbox;

	label = gtk_label_new (title);
	gtk_label_set_ellipsize (GTK_LABEL (label), PANGO_ELLIPSIZE_MIDDLE);

	button = gtk_button_new ();
	gtk_widget_set_name (button, "giggle-terminal-tab-close-button");
	gtk_button_set_relief (GTK_BUTTON (button), GTK_RELIEF_NONE);

	g_signal_connect_swapped (button, "clicked",
				  G_CALLBACK (view_terminal_close_tab),
				  terminal);

	image = gtk_image_new_from_stock (GTK_STOCK_CLOSE, GTK_ICON_SIZE_MENU);
	gtk_container_add (GTK_CONTAINER (button), image);

	hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start (GTK_BOX (hbox), label, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, FALSE, 0);
	gtk_widget_show_all (hbox);

	g_signal_connect (terminal, "window-title-changed",
			  G_CALLBACK (view_terminal_title_changed_cb), label);

	return hbox;
}

void
giggle_view_terminal_append_tab (GiggleViewTerminal *view,
				 const char         *directory)
{
	GiggleViewTerminalPriv *priv = GET_PRIV (view);
	VtePtyFlags             pty_flags;
	GtkWidget              *terminal, *label;
	GError                 *error = NULL;
	GSpawnFlags             spawn_flags;
	char                   *title;
	const gchar            *shell;
	gchar                 **real_argv;
	gboolean                succes;
	int                     i;

	g_return_if_fail (GIGGLE_IS_VIEW_TERMINAL (view));
	g_return_if_fail (NULL != directory);

	terminal = vte_terminal_new ();
	gtk_widget_grab_focus (terminal);
	gtk_widget_show (terminal);

	g_signal_connect (terminal, "child-exited",
			  G_CALLBACK (view_terminal_close_tab), NULL);

	g_signal_connect_swapped (terminal, "selection-changed",
				  G_CALLBACK (giggle_clipboard_changed), view);

	pty_flags = VTE_PTY_NO_LASTLOG | VTE_PTY_NO_UTMP | VTE_PTY_NO_WTMP;
	shell = g_getenv ("SHELL");
	real_argv = g_new (char *, 2);
	real_argv[0] = g_strdup (shell ? shell : "/bin/sh");
	real_argv[1] = NULL;
	spawn_flags = G_SPAWN_CHILD_INHERITS_STDIN | G_SPAWN_SEARCH_PATH | G_SPAWN_FILE_AND_ARGV_ZERO;

	succes = vte_terminal_fork_command_full (VTE_TERMINAL (terminal),
	                                         pty_flags,
	                                         directory,
	                                         real_argv,
	                                         NULL,
	                                         spawn_flags,
	                                         NULL, NULL,
	                                         NULL,
	                                         &error);
	g_strfreev (real_argv);

	if (succes == FALSE) {
		g_warning ("%s: %s: vte_terminal_fork_command_full failed %s",
		           G_STRLOC, G_STRFUNC, error->message);
		g_error_free (error);
	}

	title = g_filename_display_name (directory);
	label = view_terminal_create_label (view, terminal, title);
	g_free (title);

	i = gtk_notebook_append_page (GTK_NOTEBOOK (priv->notebook), terminal, label);
	/*FIXME:gtk_notebook_set_show_tabs (GTK_NOTEBOOK (priv->notebook), i > 0);*/
	gtk_notebook_set_current_page (GTK_NOTEBOOK (priv->notebook), i);

	gtk_container_child_set (GTK_CONTAINER (priv->notebook),
	                         terminal,
	                         "tab-expand", TRUE,
	                         "tab-fill", TRUE,
	                         NULL);

	gtk_action_set_visible (giggle_view_get_action (GIGGLE_VIEW (view)), TRUE);
}

static VteTerminal *
view_terminal_get_current (GiggleViewTerminal *view)
{
	GiggleViewTerminalPriv *priv = GET_PRIV (view);
	GtkWidget *page;
	int page_no;

	page_no = gtk_notebook_get_current_page (GTK_NOTEBOOK (priv->notebook));
	page = gtk_notebook_get_nth_page (GTK_NOTEBOOK (priv->notebook), page_no);

	return VTE_TERMINAL (page);

}

static void
view_terminal_do_copy (GiggleClipboard *clipboard)
{
	GiggleViewTerminal *view = GIGGLE_VIEW_TERMINAL (clipboard);
	VteTerminal *terminal = view_terminal_get_current (view);
	vte_terminal_copy_clipboard (terminal);
}

static gboolean
view_terminal_can_copy (GiggleClipboard *clipboard)
{
	GiggleViewTerminal *view = GIGGLE_VIEW_TERMINAL (clipboard);
	VteTerminal *terminal = view_terminal_get_current (view);
	return vte_terminal_get_has_selection (terminal);
}

static void
view_terminal_do_paste (GiggleClipboard *clipboard)
{
	GiggleViewTerminal *view = GIGGLE_VIEW_TERMINAL (clipboard);
	VteTerminal *terminal = view_terminal_get_current (view);
	vte_terminal_paste_clipboard (terminal);
}

static gboolean
view_terminal_can_paste (GiggleClipboard *clipboard)
{
	return TRUE;
}

static void
giggle_view_terminal_clipboard_init (GiggleClipboardIface *iface)
{
	iface->do_copy   = view_terminal_do_copy;
	iface->can_copy  = view_terminal_can_copy;
	iface->do_paste  = view_terminal_do_paste;
	iface->can_paste = view_terminal_can_paste;
}
