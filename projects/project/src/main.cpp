#include "raylib.h"
#include "Player.h"
#include "NPC.h"
#include "SwordAttackCommand.h"
#include "ShieldBlockCommand.h"
#include "MagicCommand.h"
#include "InputHandler.h"
#include <iostream>

const int screenWidth = 800;
const int screenHeight = 600;

enum class Turn {
    PLAYER,
    NPC
};

int main() {
    InitWindow(screenWidth, screenHeight, "Knight vs Beastlord Satyr");

    Player player("Knight", 100, 300, 300);
    NPC beastlordSatyr("Beastlord Satyr", 50, 600, 300);

    InputHandler inputHandler;
    SwordAttackCommand swordCommand;
    ShieldBlockCommand shieldCommand;
    MagicCommand magicCommand;

    inputHandler.bindCommand(KEY_S, &swordCommand);
    inputHandler.bindCommand(KEY_D, &shieldCommand);
    inputHandler.bindCommand(KEY_M, &magicCommand);

    Turn turn = Turn::PLAYER;
    bool isGameOver = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Pause Game Logic
        if (IsKeyPressed(KEY_P)) 
        {
            while (!WindowShouldClose() && !IsKeyPressed(KEY_P))
            {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Game Paused. Press 'P' to resume.", screenWidth / 2 - 150, screenHeight / 2, 20, GRAY);
                EndDrawing();
            }
        }

        if (!isGameOver) 
        {

            if (turn == Turn::PLAYER) {
                player.handleInput();

                // Check if player's animation completes before switching turns
                if (player.getState() == PlayerState::IDLE &&
                    (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_M)))
                {
                    turn = Turn::NPC;
                }
            }
            else if (turn == Turn::NPC)
            {
                beastlordSatyr.handleAI(player);

                // Check if NPC's animation completes before switching turns
                if (beastlordSatyr.getState() == NPCState::IDLE) 
                {
                    turn = Turn::PLAYER;
                }
            }

            // Update animations
            player.updateAnimation();
            beastlordSatyr.updateAnimation();

            // Update player and NPC logic
            player.update();
            beastlordSatyr.update();

            // Game over logic
            if (player.getHealth() <= 0 || beastlordSatyr.getHealth() <= 0) 
            {
                isGameOver = true;
            }
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!isGameOver)
        {
            player.draw();
            beastlordSatyr.draw();

            DrawText(TextFormat("Player Health: %d", player.getHealth()), 10, 10, 20, BLACK);
            DrawText(TextFormat("NPC Health: %d", beastlordSatyr.getHealth()), screenWidth - 200, 10, 20, BLACK);
        }
        else
        {
            if (player.getHealth() <= 0) 
            {
                DrawText("Game Over! NPC Wins!", screenWidth / 2 - 100, screenHeight / 2, 20, RED);
            }
            else
            {
                DrawText("Victory! Player Wins!", screenWidth / 2 - 100, screenHeight / 2, 20, GREEN);
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
