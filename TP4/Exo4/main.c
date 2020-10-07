#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main() {
	char mot[20];
	char letters_min[] = "azertyuiopmlkjhgfdsqwxcvbn";
	char letters_maj[] = "AZERTYUIOPMLKJHGFDSQWXCVBN";
	int lengthMot = 0;

	// maj + 32 => min
	printf("\nEntrer un mot : ");
	scanf_s("%s", &mot, 20);

	lengthMot = strlen(mot);


	// On met le mot en minuscules
	int booleen = 0;
	char letter;
	for (int j = 0; j < lengthMot; j++) {
		letter = mot[j];
		booleen = 0;
		// On teste si la lettre est en majuscule
		for (int i = 0; i <= sizeof(letters_maj); i++) {
			if (letters_maj[i] == letter) {
				booleen = 1;
			}
		}
		// Si la lettre est majuscule, on la met en minuscule
		if (booleen == 1) {
			mot[j] += 32;
		}
	}
	
	// On retire les caractères spéciaux
	for (int j = 0; j < lengthMot; j++) {
		letter = mot[j];
		booleen = 0;
		// On teste si la lettre est un caractère spécial
		for (int i = 0; i <= sizeof(letters_min); i++) {
			if (letters_min[i] == letter) {
				booleen += 1;
			}
		}
		// Si la lettre est un caractère spécial, on la change en -1
		if (booleen == 0) {
			mot[j] = -1;
		}
	}

	// On retire les caracteres speciaux
	char mot_[20];
	int n = 0;
	for (int j = 0; j < lengthMot+1; j++) {
		if (mot[j] != -1) {
			mot_[n] = mot[j];
			n++;
		}		
	}
	printf("\n%s", mot_);

	// On teste la symetrie
	lengthMot = strlen(mot_);

	int test = 1;
	for (int i = 0; i < lengthMot / 2; i++) {
		if (mot_[i] != mot_[lengthMot - i - 1]) {
			test = 0;
		}
	}
	if (test == 1) {
		printf("\nC'est un palindrome");
	}
	else {
		printf("\nCe n'est pas un palindrome");
	}
}