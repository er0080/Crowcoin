#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

CROWD=${CROWD:-$SRCDIR/crowd}
CROWCLI=${CROWCLI:-$SRCDIR/crow-cli}
CROWTX=${CROWTX:-$SRCDIR/crow-tx}
CROWQT=${CROWQT:-$SRCDIR/qt/crow-qt}

[ ! -x $CROWD ] && echo "$CROWD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
CROWVER=($($CROWCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for crowd if --version-string is not set,
# but has different outcomes for crow-qt and crow-cli.
echo "[COPYRIGHT]" > footer.h2m
$CROWD --version | sed -n '1!p' >> footer.h2m

for cmd in $CROWD $CROWCLI $CROWTX $CROWQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${CROWVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${CROWVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
