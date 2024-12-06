#include "PlayerMagicState.h"
#include "GameObject.h"

#include "State.h"

void PlayerMagicState::enter(GameObject* gameObject) 
{
    
    gameObject->setAnimation("playerAttack.png", 5);
    
}

void PlayerMagicState::execute(GameObject* gameObject) 
{
    
    if (gameObject->getHealth() > 0) 
    {
        gameObject->castMagic();
    }
}

void PlayerMagicState::exit(GameObject* gameObject) 
{
    
    gameObject->resetAnimation();
}
