# TD 6 : six versions de cp
CC     = gcc
CFLAGS = -std=c11 -D_XOPEN_SOURCE=700 -O0 -Wall -Wextra -Werror -pedantic
# -O0 : on mesure le systeme, pas l'optimiseur

PROGRAMMES = cp_rw1 cp_rw512 cp_rw1024 cp_getc cp_fread cp_mmap

all: $(PROGRAMMES)

cp_rw1:    cp_rw.c ; $(CC) $(CFLAGS) -DTAILLE=1    $< -o $@
cp_rw512:  cp_rw.c ; $(CC) $(CFLAGS) -DTAILLE=512  $< -o $@
cp_rw1024: cp_rw.c ; $(CC) $(CFLAGS) -DTAILLE=1024 $< -o $@
cp_getc:   cp_getc.c  ; $(CC) $(CFLAGS) $< -o $@
cp_fread:  cp_fread.c ; $(CC) $(CFLAGS) $< -o $@
cp_mmap:   cp_mmap.c  ; $(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(PROGRAMMES) copie.tmp
