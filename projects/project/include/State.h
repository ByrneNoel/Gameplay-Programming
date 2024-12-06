#ifndef STATE_H
#define STATE_H

#include "GameObject.h"

class GameObject;

// Abstract base class for all states
class State {
public:
    virtual void enter(GameObject* gameObject) = 0;
    virtual void execute(GameObject* gameObject) = 0;
    virtual void exit(GameObject* gameObject) = 0;
};

// Specific state classes
class IdleState : public State {
public:
    void enter(GameObject* gameObject) override;
    void execute(GameObject* gameObject) override;
    void exit(GameObject* gameObject) override;
};

class AttackState : public State {
public:
    void enter(GameObject* gameObject) override;
    void execute(GameObject* gameObject) override;
    void exit(GameObject* gameObject) override;
};

class DefendState : public State {
public:
    void enter(GameObject* gameObject) override;
    void execute(GameObject* gameObject) override;
    void exit(GameObject* gameObject) override;
};

#endif
