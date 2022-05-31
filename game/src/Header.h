#pragma once
#if defined(_WIN32)
#define NOGDI           
#define NOUSER            

typedef struct tagMSG* LPMSG;

#include <windows.h>
typedef struct tagBITMAPINFOHEADER {
	LONG  biWidth;
	LONG  biHeight;

} BITMAPINFOHEADER, * PBITMAPINFOHEADER;
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <crtdbg.h>
#include <time.h> 


struct arrow_pair {
	int ele;
	bool arr;
};

int maxCheck(struct arrow_pair* atp, int maxMobile, int len);
int bmn(struct arrow_pair* atp, size_t len);
double lexTime(int* tab, size_t len);
double sjtTime(int* tab, size_t len);
void heapTimePart(int tab[], int len, int total);
double heapTime(int tab[], int len, int total);
void SJT(size_t len);
void swap(int* A, int* B);
void heap(int* arr,size_t len, size_t total);
void lex(size_t len);
void swapArr(struct arrow_pair* A, struct arrow_pair* B);
void rev(int* tab, size_t len, size_t el);
