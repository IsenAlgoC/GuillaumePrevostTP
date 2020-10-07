#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main() {
	char mot[20];
	char tom[20];
	char letters_min[] = "azertyuiopmlkjhgfdsqwxcvbn";
	char letters_maj[] = "AZERTYUIOPMLKJHGFDSQWXCVBN";
	int lengthMot = 0;

	// maj + 32 => min
	printf("\nEntrer un mot : ");
	scanf_s("%s", &mot, 20);

	lengthMot = strlen(mot);

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

	int test = 1;
	for (int i = 0; i < lengthMot / 2; i++) {
		if (mot[i] != mot[lengthMot - i - 1]) {
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