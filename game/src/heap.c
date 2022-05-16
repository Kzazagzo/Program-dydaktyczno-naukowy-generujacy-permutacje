#include "Header.h"

void heap(int tab[], size_t len, size_t total) {
	if (len == 1) {
		for (size_t i = 0; i != total; i++)
			printf("%i ", tab[i]);
		printf("\n");
	}
	for (int i = 0; i != len; i++) {
		heap(tab, len - 1, total);
		if (i < len - 1)
			len % 2 == 0 ? swap(&tab[i], &tab[len - 1]) : swap(&tab[0], &tab[len - 1]);
	}
}
