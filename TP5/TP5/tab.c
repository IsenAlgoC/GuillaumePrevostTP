#include <stdlib.h>
#include <stdio.h>
#include "tab.h"


int initTab(int* tab, int tabSize) {
	// Fonction qui remplit un tableau d’entiers de taille size avec des zéros.
	if (tabSize < 0 || tab == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < tabSize; i++) {
			*(tab + i) = 0;
		}
		return tabSize;
	}
}

int afficheTab(int* tab, int size, int nbElts) {
	// Fonction qui affiche les nbElts premièrs éléments du tableau tab sur une ligne de la console.
	if (size <= 0 || tab == NULL || nbElts>size) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d  ",*(tab+i));
		}
		return 0;
	}
}

int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	// Fonction qui  ajoute un nombre entier à la suite des valeurs déjà entrées et met 
	// à jour le nombre d'éléments stockés ainsi que la capacité réelle du tableau
	if (*size <= 0 || tab == NULL) {
		return -1;
	}
	if(*nbElts >= *size){
		// On utilise realloc pour agrandir le tableau
		int* tab2 = (int*)realloc(tab, (TAILLEAJOUT+*size) * sizeof(int));
		if (tab2 == NULL) {
			return -1;
		} else {
			tab = tab2;
			// On initialise les dernières valeurs du nouveau tableau à 0
			for (int i = 0; i < TAILLEAJOUT; i++) {
				*(tab + i + *size) = 0;
			}
			*size += TAILLEAJOUT;
		}
	}
	// Ajout de l'élément à la place désirée
	*(tab + *nbElts) = element;
	return *nbElts + 1;
}