#include "raylib.h"
#include "screens.h"

int bmn(struct arrow_pair* atp, int len) {
	//if (len == 1)
	//	return -1;
	//int maxMobile = -1;
	//if (!atp[0].arr && atp[0].ele > atp[1].ele)
	//	maxMobile = 0;
	//for (int i = 1; i != len - 1; i++) {
	//	if (atp[i].arr && atp[i].ele > atp[i - 1].ele) {
	//		maxMobile = maxCheck(atp, maxMobile, i);
	//	}
	//	if (!atp[i].arr && atp[i].ele > atp[i + 1].ele) {
	//		maxMobile = maxCheck(atp, maxMobile, i);
	//	}
	//}
	//if (atp[len - 1].arr && atp[len - 1].ele > atp[len - 2].ele)
	//	maxMobile = maxCheck(atp, maxMobile, len - 1);
	//return maxMobile == -1 ? -1 : atp[maxMobile].ele;
	int n = -1;
	for (int i = 0; i != len; i++) {
		int num = atp[i].ele;
		int arr = atp[i].arr;
		if (i == 0) {
			if (!arr && (num > atp[i + 1].ele))
				if (num > n)
					n = num;
		}
		else if (i != len - 1) {
			if((arr && (num > atp[i -1].ele)) || (!arr && (num > atp[i+1].ele)))
				if(num > n)
					n = num;
		}
		else {
			if (arr && (num > atp[i - 1].ele))
				if (num > n)
					n = num;
		}

	}
	return n;
}

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