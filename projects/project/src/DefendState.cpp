#include "DefendState.h"
#include "IdleState.h"
#include <iostream>

void DefendState::enter(GameObject* entity)
{
    entity->setCurrentFrame(0);
    entity->setTimeSinceLastFrame(0.0f);
    entity->setFrameSpeed(0.175f);

    if (entity->isPlayer())
    {
        entity->setAnimation("defend", "assets/playerBlock.png", 2);
    }
    else {
        entity->setAnimation("defend", "assets/npcHit.png", 1);
    }

    std::cout << entity->getName() << " raises defenses!" << std::endl;
    entity->setDefending(true); //  no damage is taken this turn.
}

void DefendState::execute(GameObject* entity)
{
    entity->updateAnimation();

   
    if (entity->isAnimationComplete())
    {
        // Action is done now that the animation is over.
        entity->completeAction();
        entity->changeState(new IdleState());
    }
}

void DefendState::exit(GameObject* entity)
{
    std::cout << entity->getName() << " finished defending action!" << std::endl;
    
}

void DefendState::draw(GameObject* entity)
{
    entity->draw();
}
