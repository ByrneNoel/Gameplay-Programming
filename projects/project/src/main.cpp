#include "raylib.h"
#include "Player.h"
#include "NPC.h"
#include "AttackState.h"
#include "InputHandler.h"
#include "DeadState.h"
#include "DefendState.h"
#include "GameObject.h"
#include "IdleState.h"
#include "MagicState.h"
#include "State.h"
#include <iostream>

const int screenWidth = 800;
const int screenHeight = 600;

enum class Turn
{
    PLAYER,
    NPC
};

int main() {
    InitWindow(screenWidth, screenHeight, "Knight vs Beastlord Satyr");

    Player player("Knight", 100, 200, 350);
    NPC beastlordSatyr("Beastlord Satyr", 100, 400, 350);
    InputHandler inputHandler;

    Texture2D backgroundTexture = LoadTexture("assets/background.png");

    Turn turn = Turn::PLAYER;
    bool isGameOver = false;
    std::string winner;

    SetTargetFPS(60);

  

    while (!WindowShouldClose())
    {
      
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!isGameOver)
        {
            // Draw background
            DrawTexture(backgroundTexture, 0, 0, WHITE);

            // Display health
            DrawText(TextFormat("Player Health: %d", player.getHealth()), 10, 10, 20, BLACK);
            DrawText(TextFormat("NPC Health: %d", beastlordSatyr.getHealth()), screenWidth - 200, 10, 20, BLACK);


            // Handle turns
            if (turn == Turn::PLAYER)
            {  
                inputHandler.handleInput(player);

                if (!player.isActionComplete())
                {
                    player.resetAction(); // Reset actionComplete for the player
                    turn = Turn::NPC; // NPC's turn
                }
                else
                {
                    // Check if NPC health reaches zero
                    if (beastlordSatyr.getHealth() <= 0)
                    {
                        isGameOver = true;
                        winner = "Player Wins!";
                    }
                    else
                    {
                        turn = Turn::NPC; // NPC's turn
                        player.resetAction(); // Reset player's action state
                    }
                }
            }
            else if (turn == Turn::NPC)
            {
                if (!beastlordSatyr.isActionComplete())
                {
                    beastlordSatyr.takeTurn(player);
                }
                else
                {
                    // Check if player health reaches zero
                    if (player.getHealth() <= 0)
                    {
                        isGameOver = true;
                        winner = "Beastlord Satyr Wins!";
                    }
                    else
                    {
                        turn = Turn::PLAYER; // Back to player's turn
                        beastlordSatyr.resetAction(); // Reset NPC's action state
                    }
                }
            }

            // Update and draw game objects
            player.update();
            beastlordSatyr.update();

            player.draw();
            beastlordSatyr.draw();
        }
        else
        {
            // Game Over Screen
            DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.8f));
            DrawText("Game Over!", screenWidth / 2 - 100, screenHeight / 2 - 50, 40, RED);
            DrawText(winner.c_str(), screenWidth / 2 - 100, screenHeight / 2, 30, WHITE);
            DrawText("Press [R] to Restart or [ESC] to Quit", screenWidth / 2 - 180, screenHeight / 2 + 50, 20, LIGHTGRAY);

            // Handle restart or exit
            if (IsKeyPressed(KEY_R))
            {
                player.reset();               // Reset player state
                beastlordSatyr.reset();      // Reset NPC state
                turn = Turn::PLAYER;
                isGameOver = false;
            }
        }

        EndDrawing();
    }

    // Cleanup resources
    UnloadTexture(backgroundTexture);
    CloseWindow();

    return 0;
}