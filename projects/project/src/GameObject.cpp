#include "GameObject.h"
#include <iostream>

GameObject::GameObject(std::string name, int health, int x, int y)
    : name(name), health(health), position({ (float)x, (float)y }), currentState(nullptr),
    frameWidth(0), frameHeight(0), currentFrame(0), timeSinceLastFrame(0.0f), frameSpeed(0.2f), frameCount(0), actionComplete(false) {}

GameObject::~GameObject()
{
    for (auto& pair : animations) 
    {
        UnloadTexture(pair.second);
    }
}

std::string GameObject::getName() const 
{
    return name;
}

int GameObject::getHealth() const
{
    return health;
}

void GameObject::takeDamage(int damage) 
{
    health -= damage;
    if (health < 0) health = 0;
}

void GameObject::setDefending(bool defending) 
{
    this->defending = defending;
}

bool GameObject::isDefending() const 
{
    return defending;
}

void GameObject::changeState(State* newState) 
{
    if (currentState) 
    {
        currentState->exit(this);
        delete currentState;
    }
    currentState = newState;
    currentState->enter(this);

    actionComplete = false; // Reset actionComplete when changing states
}

void GameObject::setAnimation(const std::string& animationName, const std::string& texturePath, int frames) {
    if (animations.find(animationName) == animations.end())
    {
        Texture2D texture = LoadTexture(texturePath.c_str());
        animations[animationName] = texture;
    }
    currentAnimation = animationName;
    frameCount = frames;
    frameWidth = animations[currentAnimation].width / frameCount;
    frameHeight = animations[currentAnimation].height;
    currentFrame = 0;
    timeSinceLastFrame = 0.0f;
}

void GameObject::resetAnimation() 
{
    currentFrame = 0;
    timeSinceLastFrame = 0.0f;
}

void GameObject::updateAnimation() 
{
    timeSinceLastFrame += GetFrameTime();
    if (timeSinceLastFrame >= frameSpeed)
    {
        timeSinceLastFrame = 0.0f;
        currentFrame = (currentFrame + 1) % frameCount;
    }
}

void GameObject::draw()
{
    if (!currentAnimation.empty() && animations.find(currentAnimation) != animations.end()) 
    {
        Texture2D texture = animations[currentAnimation];
        Rectangle sourceRect = getFrameRectangle();
        Rectangle destRect = { position.x, position.y, (float)frameWidth * 3.0f, (float)frameHeight * 3.0f };
        DrawTexturePro(texture, sourceRect, destRect, { 0.0f, 0.0f }, 0.0f, WHITE);
    }
}

Rectangle GameObject::getFrameRectangle() const 
{
    return { static_cast<float>(frameWidth * currentFrame), 0.0f, (float)frameWidth, (float)frameHeight };
}

Texture2D GameObject::getTextureForState() const 
{
    return animations.at(currentAnimation);
}

const Vector2& GameObject::getPosition() const
{
    return position;
}

bool GameObject::isPlayer() const 
{
    return false; // Default is NPC; override in Player class
}

void GameObject::completeAction() 
{
    actionComplete = true;
}

bool GameObject::isAnimationComplete() const 
{
    return currentFrame >= frameCount - 1;
}
