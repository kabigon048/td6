#!/bin/sh
# Cree les trois fichiers de test (donnees aleatoires, donc non compressibles) avec dd
set -eu
dd if=/dev/urandom of=f1M   bs=1M count=1   status=none
dd if=/dev/urandom of=f10M  bs=1M count=10  status=none
dd if=/dev/urandom of=f100M bs=1M count=100 status=none
ls -l f1M f10M f100M
