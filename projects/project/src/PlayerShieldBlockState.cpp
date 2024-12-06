#include "PlayerShieldBlockState.h"
#include "GameObject.h"

void PlayerShieldBlockState::enter(GameObject* gameObject)
{
    gameObject->setAnimation("playerBlock.png", 2); // Set shield block animation
}

void PlayerShieldBlockState::execute(GameObject* gameObject) 
{
    gameObject->updateAnimation();
    // Implement the logic for shield block here
}

void PlayerShieldBlockState::exit(GameObject* gameObject) 
{
    gameObject->resetAnimation();
}
