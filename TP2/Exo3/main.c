#include <stdlib.h>
#include <stdio.h>


int main() {
	int an = 10001;
	while (an < 0 || an > 10000) {
		printf("Entrer l'annee a tester : ");
		scanf_s("%hu", &an);
	}

	// Première methode.
	printf("METHODE 1 : \n");
	printf("%d ", an);
	if ((an % 400 == 0) || (an % 100 != 0 && an % 4 == 0)) {
		printf("est ");
	}
	else {
		printf("n'est pas ");
	}
	printf("une annee bissectile\n");

	// Deuxième methode.
	printf("METHODE 2 : \n");
	printf("%d ", an);
	if (an % 400 == 0) {
		printf("est ");
	} else {
		if (an % 100 == 0) {
			printf("n'est pas ");
		} else {
			if (an % 4 == 0) {
				printf("est ");
			} else {
				printf("n'est pas ");
			}
		}
	}
	printf("une annee bissectile\n\n");
	main();

}