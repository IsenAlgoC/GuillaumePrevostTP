#include "tp4.h"
#include <stdlib.h>
#include <stdio.h>



int main() {
	HEURE HeureDebut = { 12,30 }, HeureFin = { 0,0 }, Duree = { 0,45 };
	int m = HeureDebut.minute + Duree.minute;
	HeureFin.heure += HeureDebut.heure + m/60 ;
	HeureFin.minute += m % 60;
	printf("Heure de fin : %dh%d", HeureFin.heure, HeureFin.minute);
}