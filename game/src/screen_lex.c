#include "raylib.h"
#include "screens.h"

static int curLn = 1;
static int finishScreen = 0;
static bool cp = true;
static bool end = false;

void InitLexScreen(void) {
	finishScreen = 0;
	curLn = 1;
	int* arr = NULL;
	cp = true;
	end = false;
}


void UpdateLexScreen(void) {
	int* arr = malloc(sizeof(int) * AppendAlgorithmLenght());
	for (int i = 0; i != AppendAlgorithmLenght(); i++)
		arr[i] = i + 1;
	lex(arr, AppendAlgorithmLenght());
	cp = false;
	free(arr);
	finishScreen = TITLE;
}


void DrawLexScreen(void) {
	if (cp) {
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), LIGHTGRAY);
		DrawTextEx(font, "Porzadek leksykograficzny", (Vector2) { GetScreenWidth() * 0.25f, GetScreenHeight() * 0.01f }, font.baseSize, 1, BLACK);
		DrawTextEx(font, "void lex(int* arr, size_t len)\n"
			"\t\t\twhile (1)\n"
			"\t\t\t\t\tint piv = len - 1;\n"
			"\t\t\t\t\twhile(arr[piv-1] >= arr[piv] && piv>0) piv--; \n"
			"\t\t\t\t\tif(piv == 0) break; \n"
			"\t\t\t\t\tint indk = len - 1;\n"
			"\t\t\t\t\twhile (arr[piv - 1] >= arr[indk]) indk--;\n"
			"\t\t\t\t\tswap(&arr[indk], &arr[piv - 1]);\n"
			"\t\t\t\t\trev(arr, len - 1, piv);\n"
			"\t\t\t\t\tGetOutput();\n"
			, (Vector2) { GetScreenWidth() * 0.01f, GetScreenHeight() * 0.15f }, font.baseSize * 0.5f, 1, BLACK);
		DrawTriangleLines((Vector2) { GetScreenWidth() * 0.009f + 16, GetScreenHeight() * 0.15f + 24 * curLn }, (Vector2) { GetScreenWidth() * 0.009f + 16, GetScreenHeight() * 0.15f + 12 + 24 * curLn }, (Vector2) { GetScreenWidth() * 0.009f + 24 + 4, GetScreenHeight() * 0.15f + 24 * curLn + 6 }, RED);
	}
	
}

void DrawPermLex(int* arr, int col) {
	for (int i = 0; i != AppendAlgorithmLenght(); i++) {
		char znak[2] = { arr[i] + 48,'\0' };
		DrawCharacterLex(i, znak, col);
	}
}

void DrawVariLex(int piv, int indk) {
	char iPiv[2] = { piv + 48, '\0' };
	DrawTextEx(font, iPiv, (Vector2) { 517, 100 }, 3.0f * font.baseSize, 1, BLACK);
	DrawTextEx(font, "int piv", (Vector2) { 495, 70 }, 1.0f * font.baseSize, 1, BLACK);
	DrawRectangleLines(500, 100, 80, 80, BLACK);
	if (indk != -1) {
		char iIndk[2] = { indk + 48, '\0' };
		DrawTextEx(font, iIndk, (Vector2) { 665, 100 }, 3.0f * font.baseSize, 1, BLACK);
		DrawTextEx(font, "int indk", (Vector2) { 635, 70 }, 1.0f * font.baseSize, 1, BLACK);
		DrawRectangleLines(650, 100, 80, 80, BLACK);
	}
}

void PauseLex(int* arr, int curLine, int piv, int indk) {
	curLn = curLine;
	if (!end) {
		while (1) {
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawLexScreen();
			DrawPermLex(arr, curLine);
			DrawVariLex(piv, indk);
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

void DrawCharacterLex(int pos, char znak[2], int col) {
	DrawLineV((Vector2) { (2 * pos + 1)* GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.8f }, (Vector2) { 30 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.8f }, BLACK);
	if (col == 9)
		DrawTextEx(font, znak, (Vector2) { (2 * pos + 1)* GetScreenWidth() / (2 * AppendAlgorithmLenght()) - 5 + pos * 0.5f, GetScreenHeight() * 0.69f }, font.baseSize * 2.0f, 1, GREEN);
	else
		DrawTextEx(font, znak, (Vector2) { (2 * pos + 1)* GetScreenWidth() / (2 * AppendAlgorithmLenght()) - 5 + pos * 0.5f, GetScreenHeight() * 0.69f }, font.baseSize * 2.0f, 1, BLACK);
}

void UnloadLexScreen(void) {
	;
}

int FinishLexScreen(void) {
    return finishScreen;
}


void lex(int* arr,size_t len) {
	while (1) {
		int piv = len - 1;
		PauseLex(arr, 2, piv, -1);
		while (arr[piv - 1] >= arr[piv] && piv > 0) { // ZnajdŸ od koñca malej¹cy ci¹g i wybierz liczbê 1 liczbê przed nim
			piv--;
			PauseLex(arr, 3, piv, -1);
		}
		if (piv == 0) {
			PauseLex(arr, 4, piv, -1);
			break;
		}
		int indk = len - 1;
		PauseLex(arr, 5, piv, indk);
		while (arr[piv - 1] >= arr[indk]) {  // Zamieñ go z maksymalnie prawym najmiej rosn¹cym elementem
			indk--;
			PauseLex(arr, 6, piv, indk);
		}
		swap(&arr[indk], &arr[piv - 1]);
		PauseLex(arr, 7, piv, indk);
		rev(arr, len - 1, piv); // Odwróæ ci¹g najmniejszych elementów
		PauseLex(arr, 8, piv, indk);
		PauseLex(arr, 9, piv, indk);
		for (int i = 0; i != AppendAlgorithmLenght(); i++)
			printf("%i ", arr[i]);
		printf("\n");
	}
}
