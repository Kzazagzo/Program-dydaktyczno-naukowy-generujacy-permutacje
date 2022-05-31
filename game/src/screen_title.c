#include "raylib.h"
#include "screens.h"

static int finishScreen = 0;

void InitTitleScreen(void) {
    finishScreen = 0;
}

void UpdateTitleScreen(void) {
    if (IsKeyPressed(KEY_ONE)) {
        finishScreen = ALGORITHM;   
    }
    if (IsKeyPressed(KEY_TWO)) {
        finishScreen = PLOT;   
    }
}

void DrawTitleScreen(void) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GREEN);
    DrawTextEx(font, "Implementacja okienkowa", (Vector2){ 10, 10 }, font.baseSize*0.8f, 1, BLACK);
    DrawTextEx(font, "1. Algorytmy", (Vector2){ GetScreenWidth()* 0.75f, GetScreenHeight()*0.75f }, font.baseSize, 1, BLACK);
    DrawTextEx(font, "2. Wykresy", (Vector2) { GetScreenWidth() * 0.75f + 28, GetScreenHeight() * 0.75f + 32}, font.baseSize, 1, BLACK);
    DrawTextEx(font, "Esc. Wyjscie", (Vector2) { GetScreenWidth() * 0.75f + 4*2, GetScreenHeight() * 0.75f + 32*2 }, font.baseSize, 1, BLACK);
}


void UnloadTitleScreen(void){
    ;
}

int FinishTitleScreen(void) {
    return finishScreen;
}