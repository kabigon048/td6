/* TD6, exercice 3 : copie caractere par caractere avec la bibliotheque C (version 4) */
#include <stdio.h>
#include <stdlib.h>

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
	/* ETAPE 1 : ouvrir la destination en ecriture binaire ; tester l'echec (et fermer src).        */
	/* ETAPE 2 : boucle : lire un octet avec fgetc jusqu'a EOF (le resultat va dans un int, pas un
	             char : voir la question 1) et l'ecrire avec fputc ; detecter l'echec de fputc.      */
	/* ETAPE 3 : apres la boucle, distinguer une erreur de lecture d'une fin de fichier normale.     */
	/* ETAPE 4 : fermer la destination (fclose vide le tampon d'ecriture : tester son retour) et la source. */
	fclose(src);
	return EXIT_SUCCESS;
}
