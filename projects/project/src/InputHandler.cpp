#include "InputHandler.h"
#include "raylib.h"
#include <iostream>


void InputHandler::handleInput(GameObject& gameObject) 
{
    if (IsKeyPressed(KEY_S))
    {
        commandMap[KEY_S]->execute(gameObject);
    }
    else if (IsKeyPressed(KEY_D))
    {
        commandMap[KEY_D]->execute(gameObject);
    }
    else if (IsKeyPressed(KEY_M)) 
    {
        commandMap[KEY_M]->execute(gameObject);
    }
}

void InputHandler::bindCommand(int key, Command* command)
{
    commandMap[key] = command;
}
