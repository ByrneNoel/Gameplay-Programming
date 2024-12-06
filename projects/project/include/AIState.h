#ifndef AI_STATE_H
#define AI_STATE_H

#include "GameObject.h" 
#include "State.h"

class GameObject;

class AIState : public State 
{
public:
    void enter(GameObject* gameObject) override;
    void execute(GameObject* gameObject) override;
    void exit(GameObject* gameObject) override;
};

#endif // AI_STATE_H
