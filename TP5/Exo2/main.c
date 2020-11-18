#include <stdlib.h>
#include <stdio.h>
#include "tab.h"




int main() {
	TABLEAU tab = newArray();
	printf("\n\n");
	displayElements(&tab, 1, tab.size);

	for (int i = 0; i < 120; i++) {
		setElement(&tab, i, i);
	}
	printf("\n\n");
	displayElements(&tab, 1, tab.size);

	deleteElements(&tab, 1, 50);
	printf("\n\n");
	displayElements(&tab, 1, tab.size);
}

