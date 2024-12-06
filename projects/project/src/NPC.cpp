#include "NPC.h"
#include "AIState.h"
#include <iostream>


NPC::NPC(std::string name, int health, int x, int y)
    : GameObject(name, health, x, y), state(NPCState::IDLE)
{
    position = { (float)x, (float)y };

    // Load textures
    idleTexture = LoadTexture("assets/npcIdel.png");
    runningToAttackTexture = LoadTexture("assets/npcRun.png");
    attackingTexture = LoadTexture("assets/npcAttack.png");
    defendingTexture = LoadTexture("assets/npcHit.png");
    magicTexture = LoadTexture("assets/satyr_magic.png");
    deadTexture = LoadTexture("assets/npcDead.png");
}

NPC::~NPC() 
{
    // Unload textures

    UnloadTexture(idleTexture);
    UnloadTexture(runningToAttackTexture);
    UnloadTexture(attackingTexture);
    UnloadTexture(defendingTexture);
    UnloadTexture(magicTexture);
    UnloadTexture(deadTexture);
}

void NPC::taunt() 
{
    std::cout << name << " taunts you: 'Is that all you've got?'" << std::endl;
}

void NPC::walk() 
{
    std::cout << name << " walks forward." << std::endl;
}

void NPC::attack(GameObject& target) 
{
    int option = GetRandomValue(0, 2);
    switch (option)
    {
    case 0:
        flameBreath(target);
        state = NPCState::ATTACKING;
        break;
    case 1:
        tailSwipe(target);
        state = NPCState::ATTACKING;
        break;
    case 2:
        defend();
        state = NPCState::DEFENDING;
        break;
    default:
        flameBreath(target);
        state = NPCState::ATTACKING;
        break;
    }
    defending = false;
}

void NPC::flameBreath(GameObject& target)
{
    std::cout << name << " attacks " << target.getName() << " with Flame Breath\n";
    target.takeDamage(20);
}

void NPC::tailSwipe(GameObject& target)
{
    std::cout << name << " attacks " << target.getName() << " with Tail Swipe\n";
    target.takeDamage(15);
}

void NPC::defend() 
{
    std::cout << name << " takes a defensive stance." << std::endl;
    state = NPCState::DEFENDING;
    defending = true;
}

void NPC::update() 
{
    // Update state if dead
    if (health <= 0) {
        state = NPCState::DEAD;
    }
}

void NPC::draw() 
{
    // Draw the NPC sprite based on the state

    if (state == NPCState::IDLE) 
    {
        DrawTexture(idleTexture, position.x, position.y, WHITE);
    }
    else if (state == NPCState::RUNNING_TO_ATTACK)
    {
        DrawTexture(runningToAttackTexture, position.x, position.y, WHITE);
    }
    else if (state == NPCState::ATTACKING) 
    {
        DrawTexture(attackingTexture, position.x, position.y, WHITE);
    }
    else if (state == NPCState::DEFENDING) 
    {
        DrawTexture(defendingTexture, position.x, position.y, WHITE);
    }
    else if (state == NPCState::USING_MAGIC) 
    {
        DrawTexture(magicTexture, position.x, position.y, WHITE);
    }
    else if (state == NPCState::DEAD)
    {
        DrawTexture(deadTexture, position.x, position.y, WHITE);
    }
}