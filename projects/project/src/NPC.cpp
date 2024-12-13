#include "NPC.h"
#include "DeadState.h"
#include "IdleState.h"
#include "AttackState.h"
#include "DefendState.h"
#include "MagicState.h"


NPC::NPC(std::string name, int health, int x, int y)
    : GameObject(name, health, x, y) 
{
    originalPosition = { static_cast<float>(x), static_cast<float>(y) };
    
    // Initialize animations
    setAnimation("running", "assets/npcRun.png", 7);
    setAnimation("attack", "assets/npcAttack.png", 6);
    setAnimation("block", "assets/npcHit.png", 1);
    setAnimation("magic", "assets/npcMagic.png", 6);
    setAnimation("dead", "assets/npcDead.png", 7);
    setAnimation("idel", "assets/npcIdel.png", 5);
    changeState(new IdleState());
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

void NPC::takeTurn(GameObject& player)
{
    int npcAction = GetRandomValue(0, 2); // Randomize NPC action

    if (npcAction == 0)
    {
        changeState(new AttackState());
        setTarget(&player);
        std::cout << getName() << " attacks the Player!" << std::endl;
    }
    else if (npcAction == 1)
    {
        changeState(new DefendState());
        std::cout << getName() << " defends!" << std::endl;
    }
    else if (npcAction == 2)
    {
        changeState(new MagicState());
        setTarget(&player);
        std::cout << getName() << " casts magic on the Player!" << std::endl;
    }

    
}





void NPC::update() 
{
    if (currentState) currentState->execute(this); // Update the current state
}