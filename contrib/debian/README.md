
Debian
====================
This directory contains files used to package crowd/crow-qt
for Debian-based Linux systems. If you compile crowd/crow-qt yourself, there are some useful files here.

## crow: URI support ##


crow-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install crow-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your crow-qt binary to `/usr/bin`
and the `../../share/pixmaps/crow128.png` to `/usr/share/pixmaps`

crow-qt.protocol (KDE)

