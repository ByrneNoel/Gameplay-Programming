#ifndef ATTACK_STATE_H
#define ATTACK_STATE_H

#include "State.h"
#include "GameObject.h"
#include "raylib.h"
#include <iostream>
#include <cmath>

enum class AttackPhase { APPROACH, ANIMATING, RETREAT };

class AttackState : public State
{
public:
    AttackState() = default; // Default constructor

    void enter(GameObject* entity) override;
    void execute(GameObject* entity) override;
    void exit(GameObject* entity) override;
    void draw(GameObject* entity) override;

private:

    AttackPhase phase = AttackPhase::APPROACH;
    bool damageDealt = false; 
    Vector2 startPosition{};
    Vector2 targetPosition{};
    float moveSpeed = 200.0f; 
};

#endif // ATTACK_STATE_H
