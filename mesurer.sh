#!/bin/bash
# Mesure les 6 versions sur les 3 fichiers avec la commande interne `time` de bash.
# N essais par case : on garde le temps reel MINIMAL (le moins perturbe par le reste du systeme).
# Usage : bash mesurer.sh [nombre_d_essais]      (3 par defaut ; la version a 1 octet est longue sur 100 Mo !)
ESSAIS=${1:-3}
PROGS="cp_rw1 cp_rw512 cp_rw1024 cp_getc cp_fread cp_mmap"
FICHIERS="f1M f10M f100M"
export LC_ALL=C             # point decimal (et non virgule) : awk compare des nombres
TIMEFORMAT='%R %U %S'          # real user sys, en secondes
printf '%-11s' "version"; for f in $FICHIERS; do printf '%24s' "$f real/user/sys (s)"; done; echo
for p in $PROGS; do
  printf '%-11s' "$p"
  for f in $FICHIERS; do
    meilleur=""
    for ((i = 0; i < ESSAIS; i++)); do
      rm -f copie.tmp
      t=$( { time ./$p $f copie.tmp; } 2>&1 ) || { echo "ECHEC $p $f"; exit 1; }
      cmp -s $f copie.tmp || { echo "COPIE DIFFERENTE : $p $f"; exit 1; }     # on verifie toujours le resultat
      if [ -z "$meilleur" ] || awk -v a="${t%% *}" -v b="${meilleur%% *}" 'BEGIN { exit !(a < b) }'; then meilleur=$t; fi
    done
    printf '%24s' "$(echo $meilleur | tr ' ' '/')"
  done
  echo
done
rm -f copie.tmp
