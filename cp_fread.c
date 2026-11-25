/* TD6, exercice 5 : copie par blocs de 4096 octets avec fread()/fwrite() (version 6) */
#include <stdio.h>
#include <stdlib.h>

#define BLOC 4096

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage : %s source destination\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE *src = fopen(argv[1], "rb");
	if (src == NULL) {
		perror(argv[1]);
		return EXIT_FAILURE;
	}
	/* ETAPE 1 : ouvrir la destination en ecriture binaire ; declarer un tampon statique de BLOC octets. */
	/* ETAPE 2 : boucle : lire un bloc avec fread jusqu'a ce qu'elle retourne 0 ; ecrire exactement
	             ce nombre d'octets avec fwrite (sinon : erreur).                                         */
	/* ETAPE 3 : apres la boucle : erreur de lecture ? ; fermer la destination (tester son retour) et la source. */
	fclose(src);
	return EXIT_SUCCESS;
}
