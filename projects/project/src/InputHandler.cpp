#include "InputHandler.h"
#include "AttackState.h"
#include "DefendState.h"
#include "MagicState.h"
#include <iostream>

void InputHandler::handleInput(Player& player) 
{
    if (IsKeyPressed(KEY_S)) // Sword attack
    { 
        std::cout << "Key 'S' pressed: Sword Attack!" << std::endl;
        player.changeState(new AttackState());
    }
    else if (IsKeyPressed(KEY_D)) // Defend
    { 
        std::cout << "Key 'D' pressed: Defend!" << std::endl;
        player.changeState(new DefendState());
    }
    else if (IsKeyPressed(KEY_M)) // Magic
    { 
        std::cout << "Key 'M' pressed: Magic!" << std::endl;
        player.changeState(new MagicState());
    }
}
