#include "raylib.h"
#include "screens.h"

void heapTimePart(int tab[], int len, int total) {
	if (len == 1)
		return;
	for (int i = 0; i != len; i++) {
		heapTimePart(tab, len - 1, total);
		len % 2 == 0 ? swap(&tab[i], &tab[len - 1]) : swap(&tab[0], &tab[len - 1]);
	}
}


double heapTime(int tab[], int len, int total) {
	LARGE_INTEGER freq;
	LARGE_INTEGER t1, t2;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&t1);
	heapTimePart(tab, len, total);
	QueryPerformanceCounter(&t2);
	return (double)(t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart;
}

int heapMem() {
	return 0;
}