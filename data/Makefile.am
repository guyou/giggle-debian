gladedir = $(datadir)/giggle/glade
dist_glade_DATA = \
	main-window.ui

desktop_in_data=giggle.desktop.in
desktop_DATA=$(desktop_in_data:.desktop.in=.desktop)
desktopdir=$(datadir)/applications
@INTLTOOL_DESKTOP_RULE@

CLEANFILES=$(desktop_DATA)

EXTRA_DIST=giggle.desktop.in
