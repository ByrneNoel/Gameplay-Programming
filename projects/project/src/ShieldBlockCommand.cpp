#include "PlayerShieldBlockState.h"
#include "ShieldBlockCommand.h"


void ShieldBlockCommand::execute(GameObject& gameObject) 
{
    gameObject.changeState(new PlayerShieldBlockState());
}
