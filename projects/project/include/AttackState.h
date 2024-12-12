#ifndef ATTACK_STATE_H
#define ATTACK_STATE_H

#include "State.h"
#include "GameObject.h"
#include "raylib.h"
#include <iostream>

class AttackState : public State
{
public:
    AttackState() = default; // Default constructor

    void enter(GameObject* entity) override;
    void execute(GameObject* entity) override;
    void exit(GameObject* entity) override;
    void draw(GameObject* entity) override;
};

#endif // ATTACK_STATE_H
