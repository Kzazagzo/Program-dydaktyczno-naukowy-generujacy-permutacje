#include "raylib.h"
#include "screens.h"

static int finishScreen = 0;
static char algorithmLenght[2] = "0";
static bool feror = false;
static bool ceror = false;

void InitAlgorithmScreen(void) {
	finishScreen = 0;
}

void UpdateAlgorithmScreen(void) {
	if (IsKeyPressed(KEY_BACKSPACE)) {
		finishScreen = TITLE;
		return;
	}
	int key = GetKeyPressed();
	if (key >= 49 && key <= 57) {
		feror = false;
		ceror = false;
		itoa(key - 48, algorithmLenght, 10);
	}
	else {
		if (key >= 290 && key <= 292) {
			if (algorithmLenght[0] != '0') {
				if (IsKeyPressed(KEY_F1)) finishScreen = HEAP;
				if (IsKeyPressed(KEY_F2)) finishScreen = JT;
				if (IsKeyPressed(KEY_F3)) finishScreen = LEX;
				return;
			}
			else {
				feror = true, ceror = false;
				return;
			}
		}
		if(key != 0)
			ceror = true, feror = false;
	}
}


void DrawAlgorithmScreen(void) {
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), LIGHTGRAY);
	DrawTextEx(font, "F1. Algorytm Heapa", (Vector2) { GetScreenWidth() * 0.01f, GetScreenHeight() * 0.01f }, font.baseSize, 1, BLACK);
	DrawTextEx(font, "F2. Algorytm Johnsona-Trottera ", (Vector2) { GetScreenWidth() * 0.01f, GetScreenHeight() * 0.4f }, font.baseSize, 1, BLACK);
	DrawTextEx(font, "F3. Porzadek leksykograficzny ", (Vector2) { GetScreenWidth() * 0.01f, GetScreenHeight() * 0.8f }, font.baseSize, 1, BLACK);
	DrawTextEx(font, "Podaj dlugosc ciagu", (Vector2) { GetScreenWidth() * 0.67f, GetScreenHeight() * 0.3f }, font.baseSize * 0.8f, 1, BLACK);
	DrawRectangleLines(GetScreenWidth() * 0.74f, GetScreenHeight() * 0.4f, 120, 120, BLACK);
	DrawTextEx(font, algorithmLenght, (Vector2) { GetScreenWidth() * 0.775f, GetScreenHeight() * 0.415f }, font.baseSize * 4.0f, 1, BLACK);
	if(feror)
		DrawTextEx(font, "\t\t\t\tPrzed wybraniem\nprogramu wybierz wielkosc\n\t\ttabeli z przedzialu 1-9", (Vector2) { GetScreenWidth() * 0.66f, GetScreenHeight() * 0.72f }, font.baseSize * 0.6f, 1, RED);
	if(ceror)
		DrawTextEx(font, "\t\t\t\tTen znak nie jest\n\t\t\t\t\tprzedzialu 1-9", (Vector2) { GetScreenWidth() * 0.66f, GetScreenHeight() * 0.72f }, font.baseSize * 0.6f, 1, RED);
}


void UnloadAlgorithmScreen(void) {
	;
}

int AppendAlgorithmLenght(void) {
	return algorithmLenght[0] - '0';
}

int FinishAlgorithmScreen(void) {
	return finishScreen;
}

