#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main() {
	unsigned char w = 192;
	unsigned char x = 168;
	unsigned char y = 129;
	unsigned char z = 10;
	int n = 24;
	unsigned float mask = 0;

	// Concaténation de w, x, y et z en une seule adresse
	int Adress = z | (y << 8) | (x << 16) | (w << 24);

	// Création du masque
	for (int i = 0; i < n; i++) {
		mask += pow(2, i);
	}
	mask = mask << (32-n);

	unsigned int LongBroad = Adress | (~mask);
	unsigned int LongReseau = Adress & mask;

	// Separation des adresses reseau et broadcast en 4 nombres chacunes
	int d = LongBroad & 255;
	LongBroad = LongBroad >> 8;
	int c = LongBroad & 255;
	LongBroad = LongBroad >> 8;
	int b = LongBroad & 255;
	LongBroad = LongBroad >> 8;
	int a = LongBroad & 255;

	int h = LongReseau & 255;
	LongReseau = LongReseau >> 8;
	int g = LongReseau & 255;
	LongReseau = LongReseau >> 8;
	int f = LongReseau & 255;
	LongReseau = LongReseau >> 8;
	int e = LongReseau & 255;


	printf("\nAdresse IPv4 : %u.%u.%u.%u/%d", w, x, y, z, n);
	printf("\nAdresse Reseau : %u.%u.%u.%u", e, f, g, h);
	printf("\nAdresse Broadcast : %u.%u.%u.%u\n", a, b, c, d);

}