#include <stdlib.h>
#include <stdio.h>

#define carre(x) (x) * (x)
int main() {
	int nb = 5;
	printf("carre(%d) = %d", nb, carre(nb));

	// Sans modification, carre(nb+1) renvoie 11
	// Effectivement, 5 + 1*5 + 1 = 11  : Il faut mettre les parenthèses correctement.
	printf("\ncarre(%d+1) = %d", nb, carre(nb+1));
}
