/* TD6, exercice 2 : copie avec read()/write() et un tampon de TAILLE octets (-DTAILLE=512 a la compilation)
   Ce squelette contient une version NAIVE qui fonctionne dans le cas simple : lancez-la d'abord,
   puis corrigez ses defauts un par un (ETAPES 2 a 6). */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef TAILLE
#define TAILLE 1024
#endif

/* ETAPE 2 : write() peut ecrire MOINS que demande. Ecrire ici une fonction ecrire_tout(fd, buf, n)
   qui ecrit TOUS les octets : boucler tant qu'il en reste ; si l'appel est interrompu par un signal
   (EINTR), recommencer ; pour toute autre erreur, retourner -1 (voir l'enonce).                    */

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
	/* ETAPE 3 : examiner la source avec fstat ; refuser ce qui n'est pas un fichier ordinaire ;
	             refuser que la source et la destination soient le meme fichier (meme peripherique ET
	             meme i-noeud), AVANT d'ouvrir la destination avec O_TRUNC.                           */
	/* ETAPE 4 : creer la destination avec les droits de la source (et non 0644).                     */
	int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dst == -1) {
		perror(argv[2]);
		close(src);
		return EXIT_FAILURE;
	}

	static char buf[TAILLE];
	ssize_t n;
	while ((n = read(src, buf, sizeof(buf))) > 0) {
		if (write(dst, buf, (size_t)n) == -1) {          /* ETAPE 2 : a remplacer par ecrire_tout */
			perror(argv[2]);
			break;
		}
	}
	/* ETAPE 5 : la boucle s'arrete aussi sur une erreur de LECTURE (n == -1) : la detecter (et ignorer
	             EINTR) puis terminer en echec.                                                        */
	/* ETAPE 6 : tester le retour de close(dst) : une erreur d'ecriture differee n'apparait parfois qu'ici. */
	close(dst);
	close(src);
	return EXIT_SUCCESS;                                 /* ETAPES 5 et 6 : succes seulement si tout a reussi */
}
