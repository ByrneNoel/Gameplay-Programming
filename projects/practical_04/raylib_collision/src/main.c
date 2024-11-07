#include "../raylib_starter/raylib/src/raylib.h"
#include "stdio.h"
#include <string.h>

#include "../include/game.h"
#include "../include/constants.h"

// Specific include for web build
#if defined(WEB_BUILD)
#include <emscripten/emscripten.h>
#endif

// Function to wrap the game loop
void GameLoop(void);

int main(void)
{
    // Initialize the Raylib window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Collision StarterKit GPPI");

    // Initialize Game components (now handled by InitGame in game.c)
    InitGame();

    // Web-specific loop configuration
#if defined(WEB_BUILD)
    emscripten_set_main_loop(GameLoop, 0, 1);
#else
    SetTargetFPS(60);
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        GameLoop();
    }
#endif

    // Free resources and close the game (handled by CloseGame in game.c)
    CloseGame();
    CloseWindow();

    return 0;
}

// Main game loop wrapper
void GameLoop(void)
{
    // Update game data
    UpdateGame();

    // Begin drawing and call DrawGame from game.c
    BeginDrawing();
    DrawGame();
    EndDrawing();
}
