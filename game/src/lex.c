#include "Header.h"

bool nextP(int* tab, size_t len) {
	bool done = false;
	int piv = len - 1;
	while (tab[piv - 1] >= tab[piv] && piv > 0) // Znajd� od ko�ca malej�cy ci�g i wybierz liczb� 1 liczb� przed nim
		piv--;
	if(piv==0)
		return false;
	int indk = len - 1;
	while (tab[piv - 1] >= tab[indk])  // Zamie� go z maksymalnie prawym najmiej rosn�cym elementem
		indk--;
	swap(&tab[indk], &tab[piv - 1]);
	rev(tab, len - 1, piv); // Odwr�� ci�g najmniejszych element�w
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