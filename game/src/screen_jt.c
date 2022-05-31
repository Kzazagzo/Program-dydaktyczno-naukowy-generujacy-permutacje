#include "raylib.h"
#include "screens.h"

static int finishScreen = 0;
static int curLn = 1;
static bool cp = true;
static bool end = false;
static struct arrow_pair* atp;


void InitJtScreen(void) {
	curLn = 1;
	cp = true;
	end = false;
    finishScreen = 0;
	atp = malloc(sizeof(struct arrow_pair) * AppendAlgorithmLenght());
	for (int i = 0; i != AppendAlgorithmLenght(); i++) {
		atp[i].ele = i + 1;
		atp[i].arr = true;
	}
}


void UpdateJtScreen(void) {
	SJT(AppendAlgorithmLenght());
	cp = false;
	finishScreen = TITLE;
	free(atp);
}


void DrawJtScreen(void) {
	if (cp) {
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), LIGHTGRAY);
		DrawTextEx(font, "Algorytm Johnsona-Trottera", (Vector2) { GetScreenWidth() * 0.25f, GetScreenHeight() * 0.01f }, font.baseSize, 1, BLACK);
		DrawTextEx(font, "void SJT(struct SJT apt[], size_t len)\n"
			"\t\t\twhile(n != -1)\n"
			"\t\t\t\t\tfor(int i = 0; i != len; i++)  \n"
			"\t\t\t\t\t\t\tint indk = i; \n"
			"\t\t\t\t\t\t\tif(atp[i].arr) indk--;\n"
			"\t\t\t\t\t\t\telse indk++;\n"
			"\t\t\t\t\t\t\tswapArr(&atp[i], &atp[indk]); break;\n"
			"\t\t\t\t\tfor(int i = 0; i != len; i++) \n"
			"\t\t\t\t\t\t\tif (atp[i].ele > n) atp[i].arr = !atp[i].arr;\n"
			"\t\t\t\t\tGetOutput();\n"
			"\t\t\t\t\tn = nbm(atp, len);"
			, (Vector2) { GetScreenWidth() * 0.01f, GetScreenHeight() * 0.15f }, font.baseSize * 0.5f, 1, BLACK);
		DrawTriangleLines((Vector2) { GetScreenWidth() * 0.009f + 16, GetScreenHeight() * 0.15f + 24 * curLn }, (Vector2) { GetScreenWidth() * 0.009f + 16, GetScreenHeight() * 0.15f + 12 + 24 * curLn }, (Vector2) { GetScreenWidth() * 0.009f + 24 + 4, GetScreenHeight() * 0.15f + 24 * curLn + 6 }, RED);
	}
}

void DrawPermJt(int col) {
	for (int i = 0; i != AppendAlgorithmLenght(); i++) {
		char znak[2] = { atp[i].ele + 48,'\0' };
		DrawCharacterJt(i, znak, col);
		DrawArrowJt(atp[i].arr, i);
	}
}

void DrawVariJt(int n, int indk, int i) {
	char nS[2] = { n + 48, '\0' };
	DrawTextEx(font, nS, (Vector2) { 515, 100 }, 3.0f * font.baseSize, 1, BLACK);
	DrawTextEx(font, "int n", (Vector2) { 510, 70 }, 1.0f * font.baseSize, 1, BLACK);
	DrawRectangleLines(500,100,80,80,BLACK);
	if (indk != -1) {
		char iS[2] = { indk + 48, '\0' };
		DrawTextEx(font, nS, (Vector2) { 665, 100 }, 3.0f * font.baseSize, 1, BLACK);
		DrawTextEx(font, "int indk", (Vector2) { 640, 70 }, 1.0f * font.baseSize, 1, BLACK);
		DrawRectangleLines(650, 100, 80, 80, BLACK);
	}
	if (i != -1) {
		char iI[2] = { i + 48, '\0' };
		DrawTextEx(font, iI, (Vector2) { 595, 220 }, 3.0f * font.baseSize, 1, BLACK);
		DrawTextEx(font, "int i", (Vector2) { 590, 190 }, 1.0f * font.baseSize, 1, BLACK);
		DrawRectangleLines(580, 220, 80, 80, BLACK);
	}
}


void PauseJt(int curLine, int n, int indk, int i) {
	curLn = curLine;
	if (!end) {
		while (1) {
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawJtScreen();
			DrawPermJt(curLine);
			DrawVariJt(n, indk, i);
			EndDrawing();
			if (IsKeyDown(KEY_F10)) {
				break;
			}
			if (IsKeyPressed(KEY_F11)) {
				break;
			}
			if (IsKeyPressed(KEY_BACKSPACE)) {
				end = true;
				break;
			}
		}
	}
}

void DrawCharacterJt(int pos, char znak[2], int col) {
	DrawLineV((Vector2) { (2 * pos + 1)* GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.9f }, (Vector2) { 30 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.9f }, BLACK);
	if (col == 9) 
		DrawTextEx(font, znak, (Vector2) { (2 * pos + 1)* GetScreenWidth() / (2 * AppendAlgorithmLenght()) - 5 + pos * 0.5f, GetScreenHeight() * 0.79f }, font.baseSize * 2.0f, 1, GREEN);
	else 
		DrawTextEx(font, znak, (Vector2) { (2 * pos + 1)* GetScreenWidth() / (2 * AppendAlgorithmLenght()) - 5 + pos * 0.5f, GetScreenHeight() * 0.79f }, font.baseSize * 2.0f, 1, BLACK);
}

void DrawArrowJt(int dir, int pos) {
	if (dir) {
		DrawLineV((Vector2) { 5 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.78f }, (Vector2) { 25 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.78f }, BLACK);
		DrawLineV((Vector2) { 5 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.78f }, (Vector2) { 15 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.77f }, BLACK);
		DrawLineV((Vector2) { 5 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.78f }, (Vector2) { 15 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.79f }, BLACK);
	}
	else {
		DrawLineV((Vector2) { 5 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.78f }, (Vector2) { 25 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.78f }, BLACK);
		DrawLineV((Vector2) { 25 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.78f }, (Vector2) { 15 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.77f }, BLACK);
		DrawLineV((Vector2) { 25 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.78f }, (Vector2) { 15 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.79f }, BLACK);
	}
}

void UnloadJtScreen(void) {
	;
}

int FinishJtScreen(void) {
    return finishScreen;
}


// true = ← or false = →

// Liczba jest mobila jeżeli wskazuje strzałką na większą od siebie
// 1. Znajdź największą mobilną liczbę
// 2. Zmień najwięszką mobilbą z tą na którą wskazuję
// 3. Zmień kierunek strzałki liczb większych niż n

void SJT(size_t len) {
	int n = len;
	while (n != -1) {
		PauseJt(1, n, -1, -1);
		for (int i = 0; i != len; i++) {
			PauseJt(2, n, -1, i);
			if (atp[i].ele == n) {
				int indk = i;
				PauseJt(3, n, indk, i);
				if (atp[i].arr) {
					indk--;
					PauseJt(4, n, indk, i);
				}
				else {
					indk++;
					PauseJt(5, n, indk, i);
				}
				swapArr(&atp[i], &atp[indk]);
				PauseJt(6, n, indk, i);
				break;
			}
		}
		PauseJt(7, n, -1, -1);
		for (int i = 0; i != len; i++) {
			if (atp[i].ele > n)
				atp[i].arr = !atp[i].arr;
			PauseJt(8, n, -1, i);
		}
		PauseJt(9, n, -1, -1);
		n = bmn(atp, len); 
		PauseJt(10,n, -1, -1);
		if (end)
			break;
	}
}