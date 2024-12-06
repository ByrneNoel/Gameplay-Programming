#include "Player.h"
#include <iostream>


Player::Player(std::string name, int health, int x, int y)
    : GameObject(name, health, x, y), state(PlayerState::IDLE), swordCooldown(0), shieldCooldown(0), magicCooldown(0)
{
    position = { (float)x, (float)y };

    // Load textures
    idleTexture = LoadTexture("assets/playerIdel.png");
    runningToAttackTexture = LoadTexture("assets/playerRun.png");
    attackingTexture = LoadTexture("assets/playerAttack.png");
    defendingTexture = LoadTexture("assets/playerBlock.png");
    magicTexture = LoadTexture("assets/knight_magic.png");
    deadTexture = LoadTexture("assets/playerDead.png");
}

Player::~Player() 
{
    // Unload textures
    UnloadTexture(idleTexture);
    UnloadTexture(runningToAttackTexture);
    UnloadTexture(attackingTexture);
    UnloadTexture(defendingTexture);
    UnloadTexture(magicTexture);
    UnloadTexture(deadTexture);
}

void Player::charge()
{
    std::cout << name << " charges at the enemy!" << std::endl;
}

void Player::walk() 
{
    std::cout << name << " walks forward." << std::endl;
}

void Player::attack(GameObject& target) 
{
    basicAttack(target);
}

void Player::basicAttack(GameObject& target) 
{
    std::cout << name << " attacks " << target.getName() << " with a Basic Attack\n";
    target.takeDamage(7);
}

void Player::swordSlash(GameObject& target) 
{
    if (swordCooldown == 0)
    {
        std::cout << name << " attacks " << target.getName() << " with Sword Slash\n";
        target.takeDamage(15);
        swordCooldown = 1;
    }
    else 
    {
        std::cout << name << "'s Sword Slash is on cooldown for " << swordCooldown << " more turns.\n";
    }
}

void Player::shieldBash(GameObject& target)
{
    if (shieldCooldown == 0) 
    {
        std::cout << name << " attacks " << target.getName() << " with Shield Bash\n";
        target.takeDamage(25);
        shieldCooldown = 2;
    }
}

void Player::defend() 
{
    std::cout << name << " takes a defensive stance." << std::endl;
    state = PlayerState::DEFENDING;
    shieldCooldown = 3;
}

void Player::useMagic(GameObject& target) 
{
    if (magicCooldown == 0) 
    {
        std::cout << name << " uses a magical attack on " << target.getName() << "\n";
        target.takeDamage(20);
        magicCooldown = 3;
    }
}

void Player::update()
{
    // Handle cooldowns
    if (swordCooldown > 0) swordCooldown--;
    if (shieldCooldown > 0) shieldCooldown--;
    if (magicCooldown > 0) magicCooldown--;
}

void Player::draw() 
{
    // Draw the player sprite based on the state

    if (state == PlayerState::IDLE) 
    {
        DrawTexture(idleTexture, position.x, position.y, WHITE);
    }
    else if (state == PlayerState::RUNNING_TO_ATTACK)
    {
        DrawTexture(runningToAttackTexture, position.x, position.y, WHITE);
    }
    else if (state == PlayerState::ATTACKING) 
    {
        DrawTexture(attackingTexture, position.x, position.y, WHITE);
    }
    else if (state == PlayerState::DEFENDING) 
    {
        DrawTexture(defendingTexture, position.x, position.y, WHITE);
    }
    else if (state == PlayerState::USING_MAGIC) 
    {
        DrawTexture(magicTexture, position.x, position.y, WHITE);
    }
    else if (state == PlayerState::DEAD)
    {
        DrawTexture(deadTexture, position.x, position.y, WHITE);
    }
}

void Player::handleInput()
{
    if (IsKeyPressed(KEY_S))
    {
        state = PlayerState::ATTACKING;
        // Handle sword attack
    }
    else if (IsKeyPressed(KEY_D))
    {
        state = PlayerState::DEFENDING;
        // Handle shield block
    }
    else if (IsKeyPressed(KEY_M)) 
    {
        state = PlayerState::USING_MAGIC;
        // Handle magic attack
    }
}
