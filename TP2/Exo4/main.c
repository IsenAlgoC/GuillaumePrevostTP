#include <stdlib.h>
#include <stdio.h>
#include <time.h>



int main() {
	srand(time(NULL));
	int n = rand();
	int a = -1;
	int i = 0;

	while(a!=n){
		printf("Votre nombre : ");
		scanf_s("%d", &a);
		i++;
		if (a > n) {
			printf("Trop grand\n");
		} 
		if(a<n) {
			printf("Trop petit\n");
		}
	}
	printf("\nBravo !\nVotre score est de %d",i);
}
