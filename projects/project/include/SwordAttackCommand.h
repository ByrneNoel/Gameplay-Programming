#ifndef SWORD_ATTACK_COMMAND_H
#define SWORD_ATTACK_COMMAND_H

#include "Command.h"

class PlayerSwordAttackState;

class SwordAttackCommand : public Command {
public:
    void execute(GameObject& gameObject) override;
};

#endif // SWORD_ATTACK_COMMAND_H
