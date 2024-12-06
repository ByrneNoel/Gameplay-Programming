#ifndef MAGIC_COMMAND_H
#define MAGIC_COMMAND_H

#include "Command.h"

class MagicCommand : public Command 
{
public:
    void execute(GameObject& gameObject) override;
};

#endif // MAGIC_COMMAND_H
