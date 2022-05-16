#define SCREENS_H
#include "Header.h"

typedef enum GameScreen { NONE = 0, TITLE, ALGORITHM, HEAP, JT , LEX} GameScreen;

extern GameScreen currentScreen;
extern Font font;

void InitTitleScreen(void);
void UpdateTitleScreen(void);
void DrawTitleScreen(void);
void UnloadTitleScreen(void);
int FinishTitleScreen(void);


void InitAlgorithmScreen(void);
void UpdateAlgorithmScreen(void);
void DrawAlgorithmScreen(void);
void UnloadAlgorithmScreen(void);
int FinishAlgorithmScreen(void);


void InitHeapScreen(void);
void UpdateHeapScreen(void);
void DrawHeapScreen(void);
void UnloadHeapScreen(void);
int FinishHeapScreen(void);

void DrawCharacterHeap(int pos, char znak[2], int col);

void InitJtScreen(void);
void UpdateJtScreen(void);
void DrawJtScreen(void);
void UnloadJtScreen(void);
int FinishJtScreen(void);

void DrawTrianglePointer(int curLine);
void DrawCharacterJt(int pos, char znak[2]);
void DrawArrowJt(bool dir, int pos);
void DrawPermJt();
void DrawVariJt(int n, int indk, int i);

void InitLexScreen(void);
void UpdateLexScreen(void);
void DrawLexScreen(void);
void UnloadLexScreen(void);
int FinishLexScreen(void);

void DrawCharacterLex(int pos, char znak[2], int col);
void PauseLex(int curLine, int piv, int indk);
void DrawVariLex(int piv, int indk);
void DrawPermLex(int col);
