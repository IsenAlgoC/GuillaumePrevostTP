#include <stdlib.h>
#include <stdio.h>


int main() {
	char prenom[20];
	char nom[20];
	char sexe;

	printf("Entrer votre prenom : ");
	scanf_s("%s", prenom, 20);
	printf("Entrer votre nom : ");
	scanf_s("%s", nom, 20);
	printf("Entrer votre sexe : ");
	sexe = _getch();
	printf("%c\n", sexe);

	if (sexe == 'H') {
		printf("Monsieur ");
	} else {
		printf("Madame ");
	}
	printf("%s %s", prenom, nom);
}