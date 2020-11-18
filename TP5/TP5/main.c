#include <stdlib.h>
#include <stdio.h>
#include "tab.h"


int main() {
	int myTab[10];
	int* myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));

	// Remplissage du tableau avec des 0
	initTab(myTab2, TAB2SIZE);

	// Remplissage des 20 premières valeures du tableau avec les nombres de 1 à 20
	if (myTab2 != NULL) {
		for (int i = 0; i < 20; i++) {
			*(myTab2 + i) = i + 1;
		}
	}

	// Affichage tu tableau
	afficheTab(myTab2, TAB2SIZE, 100);
	printf("\n\n");

	// Ajout d'un élément à le place 101 du tableau. Réallocation de mémoire nécéssaire.
	int size = TAB2SIZE;
	int nbElmts = 100;
	ajoutElementDansTableau(myTab2, &size, &nbElmts, 1);
	afficheTab(myTab2, size, 110);

	// Destruction du tableau
	free(myTab2);
}

