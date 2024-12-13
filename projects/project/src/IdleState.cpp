#include "IdleState.h"
#include "GameObject.h"
#include <iostream>

void IdleState::enter(GameObject* entity)
{
    entity->setCurrentFrame(0);
    entity->setTimeSinceLastFrame(0.0f);
    entity->setFrameSpeed(0.175f);


    if (entity->isPlayer()) 
    {
        entity->setAnimation("idle", "assets/playerIdel.png", 5);
    }
    else 
    {
        entity->setAnimation("idle", "assets/npcIdel.png", 5);
    }

    std::cout << entity->getName() << " enters IDLE state!" << std::endl;
    entity->resetAnimation();
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