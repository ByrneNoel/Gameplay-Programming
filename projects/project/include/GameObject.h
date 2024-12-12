#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "raylib.h"
#include <string>
#include <map>
#include "State.h"

class State; // Forward declaration


class GameObject {
protected:
    std::string name;
    int health;
    bool defending;
    Vector2 position;
    State* currentState;
    int frameWidth, frameHeight;
    int currentFrame;
    float timeSinceLastFrame;
    float frameSpeed;
    int frameCount;
    std::map<std::string, Texture2D> animations; // Map of animations
    std::string currentAnimation;
    bool actionComplete;

public:
    GameObject(std::string name, int health, int x, int y);
    virtual ~GameObject();

      // Getters and setters
    int getCurrentFrame() const { return currentFrame; }
    void setCurrentFrame(int frame) { currentFrame = frame; }

    float getTimeSinceLastFrame() const { return timeSinceLastFrame; }
    void setTimeSinceLastFrame(float time) { timeSinceLastFrame = time; }

    float getFrameSpeed() const { return frameSpeed; }
    void setFrameSpeed(float speed) { frameSpeed = speed; }

    int getFrameCount() const { return frameCount; }
    void setFrameCount(int count) { frameCount = count; }

    std::string getName() const;
    int getHealth() const;
    void takeDamage(int damage);
    void setDefending(bool defending);
    bool isDefending() const;
    void changeState(State* newState);

    void completeAction();
    bool isAnimationComplete() const;

    // Animation methods
    void setAnimation(const std::string& animationName, const std::string& texturePath, int frames);
    void resetAnimation();
    void updateAnimation();
    void draw();
    Rectangle getFrameRectangle() const;
    Texture2D getTextureForState() const;

    const Vector2& getPosition() const;

    virtual void update() {};


    virtual bool isPlayer() const; // To differentiate between Player and NPC
};

#endif // GAMEOBJECT_H
