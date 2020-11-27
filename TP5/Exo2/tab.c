#include <stdlib.h>
#include <stdio.h>
#include "tab.h"


TABLEAU newArray() {
	// Renvoie une structure TABLEAU
	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	tab.elt = malloc(TAILLEINITIALE*sizeof(int));

	for (int i = 0; i < tab.size; i++) {
		tab.elt[i] = 0;
	}
	return tab;
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	// Augmente la taille du tableau de incrementValue
	if (incrementValue < 0 || tab->elt == NULL) {
		return -1;
	}
	int* save = tab->elt;
	int* tab2 = realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));
	if(tab2 == NULL) {
		tab->elt = save;
		return -1;
	} else {
		tab->elt = tab2;
		// On met des 0 aux valeurs ajoutées.
		for (int i = 0; i < incrementValue; i++) {
			tab->elt[tab->size + i] = 0;
		}
		tab->size += incrementValue;
	}
	return tab->size;
}

int setElement(TABLEAU* tab, int pos, int element) {
	// Ecrit un élément à une position donnée sans insertion. Augmente la taille du tableau si nécéssaire.
	if (tab->elt == NULL || pos <= 0) {
		return 0;
	}
	if (pos > tab->size) {
		incrementArraySize(tab, pos - tab->size);
		if (tab->elt == NULL) {
			return 0;
		}
	}
	// On met à jour le nombre d'éléments.
	if (pos >= tab->eltsCount) {
		tab->eltsCount = pos;
	}
	// On ajoute l'élément à la bonne place.
	// Les zéros sont mis automatiquement dans la fonction incrementArraySize
	tab->elt[pos - 1] = element;
	
	return pos;
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	// Affiche une portion de tableau, entre startPos et endPos.
	if (startPos > endPos) {
		int tmp = startPos;
		startPos = endPos;
		endPos = tmp;
	}
	if (tab->elt == NULL || startPos < 1 || endPos > tab->eltsCount) {
		return -1;
	}
	for (int i = startPos; i <= endPos; i++) {
		printf("%d  ", tab->elt[i-1]);
	}
	return 0;
}


int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	// Supprime les éléments du tableau aux positions dans l'intervalle [startPos, endPos]
	if (startPos > endPos) {
		int tmp = startPos;
		startPos = endPos;
		endPos = tmp;
	}
	if (tab->elt == NULL || startPos < 1 || endPos > tab->eltsCount) {
		return -1;
	}

	int* tab2 = tab->elt;
	int c = 0;

	for (int i = 0; i < tab->size; i++) {
		if (i<startPos-1 || i>endPos-1) {
			tab->elt[c] = tab2[i];
			c++;
		}
	}
	tab->eltsCount -= endPos - startPos + 1;
	tab->size -= endPos - startPos + 1;
	return tab->size;
}