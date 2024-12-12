#ifndef NPC_H
#define NPC_H

#include "GameObject.h"
#include "State.h"

class NPC : public GameObject 
{

protected:
    
    bool actionComplete;

public:
    NPC(std::string name, int health, int x, int y);
    ~NPC();
    void reset();
    void takeTurn(GameObject& target);
    void update() override;

    bool isActionComplete() const { return actionComplete; }
    void resetAction() { actionComplete = false; }
    void completeAction() { actionComplete = true; }

private:

    Vector2 originalPosition;

};

#endif // NPC_H
