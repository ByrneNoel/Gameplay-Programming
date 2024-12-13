#include "Player.h"
#include "IdleState.h"
#include "AttackState.h"
#include "DefendState.h"
#include "MagicState.h"
#include "DeadState.h"


Player::Player(std::string name, int health, int x, int y)
    : GameObject(name, health, x, y), originalPosition({ static_cast<float>(x), static_cast<float>(y) })
{

    // Load specific animations for Player
    setAnimation("running", "assets/playerRun.png", 7);     // Running animation (7 frames)
    setAnimation("attack", "assets/playerAttack.png", 6);  // Attacking animation (6 frames)
    setAnimation("block", "assets/playerBlock.png", 2);  // Defending animation (2 frames)
    setAnimation("magic", "assets/playerMagic.png", 6);  
    setAnimation("dead", "assets/playerDead.png", 7);    // Death animation (7 frames)
    setAnimation("idle", "assets/playerIdel.png", 5);    // Idle animation (5 frames)

    changeState(new IdleState());
}

void Player::reset() 
{

    health = 100;
    position = originalPosition;
    changeState(new IdleState()); 
}

bool Player::isPlayer() const 
{
    return true;
}

void Player::update() 
{
    if (currentState) currentState->execute(this); // Update the current state
}




