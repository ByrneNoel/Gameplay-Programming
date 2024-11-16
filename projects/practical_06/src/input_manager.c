#include <raylib.h>
#include "../include/command.h"
#include "../include/input_manager.h"

// Sample input initialization
void init_input_manager()
{
    // Initialize input sources (keyboard, controller, etc.)
}

// Sample input polling
CommandType poll_input()
{
    // Check keyboard input

    if (IsKeyPressed(KEY_W)) 
    {
        return MOVE_UP;
    }
    else if (IsKeyPressed(KEY_S)) 
    {
        return MOVE_DOWN;
    }
    else if (IsKeyPressed(KEY_A))
    {
        return MOVE_LEFT;
    }
    else if (IsKeyPressed(KEY_D))
    {
        return MOVE_RIGHT;
    }
    else if (IsKeyPressed(KEY_SPACE))
    {
        return FIRE;
    }
    else if (IsKeyPressed(KEY_UP)) 
    {
        return JUMP;
    }
    else if (IsKeyPressed(KEY_R))
    {
        return RUN;
    }
    else if (IsKeyPressed(KEY_C))
    {
        return CROUCH;
    }
    else if (IsKeyPressed(KEY_F)) 
    {
        return ATTACK;
    }
    else if (IsKeyPressed(KEY_V)) 
    {
        return SHIELD;
    }

    // Check controller input
    if (IsGamepadAvailable(0)) // Is Controller 0
    {
        if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_UP))
            return MOVE_UP;
        if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN))
            return MOVE_DOWN;
        if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT))
            return MOVE_LEFT;
        if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT))
            return MOVE_RIGHT;

        // Check Right Trigger
        float rightTriggerValue = GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_TRIGGER);
        if (rightTriggerValue > 0.5f)
        {
            return FIRE;
        }
    }

    return NONE; // No Input
}

void exit_input_manager()
{
    // Cleanup resources if needed
}
