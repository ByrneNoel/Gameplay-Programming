#ifndef PLAYER_SHIELD_BLOCK_STATE_H
#define PLAYER_SHIELD_BLOCK_STATE_H

#include "State.h"

class PlayerShieldBlockState : public State
{
public:
    void enter(GameObject* gameObject) override;
    void execute(GameObject* gameObject) override;
    void exit(GameObject* gameObject) override;
};

#endif // PLAYER_SHIELD_BLOCK_STATE_H
