#include <stdio.h>

int main()
{
	int angka[1000], i, a, jumlahPrima = 0;

	for (i = 0; i < 1000; i++) {
		angka[i] = 1;
	}
	
	for (i = 1; i < 1000; i++) {
		if (angka[i] == 1 && i != 1) {
			for (a = i; a <= 1000; a++) {
				if (a % i == 0 && a != i) {
					angka[a] = 0;
                }
			}
		}
	}

	for ( i = 2; i < 1000; i++ ) {
		if (angka[i] == 1 ) {
			++jumlahPrima;
		} 

	} 
	printf( "Angka prima dari 1 - 1000 yaitu sejumlah %d bilangan.\n", jumlahPrima );
	return 0; 
}