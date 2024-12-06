#ifndef PLAYER_SWORD_ATTACK_STATE_H
#define PLAYER_SWORD_ATTACK_STATE_H

#include "State.h"

class PlayerSwordAttackState : public State 
{
public:
    void enter(GameObject* gameObject) override;
    void execute(GameObject* gameObject) override;
    void exit(GameObject* gameObject) override;
};

#endif // PLAYER_SWORD_ATTACK_STATE_H
