#include <stdlib.h>
#include <stdio.h>
#include "tab.h"


int initTab(int* tab, int tabSize) {
	// Fonction qui remplit un tableau d�entiers de taille size avec des z�ros.
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
	// Fonction qui affiche les nbElts premi�rs �l�ments du tableau tab sur une ligne de la console.
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
	// Fonction qui  ajoute un nombre entier � la suite des valeurs d�j� entr�es et met 
	// � jour le nombre d'�l�ments stock�s ainsi que la capacit� r�elle du tableau
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
			// On initialise les derni�res valeurs du nouveau tableau � 0
			for (int i = 0; i < TAILLEAJOUT; i++) {
				*(tab + i + *size) = 0;
			}
			*size += TAILLEAJOUT;
		}
	}
	// Ajout de l'�l�ment � la place d�sir�e
	*(tab + *nbElts) = element;
	return *nbElts + 1;
}