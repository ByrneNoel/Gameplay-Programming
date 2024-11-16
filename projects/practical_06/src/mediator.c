#include <stdbool.h>
#include <stdlib.h>
#include "../include/mediator.h"
#include "../include/player.h"
#include "../include/command.h"


// Creates and initializes a new mediator instance
Mediator* create_mediator(Player* player)
{
    Mediator* mediator = (Mediator*)malloc(sizeof(Mediator));
    mediator->player = player;
    return mediator;
}

// Function to execute a command through the mediator
void mediator_execute_command(Mediator* mediator, Command* command)
{       
    command->execute(command, mediator);
    
}
