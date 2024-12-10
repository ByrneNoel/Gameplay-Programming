#include "NPC.h"
#include "Player.h"
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

    frameWidth = idleTexture.width / 5;   // Idle: 5 frames
    runningFrameWidth = runningToAttackTexture.width / 7;  // Running: 7 frames
    attackingFrameWidth = attackingTexture.width / 6;  // Attack: 6 frames
    defendingFrameWidth = defendingTexture.width / 1;  // Defend: 1 frames
    magicFrameWidth = magicTexture.width / 5;  // Magic: 5 frames
    deadFrameWidth = deadTexture.width / 7;  // Dead: 7 frames
    frameHeight = idleTexture.height;
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
    updateAnimation();

    // Update state if dead
    if (health <= 0) 
    {
        state = NPCState::DEAD;
    }
}

// Draw the NPC
void NPC::draw()
{
    Rectangle sourceRect = getFrameRectangle();
    Rectangle destRect = { position.x, position.y, static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
    Texture2D currentTexture;

    switch (state) {
    case NPCState::IDLE: currentTexture = idleTexture; break;
    case NPCState::RUNNING_TO_ATTACK: currentTexture = runningToAttackTexture; break;
    case NPCState::ATTACKING: currentTexture = attackingTexture; break;
    case NPCState::DEFENDING: currentTexture = defendingTexture; break;
    case NPCState::USING_MAGIC: currentTexture = magicTexture; break;
    case NPCState::DEAD: currentTexture = deadTexture; break;
    default: currentTexture = idleTexture; break;
    }

    DrawTexturePro(currentTexture, sourceRect, destRect, { 0.0f, 0.0f }, 0.0f, WHITE);
}


void NPC::handleAI(Player& player) 
{
    if (state == NPCState::DEAD) 
    {
        return; 
    }

    // Simple AI behavior logic
    if (player.getHealth() <= 20) 
    {
        // Use a magic attack if the player is low on health
        std::cout << name << " uses a magical attack on " << player.getName() << "!\n";
        setState(NPCState::USING_MAGIC);
        player.takeDamage(25); // Example damage
    }
    else if (rand() % 2 == 0) {
        // Attack half the time
        std::cout << name << " attacks " << player.getName() << "!\n";
        setState(NPCState::ATTACKING);
        player.takeDamage(15); 
    }
    else 
    {
        // Defend the other half
        std::cout << name << " takes a defensive stance!\n";
        setState(NPCState::DEFENDING);
    }
}

void NPC::updateAnimation() 
{
    timeSinceLastFrame += GetFrameTime();

    if (timeSinceLastFrame >= frameSpeed) 
    {
        timeSinceLastFrame = 0.0f;
        currentFrame++;

        switch (state) {
        case NPCState::IDLE:
            if (currentFrame >= idleFrames) currentFrame = 0;
            break;
        case NPCState::ATTACKING:
            if (currentFrame >= attackingFrames) 
            {
                currentFrame = 0;
                setState(NPCState::IDLE); // Return to idle after attack animation
            }
            break;
        case NPCState::DEFENDING:
            if (currentFrame >= defendingFrames)
            {
                currentFrame = 0;
                setState(NPCState::IDLE); // Return to idle after defense animation
            }
            break;
        case NPCState::USING_MAGIC:
            if (currentFrame >= magicFrames)
            {
                currentFrame = 0;
                setState(NPCState::IDLE); // Return to idle after magic animation
            }
            break;
        default:
            break;
        }
    }
}



Rectangle NPC::getFrameRectangle() const 
{
    return 
    {
        static_cast<float>(currentFrame * frameWidth),
        0.0f,
        static_cast<float>(frameWidth),
        static_cast<float>(frameHeight)
    };
}

NPCState NPC::getState() const 
{
    return state;
}

void NPC::setState(NPCState newState) 
{
    state = newState;
}

