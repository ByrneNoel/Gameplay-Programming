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
#include "AudioResources.h"
#include <iostream>
#include <vector>
#include <algorithm>    // For std::remove_if
#include "ExplosionEffect.h"


const int screenWidth = 800;
const int screenHeight = 600;

enum class Turn
{
    PLAYER,
    NPC
};

Sound swordSlash;
Sound magicCast;

Texture2D explosionTexture;
std::vector<ExplosionEffect> explosions;

double npcTurnStartTime = 0.0;


int main() 
{
    InitWindow(screenWidth, screenHeight, "Knight vs Beastlord Satyr");

    InitAudioDevice();

    // Load background music and start playing
    Music bgMusic = LoadMusicStream("assets/backgroundMusic.mp3");
    PlayMusicStream(bgMusic);
    SetMusicVolume(bgMusic, 0.3f);

    // Load sound effects
     swordSlash = LoadSound("assets/swordSlash.mp3");
     SetSoundVolume(swordSlash, 0.4f);

     magicCast = LoadSound("assets/magicCast.wav");
     SetSoundVolume(magicCast, 0.3f);

     explosionTexture = LoadTexture("assets/explosion.png");
     
    Player player("Knight", 100, 200, 350);
    NPC beastlordSatyr("Beastlord Satyr", 100, 400, 350);
    InputHandler inputHandler;

    player.setTarget(&beastlordSatyr);
    beastlordSatyr.setTarget(&player);

    Texture2D backgroundTexture = LoadTexture("assets/background.png");

    Turn turn = Turn::PLAYER;
    bool isGameOver = false;
    std::string winner;

    bool playerDefendingReset = false;
    bool npcDefendingReset = false;

    bool npcTurnActionSelected = false; // Tracks if NPC has chosen an action this turn

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        
        UpdateMusicStream(bgMusic);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        
        // Update explosions
        float dt = GetFrameTime();
        for (auto& expl : explosions)
        {
            expl.update(dt);
        }


        if (!isGameOver)
        {
            DrawTexture(backgroundTexture, 0, 0, WHITE);

            DrawText(TextFormat("Player Health: %d", player.getHealth()), 10, 10, 20, WHITE);
            DrawText(TextFormat("NPC Health: %d", beastlordSatyr.getHealth()), screenWidth - 200, 10, 20, WHITE);

            if (turn == Turn::PLAYER)
            {
                if (!playerDefendingReset) 
                {
                    player.setDefending(false);
                    playerDefendingReset = true; // Now we've done it once this turn
                }

                                
                if (!player.isActionComplete())
                {
                    inputHandler.handleInput(player); // Player inputs attack/defend/magic
                }
                else
                {
                    // Player finished the action
                    if (beastlordSatyr.getHealth() <= 0)
                    {
                        isGameOver = true;
                        winner = "Player Wins!";
                    }
                    else
                    {
                        player.resetAction();
                        turn = Turn::NPC;
                        npcTurnActionSelected = false; // Reset this for the NPC turn
                        npcTurnStartTime = GetTime();
                        std::cout << "Switching to NPC turn." << std::endl;
                        npcDefendingReset = false;
                    }
                }
            }
            else if (turn == Turn::NPC)
            {
                if (!npcDefendingReset)
                {
                    beastlordSatyr.setDefending(false);
                    npcDefendingReset = true;
                }

                double currentTime = GetTime();
                double elapsed = currentTime - npcTurnStartTime;

                if (elapsed < 3.0)
                {

                }

                else
                {

                    if (!beastlordSatyr.isActionComplete())
                    {
                        // Only choose a new action once
                        if (!npcTurnActionSelected)
                        {
                            beastlordSatyr.takeTurn(player);
                            npcTurnActionSelected = true;
                        }
                    }
                    else
                    {
                        // NPC finished the action
                        if (player.getHealth() <= 0)
                        {
                            isGameOver = true;
                            winner = "Beastlord Satyr Wins!";
                        }
                        else
                        {
                            beastlordSatyr.resetAction();
                            turn = Turn::PLAYER;
                            std::cout << "Switching to Player turn." << std::endl;
                            playerDefendingReset = false;
                        }
                    }


                }
            }
          


            // Update and draw game objects
            player.update();
            beastlordSatyr.update();
            player.draw();
            beastlordSatyr.draw();

            // Draw explosions last so they appear on top of characters
            for (auto& expl : explosions) 
            {
                expl.draw();
            }

            explosions.erase(std::remove_if(explosions.begin(), explosions.end(),
                [](const ExplosionEffect& e) { return !e.isActive(); }), explosions.end());
        }
        else
        {
            DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.8f));
            DrawText("Game Over!", screenWidth / 2 - 100, screenHeight / 2 - 50, 40, RED);
            DrawText(winner.c_str(), screenWidth / 2 - 100, screenHeight / 2, 30, WHITE);
            DrawText("Press [R] to Restart or [ESC] to Quit", screenWidth / 2 - 180, screenHeight / 2 + 50, 20, LIGHTGRAY);

            if (IsKeyPressed(KEY_R))
            {
                player.reset();
                beastlordSatyr.reset();
                turn = Turn::PLAYER;
                isGameOver = false;
            }
        }

        EndDrawing();
    }

    UnloadTexture(backgroundTexture);
    UnloadSound(swordSlash);
    UnloadSound(magicCast);
    UnloadTexture(explosionTexture);
    UnloadMusicStream(bgMusic);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
