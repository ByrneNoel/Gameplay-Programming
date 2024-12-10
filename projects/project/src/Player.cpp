#include "Player.h"
#include <iostream>

Player::Player(std::string name, int health, int x, int y)
    : GameObject(name, health, x, y), state(PlayerState::IDLE), swordCooldown(0), shieldCooldown(0), magicCooldown(0),
    currentFrame(0), timeSinceLastFrame(0.0f), frameSpeed(0.1f)
{
    // Initialize position
    position = { static_cast<float>(x), static_cast<float>(y) };

    // Load textures
    idleTexture = LoadTexture("assets/playerIdel.png");
    runningToAttackTexture = LoadTexture("assets/playerRun.png");
    attackingTexture = LoadTexture("assets/playerAttack.png");
    defendingTexture = LoadTexture("assets/playerBlock.png");
    magicTexture = LoadTexture("assets/knight_magic.png");
    deadTexture = LoadTexture("assets/playerDead.png");

    // Set the frame width and height based on the texture size
    frameWidth = idleTexture.width / 5;   // Idle: 5 frames
    runningFrameWidth = runningToAttackTexture.width / 7;  // Running to attack: 7 frames
    attackingFrameWidth = attackingTexture.width / 6;  // Attack: 6 frames
    defendingFrameWidth = defendingTexture.width / 2;   // Defend: 2 frames
    magicFrameWidth = magicTexture.width / 5;   // Magic: 5 frames
    deadFrameWidth = deadTexture.width / 7;   // Dead: 7 frames

    frameHeight = idleTexture.height;
}

Player::~Player() {
    // Unload textures
    UnloadTexture(idleTexture);
    UnloadTexture(runningToAttackTexture);
    UnloadTexture(attackingTexture);
    UnloadTexture(defendingTexture);
    UnloadTexture(magicTexture);
    UnloadTexture(deadTexture);
}

void Player::attack(GameObject& target) {
    if (state != PlayerState::ATTACKING) {
        state = PlayerState::ATTACKING;
        currentFrame = 0;  // Reset animation for attack
        std::cout << name << " attacks " << target.getName() << "!\n";
        target.takeDamage(15);  // Example damage
    }
}

void Player::defend() {
    state = PlayerState::DEFENDING;
    currentFrame = 0;  // Reset animation for defend
    std::cout << name << " is defending!\n";
}

void Player::walk() {
    state = PlayerState::RUNNING_TO_ATTACK;
    currentFrame = 0;  // Reset animation for walking
    std::cout << name << " is walking...\n";
}

void Player::update() {
    updateAnimation();

    // Handle cooldowns
    if (swordCooldown > 0) swordCooldown--;
    if (shieldCooldown > 0) shieldCooldown--;
    if (magicCooldown > 0) magicCooldown--;
}

void Player::draw()
{
    Rectangle sourceRect = getFrameRectangle();
    Rectangle destRect = { position.x, position.y, static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
    Texture2D currentTexture;

    switch (state) {
    case PlayerState::IDLE: currentTexture = idleTexture; break;
    case PlayerState::RUNNING_TO_ATTACK: currentTexture = runningToAttackTexture; break;
    case PlayerState::ATTACKING: currentTexture = attackingTexture; break;
    case PlayerState::DEFENDING: currentTexture = defendingTexture; break;
    case PlayerState::USING_MAGIC: currentTexture = magicTexture; break;
    case PlayerState::DEAD: currentTexture = deadTexture; break;
    default: currentTexture = idleTexture; break;
    }

    DrawTexturePro(currentTexture, sourceRect, destRect, { 0.0f, 0.0f }, 0.0f, WHITE);
}


void Player::handleInput() 
{
    if (IsKeyPressed(KEY_S) && state != PlayerState::ATTACKING) 
    {
        if (state == PlayerState::RUNNING_TO_ATTACK)
        {
            state = PlayerState::ATTACKING; // Transition to attacking
            currentFrame = 0;
        }
        else 
        {
            state = PlayerState::RUNNING_TO_ATTACK; // Start running to attack
            currentFrame = 0;
        }
    }
    else if (IsKeyPressed(KEY_D) && state != PlayerState::DEFENDING) 
    {
        state = PlayerState::DEFENDING;
        currentFrame = 0; // Reset defending animation
    }
    else if (IsKeyPressed(KEY_M) && state != PlayerState::USING_MAGIC) 
    {
        state = PlayerState::USING_MAGIC;
        currentFrame = 0; // Reset magic animation
    }
}




void Player::updateAnimation() {
    timeSinceLastFrame += GetFrameTime();

    if (timeSinceLastFrame >= frameSpeed) {
        timeSinceLastFrame = 0.0f; // Reset frame time counter
        currentFrame++;           // Move to the next frame

        int totalFrames = 0;
        bool resetToIdle = false;

        // Determine the total frames for the current state
        switch (state) {
        case PlayerState::IDLE:
            totalFrames = 5; // Idle: 5 frames
            break;
        case PlayerState::RUNNING_TO_ATTACK:
            totalFrames = 7; // Running: 7 frames
            if (currentFrame >= totalFrames) {
                currentFrame = 0;
                state = PlayerState::ATTACKING; // Transition to attacking after running
            }
            return; // Prevent resetting to IDLE
        case PlayerState::ATTACKING:
            totalFrames = 6; // Attacking: 6 frames
            resetToIdle = true;
            break;
        case PlayerState::DEFENDING:
            totalFrames = 2; // Defending: 2 frames
            resetToIdle = true;
            break;
        case PlayerState::USING_MAGIC:
            totalFrames = 5; // Magic: 5 frames
            resetToIdle = true;
            break;
        case PlayerState::DEAD:
            totalFrames = 7; // Dead: 7 frames
            break;
        default:
            break;
        }

        // Loop or reset animation
        if (currentFrame >= totalFrames) {
            currentFrame = 0;

            if (resetToIdle) {
                state = PlayerState::IDLE; // Reset to IDLE after animation
            }
        }
    }
}




Rectangle Player::getFrameRectangle() const {
    Rectangle frameRect = { 0.0f, 0.0f, static_cast<float>(frameWidth), static_cast<float>(frameHeight) };

    switch (state) {
    case PlayerState::IDLE:
        frameRect.x = static_cast<float>(currentFrame * frameWidth);
        break;
    case PlayerState::RUNNING_TO_ATTACK:
        frameRect.x = static_cast<float>(currentFrame * runningFrameWidth);
        break;
    case PlayerState::ATTACKING:
        frameRect.x = static_cast<float>(currentFrame * attackingFrameWidth);
        break;
    case PlayerState::DEFENDING:
        frameRect.x = static_cast<float>(currentFrame * defendingFrameWidth);
        break;
    case PlayerState::USING_MAGIC:
        frameRect.x = static_cast<float>(currentFrame * magicFrameWidth);
        break;
    case PlayerState::DEAD:
        frameRect.x = static_cast<float>(currentFrame * deadFrameWidth);
        break;
    default:
        break;
    }

    return frameRect;
}

PlayerState Player::getState() const 
{
    return state;
}

void Player::setState(PlayerState newState) 
{
    if (state != newState) 
    {
        state = newState;
        currentFrame = 0; // Reset animation frame on state change
        timeSinceLastFrame = 0.0f;
    }
}
