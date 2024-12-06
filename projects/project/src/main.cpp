#include "raylib.h"
#include "Player.h"
#include "NPC.h"
#include "SwordAttackCommand.h"
#include "ShieldBlockCommand.h"
#include "MagicCommand.h"
#include "InputHandler.h"
#include "AIState.h"
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
    NPC beastlordSatyr("Beastlord Satyr", 600, 300);

    InputHandler inputHandler;
    SwordAttackCommand swordCommand;
    ShieldBlockCommand shieldCommand;
    MagicCommand magicCommand;

    inputHandler.bindCommand(KEY_S, &swordCommand);
    inputHandler.bindCommand(KEY_D, &shieldCommand);
    inputHandler.bindCommand(KEY_M, &magicCommand);

    Turn turn = Turn::PLAYER;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (turn == Turn::PLAYER)
        {
            player.handleInput();

            if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_M))
            {
                turn = Turn::NPC;
            }
        }
        else if (turn == Turn::NPC)
        {
            beastlordSatyr.attack(player);
            turn = Turn::PLAYER;
        }

        player.update();
        beastlordSatyr.update();

        if (player.getHealth() <= 0 || beastlordSatyr.getHealth() <= 0)
        {
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        player.draw();
        beastlordSatyr.draw();

        DrawText(TextFormat("Player Health: %d", player.getHealth()), 10, 10, 20, BLACK);
        DrawText(TextFormat("NPC Health: %d", beastlordSatyr.getHealth()), screenWidth - 200, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
