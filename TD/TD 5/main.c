#include <stdlib.h>
#include <stdio.h>



void exo1() {
	///  EXERCICE 1
	float tab[100];
	float n = 0;
	int i = 0;

	for (int j = 0; j < 100; j++) {
		tab[j] = 0;
	}

	while (n >= 0 && i < 100) {
		i++;
		printf("Entrer une valeur : ");
		scanf_s("%f", &n);
		if (n > 0) {
			tab[i-1] = n;
		}
	}
	i--;

	printf("\nNb de valeurs : %d\n", i);
	for (int j = 0; j < 100; j++) {
		if ((j) % 10 == 0) { printf("\n"); }
		printf("%.2f  ", tab[j]);
	}

	// INSERTION DE VALEUR
	int l, c;
	float v;
	printf("\nLigne a modifier : ");
	scanf_s("%d", &l);
	printf("Colonne a modifier : ");
	scanf_s("%d", &c);
	printf("Valeur a inserer : ");
	scanf_s("%f", &v);
	tab[(l - 1) * 10 + (c - 1)] = v;

	for (int j = 0; j < 100; j++) {
		if ((j) % 10 == 0) { printf("\n"); }
		printf("%.2f  ", tab[j]);
	}

	// SUPPRESSION DE VALEUR
	printf("\nLigne a supprimer : ");
	scanf_s("%d", &l);
	printf("Colonne a supprimer : ");
	scanf_s("%d", &c);
	tab[(l - 1) * 10 + (c - 1)] = 0;

	for (int j = 0; j < 100; j++) {
		if ((j) % 10 == 0) { printf("\n"); }
		printf("%.2f  ", tab[j]);
	}

	// CALCUL DE MOYENNE
	float sum = 0;
	float num = 100;
	for (int j = 0; j < 100; j++) {
		sum += tab[j];
	}
	printf("\nMoyenne : %.2f", sum / num);
}


void exo2() {
	/// EXERCICE 2
	int tab[10][10];
	int tab2[10][10];
	// INITIALISATION
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			tab[i][j] = rand() % 21;
		}
	}
	for (int j = 0; j < 10; j++) {
		printf("\n");
		for (int i = 0; i < 10; i++) {
			printf("%d  ", tab[i][j]);
		}
	}
	// SYMETRIE
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			tab2[i][j] = tab[j][i];
		}
	}
	for (int j = 0; j < 10; j++) {
		printf("\n");
		for (int i = 0; i < 10; i++) {
			printf("%d  ", tab2[i][j]);
		}
	}


}



int main() {
	//exo1();
	exo2();
}