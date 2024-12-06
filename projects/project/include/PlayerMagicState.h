#ifndef PLAYER_MAGIC_STATE_H
#define PLAYER_MAGIC_STATE_H

#include "State.h"

class PlayerMagicState : public State 
{
public:
    void enter(GameObject* gameObject) override;
    void execute(GameObject* gameObject) override;
    void exit(GameObject* gameObject) override;
};

#endif // PLAYER_MAGIC_STATE_H
