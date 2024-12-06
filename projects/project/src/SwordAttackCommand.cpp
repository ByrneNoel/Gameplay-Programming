#include "SwordAttackCommand.h"
#include "PlayerSwordAttackState.h" 
#include "Player.h"

void SwordAttackCommand::execute(GameObject& gameObject) {
    gameObject.changeState(new PlayerSwordAttackState());
}
