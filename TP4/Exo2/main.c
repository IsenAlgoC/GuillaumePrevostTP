#include <stdlib.h>
#include <stdio.h>

#define TAILLETAB1 20
#define SEPARATEUR '/'

int main() {
	int tab1[TAILLETAB1];
	int i;

	for (i = 0; i < TAILLETAB1; i++) {
		tab1[i] = i;
	}
	for (i = 0; i < TAILLETAB1-1; i++) {
		printf("%d %c ", tab1[i], SEPARATEUR);
	}
	printf("%d\n", tab1[TAILLETAB1 - 1]);

	int *MyPtr1 = &tab1[TAILLETAB1 - 1];
	printf("%d", *MyPtr1);

	for (i = TAILLETAB1-1; i > 0 ; i--) {
		MyPtr1 -= 1;
		printf("%d %c ", *MyPtr1, SEPARATEUR);
	}

}