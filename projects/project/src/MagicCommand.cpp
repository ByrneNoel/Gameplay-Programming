#include "GameObject.h"
#include "MagicCommand.h"
#include "Player.h"
#include "PlayerMagicState.h"

void MagicCommand::execute(GameObject& gameObject)
{
    gameObject.changeState(new PlayerMagicState());
}
