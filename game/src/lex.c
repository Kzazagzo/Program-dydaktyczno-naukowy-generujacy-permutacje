#include "raylib.h"
#include "screens.h"

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

double lexTime(int* tab, size_t len) {
	LARGE_INTEGER freq;
	LARGE_INTEGER t1, t2;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&t1);
	while(1){
		if (!nextP(tab, len)) {
			QueryPerformanceCounter(&t2);
			return (double)(t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart;
		}
	}
}

int lexMem() {
	return 0;
}