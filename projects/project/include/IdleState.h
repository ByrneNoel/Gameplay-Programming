#ifndef IDLESTATE_H
#define IDLESTATE_H

#include "State.h"
#include "GameObject.h"

class IdleState : public State {
public:
    void enter(GameObject* entity) override;
    void execute(GameObject* entity) override;
    void exit(GameObject* entity) override;
    void draw(GameObject* entity) override;
};

#endif
