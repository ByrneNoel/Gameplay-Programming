#include "IdleState.h"
#include "GameObject.h"
#include <iostream>

void IdleState::enter(GameObject* entity)
{
    entity->setCurrentFrame(0);
    entity->setTimeSinceLastFrame(0.0f);
    entity->setFrameSpeed(0.2f);


    if (entity->isPlayer()) 
    {
        entity->setAnimation("idle", "assets/playerIdel.png", 4);
    }
    else 
    {
        entity->setAnimation("idle", "assets/npcIdel.png", 2);
    }

    std::cout << entity->getName() << " enters IDLE state!" << std::endl;
}

void IdleState::execute(GameObject* entity)
{
    entity->updateAnimation();
}

void IdleState::exit(GameObject* entity)
{
    std::cout << entity->getName() << " exits IDLE state!" << std::endl;
}

void IdleState::draw(GameObject* entity) 
{
    entity->draw();
}