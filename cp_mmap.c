/* TD6, exercice 4 : copie avec mmap() + memcpy() (version 5) */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage : %s source destination\n", argv[0]);
		return EXIT_FAILURE;
	}
	int src = open(argv[1], O_RDONLY);
	if (src == -1) {
		perror(argv[1]);
		return EXIT_FAILURE;
	}
	/* ETAPE 1 : examiner la source (fstat) : fichier ordinaire ; sa taille est un off_t (pas un int). */
	/* ETAPE 2 : ouvrir la destination en lecture ET ecriture (exige par une projection partagee),
	             avec creation et vidage.                                                              */
	/* ETAPE 3 : fichier vide ? mmap echoue pour une longueur nulle : il suffit de creer la destination. */
	/* ETAPE 4 : donner a la destination sa taille definitive (ftruncate) AVANT de l'ecrire par la
	             projection, sinon le programme est arrete par SIGBUS.                                   */
	/* ETAPE 5 : projeter la source (lecture seule) et la destination (ecriture partagee) ; tester
	             chaque resultat contre MAP_FAILED.                                                      */
	/* ETAPE 6 : copier avec memcpy, forcer l'ecriture sur disque (msync), liberer les projections
	             (munmap), tester close(dst).                                                            */
	close(src);
	return EXIT_SUCCESS;
}
