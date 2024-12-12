#include "DefendState.h"
#include "IdleState.h" 
#include <iostream>

void DefendState::enter(GameObject* entity)
{
    entity->setCurrentFrame(0);
    entity->setTimeSinceLastFrame(0.0f);
    entity->setFrameSpeed(0.2f);

    if (entity->isPlayer())
    {
        entity->setAnimation("defend", "assets/playerDefend.png", 4);
    }
    else {
        entity->setAnimation("defend", "assets/npcDefend.png", 3);
    }

    std::cout << entity->getName() << " raises defenses!" << std::endl;
    entity->setDefending(true); // Flag for reduced damage
}

void DefendState::execute(GameObject* entity)
{
    entity->updateAnimation();

    if (entity->getCurrentFrame() == entity->getFrameCount() - 1)
    {
        std::cout << entity->getName() << " finished defending!" << std::endl;
        entity->completeAction();
        entity->changeState(new IdleState());
    }
}

void DefendState::exit(GameObject* entity)
{
    std::cout << entity->getName() << " lowers defenses!" << std::endl;
    entity->setDefending(false); // Reset defending flag
}

void DefendState::draw(GameObject* entity) 
{
    entity->draw();
}
