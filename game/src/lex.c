#include "Header.h"

bool nextP(int* tab, size_t len) {
	bool done = false;
	int piv = len - 1;
	while (tab[piv - 1] >= tab[piv] && piv > 0) // ZnajdŸ od koñca malej¹cy ci¹g i wybierz liczbê 1 liczbê przed nim
		piv--;
	if(piv==0)
		return false;
	int indk = len - 1;
	while (tab[piv - 1] >= tab[indk])  // Zamieñ go z maksymalnie prawym najmiej rosn¹cym elementem
		indk--;
	swap(&tab[indk], &tab[piv - 1]);
	rev(tab, len - 1, piv); // Odwróæ ci¹g najmniejszych elementów
	return true;
}

void lex(int* tab, size_t len) {
	while(1){
		for (size_t i = 0; i != len; i++)
			printf("%i ", tab[i]);
		printf("\n");
		if (!nextP(tab, len))
			break;
	}
}