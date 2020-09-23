#include <stdlib.h>
#include <stdio.h>


int depassement(int number) {
	int i = 0;
	int sum = 0;
	while (65535 - sum >= i) {
		i += 1;
		sum += i;
	}	// i = 361 : dernière valeur possible avant dépassement
	printf("%d", i);
	if (number > i) { 
		return 1; 
	} else {
		return 0;
	}
}


int main() {
	int n = 1000;
	unsigned short int sum = 0;
	int i = 0;

	while (depassement(n)) {
		printf("Entrer n : ");
		scanf_s("%hu", &n);
	} 


	printf("valeur de n : %d", n);
	for (i = 0; i <= n; i++) {
		sum += i;
	}
	printf("\nsum for : %d", sum);

	i = 0;
	sum = 0;
	while (i < n && 65535-sum >= i) {	// boucle modifiée pour eviter le dépassement
		i += 1;
		sum += i;
	}
	printf("\nsum while : %d", sum);

	i = 0;
	sum = 0;
	do {
		i += 1;
		sum += i;
	} while (i < n);
	printf("\nsum do while : %d", sum);



}
