#include "AttackState.h"
#include "IdleState.h" 
#include <iostream>

void AttackState::enter(GameObject* entity) 
{
    entity->setCurrentFrame(0);
    entity->setTimeSinceLastFrame(0.0f);
    entity->setFrameSpeed(0.1f);

    if (entity->isPlayer())
    {
        entity->setAnimation("attack", "assets/playerAttack.png", 6);
    }
    else
    {
        entity->setAnimation("attack", "assets/npcAttack.png", 4);
    }

    std::cout << entity->getName() << " begins attacking!" << std::endl;
    

}

void AttackState::execute(GameObject* entity) 
{
    entity->updateAnimation(); // Update the attack animation

    if (entity->isAnimationComplete())
    {
        std::cout << entity->getName() << " finished attacking!" << std::endl;

        // Mark the action as complete
        entity->completeAction();

        // Transition back to IdleState
        entity->changeState(new IdleState());
    }
}

void AttackState::exit(GameObject* entity)
{
    std::cout << entity->getName() << " exits ATTACK state!" << std::endl;
}

void AttackState::draw(GameObject* entity)
{
    entity->draw();
}
