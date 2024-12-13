#include "GameObject.h"
#include "DeadState.h"
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
    if (health <= 0)
    {
        health = 0;
        changeState(new DeadState());
    }
}
void GameObject::setDefending(bool defending) 
{
    this->defending = defending;
    std::cout << getName() << " setDefending(" << (defending ? "true" : "false") << ") at " << __FILE__ << ":" << __LINE__ << std::endl;

}

bool GameObject::isDefending() const 
{
    return defending;
}

void GameObject::changeState(State* newState) 
{
    if (currentState) 
    {
        std::cout << getName() << " exits " << typeid(*currentState).name() << " state." << std::endl;
        currentState->exit(this);
        delete currentState;
    }

    currentState = newState;
    std::cout << getName() << " enters " << typeid(*currentState).name() << " state." << std::endl;
    currentState->enter(this);

    
    std::cout << name << " changed to new state." << std::endl;
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
    std::cout << getName() << " calls completeAction()." << std::endl;
    actionComplete = true;
}
bool GameObject::isAnimationComplete() const
{
   
    return currentFrame == frameCount - 1;
}



void GameObject::resetAction()
{
    actionComplete = false;
    std::cout << getName() << " reset their action. actionComplete set to false." << std::endl;
}

std::string GameObject::getCurrentStateName() const
{
    if (currentState)
    {
        return typeid(*currentState).name();
    }
    return "NoState";
}

void GameObject::setPosition(const Vector2& newPos) 
{
    position = newPos;
}

