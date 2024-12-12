#include "NPC.h"
#include "DeadState.h"
#include "IdleState.h"
#include "AttackState.h"
#include "DefendState.h"
#include "MagicState.h"


NPC::NPC(std::string name, int health, int x, int y)
    : GameObject(name, health, x, y) {
    originalPosition = { static_cast<float>(x), static_cast<float>(y) };
    if (this->getHealth() > 0) {
        changeState(new IdleState());
    }
    else {
        changeState(new DeadState());
    }

    // Initialize animations
    setAnimation("idle", "assets/npcIdle.png", 5);
    setAnimation("running", "assets/npcRun.png", 7);
    setAnimation("attack", "assets/npcAttack.png", 6);
    setAnimation("block", "assets/npcHit.png", 1);
    setAnimation("dead", "assets/npcDead.png", 7);
}

NPC::~NPC() {
    // Resources are managed by the base class destructor
}

void NPC::reset() 
{
    health = 100;
    position = originalPosition;
    changeState(new IdleState());
}

void NPC::takeTurn(GameObject& target
) {
    int npcAction = GetRandomValue(0, 2);

    if (npcAction == 0) 
    {
        this->changeState(new AttackState());
        target.takeDamage(15);
    }
    else if (npcAction == 1) 
    {
        this->changeState(new DefendState());
    }
    else if (npcAction == 2) 
    {
        this->changeState(new MagicState());
        target.takeDamage(20); 
    }
}

void NPC::update() 
{
    if (currentState) currentState->execute(this); // Update the current state
}