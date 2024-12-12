#ifndef DEFEND_STATE_H
#define DEFEND_STATE_H

#include "State.h"
#include "GameObject.h"

class DefendState : public State {
public:
    void enter(GameObject* entity) override;
    void execute(GameObject* entity) override;
    void exit(GameObject* entity) override;
    void draw(GameObject* entity) override;
};

#endif // DEFEND_STATE_H
