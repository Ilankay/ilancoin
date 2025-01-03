#!/usr/bin/env bash
# Copyright (c) 2016-2019 The Ilancoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

ILANCOIND=${ILANCOIND:-$BINDIR/ilancoind}
ILANCOINCLI=${ILANCOINCLI:-$BINDIR/ilancoin-cli}
ILANCOINTX=${ILANCOINTX:-$BINDIR/ilancoin-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/ilancoin-wallet}
ILANCOINQT=${ILANCOINQT:-$BINDIR/qt/ilancoin-qt}

[ ! -x $ILANCOIND ] && echo "$ILANCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
read -r -a ILCVER <<< "$($ILANCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }')"

# Create a footer file with copyright content.
# This gets autodetected fine for ilancoind if --version-string is not set,
# but has different outcomes for ilancoin-qt and ilancoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$ILANCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $ILANCOIND $ILANCOINCLI $ILANCOINTX $WALLET_TOOL $ILANCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${ILCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${ILCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
