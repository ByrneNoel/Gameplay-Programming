#include "MagicState.h"
#include "IdleState.h"

void MagicState::enter(GameObject* entity) 
{
    entity->setCurrentFrame(0);
    entity->setTimeSinceLastFrame(0.0f);
    entity->setFrameSpeed(0.15f);


    if (entity->isPlayer()) 
    {
        entity->setAnimation("magic", "assets/player_magic.png", 8);
    }
    else 
    {
        entity->setAnimation("magic", "assets/npc_magic.png", 6);
    }

    std::cout << entity->getName() << " begins casting magic!" << std::endl;
}

void MagicState::execute(GameObject* entity)
{
    entity->updateAnimation();

    if (entity->getCurrentFrame() == entity->getFrameCount() - 1)
    {
        std::cout << entity->getName() << " casts a powerful spell!" << std::endl;
        entity->completeAction();
        entity->changeState(new IdleState());
    }
}

void MagicState::exit(GameObject* entity)
{
    std::cout << entity->getName() << " finishes casting magic!" << std::endl;
}

void MagicState::draw(GameObject* entity) 
{
    entity->draw();
}
