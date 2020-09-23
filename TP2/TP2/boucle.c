#include <stdlib.h>
#include <stdio.h>



int n = 100;
int sum = 0;
int i = 0;

int main() {
	for (i = 0; i <= n; i++) {
		sum += i;
	}
	printf("sum for : %d", sum);

	i = 0;
	sum = 0;
	while (i < n) {
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
