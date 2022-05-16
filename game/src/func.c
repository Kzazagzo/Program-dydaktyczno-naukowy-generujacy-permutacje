#include "Header.h"

void swap(int* A, int* B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void rev(int* tab, size_t len, size_t el) {
	while (el < len) {
		swap(&tab[el], &tab[len]);
		len--, el++;
	}
}

void swapArr(struct arrow_pair* A, struct arrow_pair* B) {
	struct arrow_pair temp = *A;
	*A = *B;
	*B = temp;
}