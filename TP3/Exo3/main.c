#include <stdlib.h>
#include <stdio.h>
#include <math.h>




int main() {
	#define NBMAXNOTES 30
	char a = "N";
	float n = 0;
	int i = 0;
	int abs = 0;
	int val = 0;
	float tab[NBMAXNOTES];
	for (int j = 0; j < 30; j++) {
		tab[j] = -2;
	}
	/*

	while (i < 30 && a != 'O') {
		i++;
		printf("Entrez la note %d : ", i);
		scanf_s("%f", &n);
		if (n > 20 || n < 0) {
			printf("Eleve absent ? ou voulez-vous arreter la saisie des notes ? A/O/N  ");
			scanf_s(" %c", &a);
			if (a == 'A') {
				abs++;
				tab[i - 1] = -1;
			}
		} else {
			tab[i - 1] = n;
			val++;
		}
	}*/
	
	tab[0] = 2;
	tab[1] = 1;
	tab[2] = 4;
	tab[3] = 3;
	val = 4;
	i = 4;
	abs = 0;

	// CALCUL DES EXTREMUMS
	float min = 20;
	float max = 0;
	for (int j = 0; j < val+abs; j++) {
		if (tab[j] != -1 && tab[j] != -2 && tab[j] > max) {
			max = tab[j];
		}
		if (tab[j] != -1 && tab[j] != -2 && tab[j] < min) {
			min = tab[j];
		}
	}
	printf("\nIl y a %d notes valides, %d absents", val, abs);
	printf("\nLa note min est %f, la note max est %f", min, max);

	// CALCUL DE LA MOYENNE
	float sum = 0;
	for (int j = 0; j < val + abs; j++) {
		if (tab[j] != -1 && tab[j] != -2) {
			sum += tab[j];
		}
	}
	float moy = sum / val;
	printf("\nMoyenne : %f", moy);

	// CALCUL DE L'ECART-TYPE
	float et = 0;
	float s = 0;
	for (int j = 0; j < val+abs; j++) {
		if (tab[j] != -1 && tab[j] != -2) {
			s += (moy - tab[j]) * (moy - tab[j]);
		}
	}
	et = sqrtf(s/val);
	printf("\nEcart-type : %f\n", et);

	// COPIE DES TABLEAUX
	float tab2[NBMAXNOTES];
	int tab_ind[NBMAXNOTES];
	int tab_ind2[NBMAXNOTES];
	for (int j = 0; j < NBMAXNOTES; j++) {
		tab2[j] = tab[j];
		tab_ind[j] = j;
		tab_ind2[j] = j;
	}

	// TRI DES TABLEAUX
	float tmp;
	for (i = 0; i < NBMAXNOTES - 1; i++) {
		for (int j = 0; j < NBMAXNOTES - i - 1; j++) {
			if (tab2[j] < tab2[j + 1]) {
				tmp = tab2[j];
				tab2[j] = tab2[j + 1];
				tab2[j + 1] = tmp;
				tmp = tab_ind2[j];
				tab_ind2[j] = tab_ind2[j + 1];
				tab_ind2[j + 1] = tmp;
			}
		}
	}

	// AFFICHAGE
	printf("\n\n");
	printf("\nIndice  Note");
	for (int j = 0; j < NBMAXNOTES; j++) {
		if (tab[j] >= 0) {
			printf("\n%d       %f", tab_ind[j], tab[j]);
		}
	}
	printf("\n\n");
	printf("\nRang  Indice  Note");
	for (int j = 0; j < NBMAXNOTES; j++) {
		if (tab2[j] >= 0) {
			printf("\n%d     %d      %f", j, tab_ind2[j], tab2[j]);
		}
	} 
}

