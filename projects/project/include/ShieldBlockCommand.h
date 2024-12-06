#ifndef SHIELD_BLOCK_COMMAND_H
#define SHIELD_BLOCK_COMMAND_H

#include "Command.h"

class PlayerShieldBlockState;

class ShieldBlockCommand : public Command
{
public:
    void execute(GameObject& gameObject) override;
};

#endif // SHIELD_BLOCK_COMMAND_H
