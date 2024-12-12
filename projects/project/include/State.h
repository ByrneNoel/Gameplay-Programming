#ifndef STATE_H
#define STATE_H

#include "raylib.h"
#include "GameObject.h" // Base class for Player and NPC

class GameObject;

class State {
public:
    virtual ~State() = default;

    // State lifecycle methods
    virtual void enter(GameObject* entity) = 0;
    virtual void execute(GameObject* entity) = 0;
    virtual void exit(GameObject* entity) = 0;

    
    virtual void draw(GameObject* entity) = 0;
};

#endif // STATE_H
