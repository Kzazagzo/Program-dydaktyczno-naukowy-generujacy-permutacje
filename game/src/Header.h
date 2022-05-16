#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <crtdbg.h>
#include <limits.h>

struct arrow_pair {
	int ele;
	bool arr;
};

void swap(int* A, int* B);
void heap(int* tab, size_t len, size_t total);
void swapArr(struct arrow_pair* A, struct arrow_pair* B);
void SJT( size_t len);
void rev(int* tab, size_t len, size_t el);
