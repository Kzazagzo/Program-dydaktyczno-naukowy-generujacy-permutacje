#include "raylib.h"
#include "screens.h"
// true = ← or false = →

// Liczba jest mobila jeżeli wskazuje strzałką na większą od siebie
// 1. Znajdź największą mobilną liczbę
// 2. Zmień najwięszką mobilbą z tą na którą wskazuję
// 3. Zmień kierunek strzałki liczb większych niż n

double sjtTime(int* tab, int len) {
	struct arrow_pair* atp = malloc(sizeof(struct arrow_pair) * len);
	for (int i = 0; i != len; i++) {
		atp[i].ele = tab[i];
		atp[i].arr = true;
	}
	LARGE_INTEGER freq;
	LARGE_INTEGER t1, t2;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&t1);
	int n = len;
	if (len != 1) {
		while (n != -1) {
			for (int i = 0; i < len; i++) {
				if (atp[i].ele == n) {
					int indk;
					if (atp[i].arr)
						indk = i - 1;
					else
						indk = i + 1;
					swapArr(&atp[i], &atp[indk]);
					break;
				}
			}
			for (int i = 0; i != len; i++) {
				if (atp[i].ele > n)
					atp[i].arr = !atp[i].arr;
			}
			n = bmn(atp, len);
		}
	}
	free(atp);
	QueryPerformanceCounter(&t2);
	return (double)(t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart;
}

int sjtMem(int n) {
	return sizeof(struct arrow_pair) * n;
}