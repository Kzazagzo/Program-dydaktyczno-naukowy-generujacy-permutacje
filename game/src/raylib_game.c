#include "raylib.h"
#include "screens.h"


GameScreen currentScreen = 0;
Font font = { 0 };

static const int screenWidth = 800;
static const int screenHeight = 450;

static float transAlpha = 0.0f;
static bool onTransition = false;
static bool transFadeOut = false;
static int transFromScreen = -1;
static int transToScreen = -1;

static void ChangeToScreen(int screen);

static void TransitionToScreen(int screen);
static void UpdateTransition(void);
static void DrawTransition(void);

static void UpdateDrawFrame(void);

int main(void) {
	InitWindow(screenWidth, screenHeight, "Permutacje");

	font = LoadFontEx("resources/Pixellari.ttf", 32, 0, NULL);

	currentScreen = TITLE;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		UpdateDrawFrame();
	}

	switch (currentScreen) {
	case TITLE: UnloadTitleScreen(); break;
	case ALGORITHM: UnloadAlgorithmScreen(); break;
	case HEAP: UnloadHeapScreen(); break;
	case JT: UnloadJtScreen(); break;
	case LEX: UnloadLexScreen(); break;
	default: break;
	}

	UnloadFont(font);

	CloseWindow();
	return 0;
}

static void ChangeToScreen(int screen) {
	switch (currentScreen) {
	case TITLE: UnloadTitleScreen(); break;
	case ALGORITHM: UnloadAlgorithmScreen(); break;
	case HEAP: UnloadHeapScreen(); break;
	case JT: UnloadJtScreen(); break;
	case LEX: UnloadLexScreen(); break;
	default: break;
	}

	switch (screen) {
	case TITLE: InitTitleScreen(); break;
	case ALGORITHM: InitAlgorithmScreen(); break;
	case HEAP: InitHeapScreen(); break;
	case JT: InitJtScreen(); break;
	case LEX: InitLexScreen(); break;
	default: break;
	}

	currentScreen = screen;
}

static void TransitionToScreen(int screen) {
	onTransition = true;
	transFadeOut = false;
	transFromScreen = currentScreen;
	transToScreen = screen;
	transAlpha = 0.0f;
}

static void UpdateTransition(void) {
	if (!transFadeOut) {
		transAlpha += 0.05f;

		if (transAlpha > 1.01f) {
			transAlpha = 1.0f;
			// Unload current screen
			switch (transFromScreen) {
			case TITLE: UnloadTitleScreen(); break;
			case ALGORITHM: UnloadAlgorithmScreen(); break;
			case HEAP: UnloadHeapScreen(); break;
			case JT: UnloadJtScreen(); break;
			case LEX: UnloadLexScreen(); break;
			default: break;
			}

			// Load next screen
			switch (transToScreen) {
			case TITLE: InitTitleScreen(); break;
			case ALGORITHM: InitAlgorithmScreen(); break;
			case HEAP: InitHeapScreen(); break;
			case JT: InitJtScreen(); break;
			case LEX: InitLexScreen(); break;
			default: break;
			}

			currentScreen = transToScreen;

			// Activate fade out effect to next loaded screen
			transFadeOut = true;
		}
	}
	else   // Transition fade out logic
	{
		transAlpha -= 0.02f;

		if (transAlpha < -0.01f)
		{
			transAlpha = 0.0f;
			transFadeOut = false;
			onTransition = false;
			transFromScreen = -1;
			transToScreen = -1;
		}
	}
}

// Draw transition effect (full-screen rectangle)
static void DrawTransition(void)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
}

// Update and draw game frame
static void UpdateDrawFrame(void) {
	if (!onTransition) {
		switch (currentScreen) {
		case TITLE:
		{
			UpdateTitleScreen();

			if (FinishTitleScreen() == 1)
				TransitionToScreen(ALGORITHM);
			// else if (FinishTitleScreen() == 2) 
			 //    TransitionToScreen(HEAP);     // TODO WYKRESY

		}
		break;
		case ALGORITHM:
		{
			UpdateAlgorithmScreen();
			if (FinishAlgorithmScreen() == HEAP)
				TransitionToScreen(HEAP);
			if (FinishAlgorithmScreen() == JT)
				TransitionToScreen(JT);
			if (FinishAlgorithmScreen() == LEX)
				TransitionToScreen(LEX);
			if (FinishAlgorithmScreen() == TITLE)
				TransitionToScreen(TITLE);

			break;
		}
		case HEAP:
		{
			UpdateHeapScreen();
			if (FinishHeapScreen() == ALGORITHM)
				TransitionToScreen(ALGORITHM);
			if (FinishHeapScreen() == TITLE)
				TransitionToScreen(TITLE);

		} break;
		case JT: {
			UpdateJtScreen();
			if (FinishJtScreen() == ALGORITHM)
				TransitionToScreen(ALGORITHM);
			if (FinishJtScreen() == TITLE)
				TransitionToScreen(TITLE);

		case LEX: {
			UpdateLexScreen();
			if (FinishLexScreen() == ALGORITHM)
				TransitionToScreen(ALGORITHM);
			if (FinishLexScreen() == TITLE)
				TransitionToScreen(TITLE);
		}
		} break;
		default:
			break;
		}
	}
	else
		UpdateTransition();
	BeginDrawing();
	ClearBackground(RAYWHITE);
	switch (currentScreen) {
	case TITLE: DrawTitleScreen(); break;
	case ALGORITHM: DrawAlgorithmScreen(); break;
	case HEAP: DrawHeapScreen(); break;
	case JT: DrawJtScreen(); break;
	case LEX: DrawLexScreen(); break;
	default: break;
	}
	if (onTransition)
		DrawTransition();
	EndDrawing();
}
