#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include "State.h"
#include "GameObject.h"
#include <iostream>

class MagicState : public State
{
public:
    MagicState() = default; // Default constructor

    void enter(GameObject* entity) override;
    void execute(GameObject* entity) override;
    void exit(GameObject* entity) override;
    void draw(GameObject* entity) override;
};

#endif // MAGIC_STATE_H
