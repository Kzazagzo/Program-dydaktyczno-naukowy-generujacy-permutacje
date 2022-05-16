#include "raylib.h"
#include "screens.h"

static int finishScreen = 0;

void InitLexScreen(void) {
    finishScreen = 0;
}


void UpdateLexScreen(void) {
    
}


void DrawLexScreen(void) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), LIGHTGRAY);
    DrawTextEx(font, "Porzadek leksykograficzny", (Vector2) { GetScreenWidth() * 0.25f, GetScreenHeight() * 0.01f }, font.baseSize, 1, BLACK);
   
}


void UnloadLexScreen(void) {

}

// Options Screen should finish?
int FinishLexScreen(void)
{
    return finishScreen;
}