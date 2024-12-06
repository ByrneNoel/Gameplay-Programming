#include "GameObject.h"
#include <iostream>
#include "State.h" 
#include "raylib.h"

GameObject::GameObject(std::string name, int health, int x, int y)
    : name(name), health(health), cooldown(0), xPos(x), yPos(y), frame(0), maxFrames(1)
{
    texture = LoadTexture("default.png");
}

std::string GameObject::getName() const {
    return name;
}

int GameObject::getHealth() const {
    return health;
}

int GameObject::getCooldown() const {
    return cooldown;
}

void GameObject::setCooldown(int cd) {
    cooldown = cd;
}

bool GameObject::isDefending() const {
    return defending;
}

void GameObject::setDefending(bool value) {
    defending = value;
}

void GameObject::defend() {
    defending = true;
}

void GameObject::walk() {
    std::cout << name << " is walking..." << std::endl;
}

void GameObject::changeState(State* newState)
{
    // If there is an existing state, call its exit method
    if (currentState != nullptr) 
    {
        currentState->exit(this);
    }

    // Change to the new state and call its enter method
    currentState = newState;
    currentState->enter(this);
}

void GameObject::takeDamage(int damage) 
{
    if (defending) {
        std::cout << name << " is defending and takes no damage!" << std::endl;
    }
    else {
        health -= damage;
        std::cout << name << " takes damage: " << damage << ", health: " << health << std::endl;
    }
}

void GameObject::setAnimation(const std::string& textureFile, int frames) 
{
    texture = LoadTexture(textureFile.c_str());
    maxFrames = frames;
}

void GameObject::updateAnimation()
{
    frame = (frame + 1) % maxFrames;
}

void GameObject::draw()
{
    DrawTexture(texture, 100, 100, RAYWHITE);
}

void GameObject::castMagic() 
{
    
    std::cout << name << " casts magic!" << std::endl;
}

void GameObject::resetAnimation()
{
    
    setAnimation("idle.png", 1);  // Reset to idle animation with 1 frame
}
