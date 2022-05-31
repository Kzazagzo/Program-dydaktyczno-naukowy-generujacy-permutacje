#include "raylib.h"
#include "screens.h"

static int curLn = 1;
static int finishScreen = 0;
static bool cp = true;
static bool end = false;

void InitHeapScreen(void) {
	finishScreen = 0;
	curLn = 1;
	cp = true;
	end = false;
}

void UpdateHeapScreen(void) {
	int* arr = malloc(sizeof(int) * AppendAlgorithmLenght());
	for (int i = 0; i != AppendAlgorithmLenght(); i++)
		arr[i] = i + 1;
	heap(arr, AppendAlgorithmLenght(), AppendAlgorithmLenght());
	cp = false;
	free(arr);
	finishScreen = TITLE;
}

void DrawHeapScreen(void) {
	if (cp) {
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), LIGHTGRAY);
		DrawTextEx(font, "Algorytm Heapa", (Vector2) { GetScreenWidth() * 0.36f, GetScreenHeight() * 0.01f }, font.baseSize, 1, BLACK);
		DrawTextEx(font, "void heap(int arr[], size_t len, size_t total)\n"
			"\t\t\tif (len == 1)\n"
			"\t\t\t\t\tgetOutput();\n"
			"\t\t\tfor(int i = 0; i != len; i++) \n"
			"\t\t\t\t\theap(arr, arr - 1, total); \n"
			"\t\t\t\t\tif(i < len - 1)\n"
			"\t\t\t\t\t\t\tlen % 2 == 0 ? swap(&arr[i], &arr[len - 1]) : swap(&arr[0], &arr[len - 1]);\t\t"
			, (Vector2) { GetScreenWidth() * 0.01f, GetScreenHeight() * 0.15f }, font.baseSize * 0.5f, 1, BLACK);
		DrawTriangleLines((Vector2) { GetScreenWidth() * 0.009f + 16, GetScreenHeight() * 0.15f + 24 * curLn }, (Vector2) { GetScreenWidth() * 0.009f + 16, GetScreenHeight() * 0.15f + 12 + 24 * curLn }, (Vector2) { GetScreenWidth() * 0.009f + 24 + 4, GetScreenHeight() * 0.15f + 24 * curLn + 6 }, RED);
	}
}

void DrawPermHeap(int* arr,int col) {
	for (int i = 0; i != AppendAlgorithmLenght(); i++) {
		char znak[2] = { arr[i] + 48,'\0' };
		DrawCharacterHeap(i, znak, col);
	}
}

void DrawVariHeap(int len, int i) {
	char iLen[2] = { len + 48, '\0' };
	DrawTextEx(font, iLen, (Vector2) { 517, 100 }, 3.0f * font.baseSize, 1, BLACK);
	DrawTextEx(font, "int len", (Vector2) { 495, 70 }, 1.0f * font.baseSize, 1, BLACK);
	DrawRectangleLines(500, 100, 80, 80, BLACK);
	if (i != -1) {
		char iI[2] = { i + 48, '\0' };
		DrawTextEx(font, iI, (Vector2) { 665, 100 }, 3.0f * font.baseSize, 1, BLACK);
		DrawTextEx(font, "int i", (Vector2) { 663, 70 }, 1.0f * font.baseSize, 1, BLACK);
		DrawRectangleLines(650,  100, 80, 80, BLACK);
	}
}

void PauseHeap(int* arr,int curLine, int len, int i) {
	curLn = curLine;
	if (!end) {
		while (1) {
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawHeapScreen();
			DrawPermHeap(arr, curLine);
			DrawVariHeap(len, i);
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

void DrawCharacterHeap(int pos, char znak[2], int col) {
	DrawLineV((Vector2) { (2 * pos + 1)* GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.8f }, (Vector2) { 30 + (2 * pos + 1) * GetScreenWidth() / (2 * AppendAlgorithmLenght()), GetScreenHeight() * 0.8f }, BLACK);
	if (col == 2)
		DrawTextEx(font, znak, (Vector2) { (2 * pos + 1)* GetScreenWidth() / (2 * AppendAlgorithmLenght()) - 5 + pos * 0.5f, GetScreenHeight() * 0.69f }, font.baseSize * 2.0f, 1, GREEN);
	else
		DrawTextEx(font, znak, (Vector2) { (2 * pos + 1)* GetScreenWidth() / (2 * AppendAlgorithmLenght()) - 5 + pos * 0.5f, GetScreenHeight() * 0.69f }, font.baseSize * 2.0f, 1, BLACK);
}

void UnloadHeapScreen(void) {
	;
}

int FinishHeapScreen(void) {
	return finishScreen;

}

void heap(int* arr, size_t len, size_t total) {
	PauseHeap(arr, 1, len, -1);
	if (len == 1) {
		PauseHeap(arr, 2, len, -1);
	}
	PauseHeap(arr, 3, len, -1);
	for (int i = 0; i != len; i++) {
		PauseHeap(arr, 4, len, i);
		heap(arr, len - 1, total);
		PauseHeap(arr, 5, len, i);
		if (i < len - 1) {
			PauseHeap(arr, 6, len, i);
			len % 2 == 0 ? swap(&arr[i], &arr[len - 1]) : swap(&arr[0], &arr[len - 1]);
		}
	}
}