#include <stdlib.h>
#include <stdio.h>


int main() {
	char phrase[1024];
	float numWords = 1;
	float sum = 0;

	printf("Votre phrase : ");
	gets_s(phrase, 1024);

	for(int i=0; i<1024; i++){
		if (phrase[i] == ' ') {
			numWords += 1;
		}
		else {
			if (phrase[i] != -2) {
				sum += 1;
			}
		}
	}
	sum--;
	printf("\nNombre de mots : %.0f", numWords);
	printf("\nLongueur moyenne des mots : %.2f", sum / numWords);
}
