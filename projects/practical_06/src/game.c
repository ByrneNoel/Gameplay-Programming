#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/game.h"
#include "../include/input_manager.h"
#include "../include/command.h"

#include "../include/constants.h"

void InitGame(GameData *gameData)
{
	// Initialize window
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Command Pattern Starter Kit");

	// Initialize player and mediator
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	gameData->player = (Player){screenWidth / 2, screenHeight / 2, 100}; // Initialize player
	gameData->mediator = create_mediator(&gameData->player);

	// Initialise Input Manage
	init_input_manager();
}

void UpdateGame(GameData *gameData)
{
	// Poll input and execute command
	Command *command = NULL;
	
	switch (poll_input()) {
	
	case MOVE_UP:
		command = create_move_up_command();
		break;
	case MOVE_DOWN:
		command = create_move_down_command();
		break;
	case MOVE_LEFT:
		command = create_move_left_command();
		break;
	case MOVE_RIGHT:
		command = create_move_right_command();
		break;
	case FIRE:
		command = create_fire_command();
		break;
	case JUMP:
		command = create_jump_command();
		break;
	case RUN:
		command = create_run_command();
		break;
	case CROUCH:
		command = create_crouch_command();
		break;
	case ATTACK:
		command = create_attack_command();
		break;
	case SHIELD:
		command = create_shield_command();
		break;
	default:
		break;

	}

	// Execute command
	if (command) 
	{
		mediator_execute_command(gameData->mediator, command);
		free(command);
	}
}

void DrawGame(GameData *gameData)
{

	BeginDrawing();
	ClearBackground(RAYWHITE);

	// Drawing Player and Position Data
	DrawCircle(gameData->player.x, gameData->player.y, 20, RED);
	DrawText(TextFormat("(%d, %d)", gameData->player.x, gameData->player.y), gameData->player.x, gameData->player.y + 20, 20, DARKBLUE);

	EndDrawing();
}

void ExitGame(GameData *gameData)
{
	// Free the mediator if needed
	free(gameData->mediator);

	// Close the window
	CloseWindow();
}
