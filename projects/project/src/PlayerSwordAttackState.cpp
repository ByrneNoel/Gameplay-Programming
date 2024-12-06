#include "PlayerSwordAttackState.h"
#include "GameObject.h"

void PlayerSwordAttackState::enter(GameObject* gameObject) 
{
    gameObject->setAnimation("knight_sword_attack.png", 6); // Set sword attack animation
}

void PlayerSwordAttackState::execute(GameObject* gameObject)
{
    gameObject->updateAnimation();
    // Implement the logic for sword attack here
}

void PlayerSwordAttackState::exit(GameObject* gameObject)
{
    (void)gameObject;
}