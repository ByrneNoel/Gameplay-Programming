#include "DeadState.h"
#include "IdleState.h"
#include <iostream>

void DeadState::enter(GameObject* entity)
{
    entity->setCurrentFrame(0);
    entity->setTimeSinceLastFrame(0.0f);
    entity->setFrameSpeed(0.1f);

    if (entity->isPlayer()) 
    {
        entity->setAnimation("dead", "assets/playerDead.png", 6);
    }
    else {
        entity->setAnimation("dead", "assets/npcDead.png", 5);
    }

    std::cout << entity->getName() << " has died." << std::endl;
}

void DeadState::execute(GameObject* entity) 
{
    entity->updateAnimation();

    if (entity->isAnimationComplete() && entity->getHealth() > 0)
    {
        
        entity->changeState(new IdleState());
    }
}
void DeadState::exit(GameObject* entity)
{
    std::cout << entity->getName() << " is removed from the game." << std::endl;
}

void DeadState::draw(GameObject* entity)
{
    entity->draw();
}
