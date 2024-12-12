#ifndef DEAD_STATE_H
#define DEAD_STATE_H

#include "State.h"
#include "GameObject.h"

class DeadState : public State {
public:
    void enter(GameObject* entity) override;
    void execute(GameObject* entity) override;
    void exit(GameObject* entity) override;
    void draw(GameObject* entity) override;
};

#endif // DEAD_STATE_H
