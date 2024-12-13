#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "State.h"

class Player : public GameObject 
{
protected:

    bool actionComplete;

public:
    Player(std::string name, int health, int x, int y);
    
    void reset();
    bool isPlayer() const override;
    void update() override;

       

private:
    Vector2 originalPosition;
   
};

#endif // PLAYER_H
