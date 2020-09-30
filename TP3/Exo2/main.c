#include <stdlib.h>
#include <stdio.h>

int main() {
	unsigned int n = 2868838400;
	printf("Nb octets : %d", sizeof(n));
	printf("\nNb de bits : %d", 8*sizeof(n));

	unsigned int m = 1;
	int v = 0;
	for (int i = 0; i < 8 * sizeof(n); i++) {
		printf("\nbit %d  ", i);
		v = n & m;
		if (v != 0) {
			printf("ON");
		} else {
			printf("OFF");
		}
		m = m << 1;
	}
	printf("\nBye !");

}