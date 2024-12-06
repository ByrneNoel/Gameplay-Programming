#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include "raylib.h"
#include "State.h"

class State;

class GameObject 
{
protected:
    std::string name;
    int health;
    bool defending;
    Texture2D texture;
    int cooldown;
    int xPos;
    int yPos;
    int frame;
    int maxFrames;

public:
    GameObject(std::string name, int health, int x, int y);
   
    virtual ~GameObject() { UnloadTexture(texture); }

    std::string getName() const;
    int getHealth() const;
    int getCooldown() const;
    void setCooldown(int cd);
    bool isDefending() const;
    void setDefending(bool value);
    virtual void attack(GameObject& target) = 0;
    virtual void defend();
    virtual void walk();
    void takeDamage(int damage);

    void changeState(State* newState);
    State* currentState;

    void setAnimation(const std::string& textureFile, int frames);
    void resetAnimation();
    void updateAnimation();
    void draw();
    void castMagic();
};

#endif // GAME_OBJECT_H
