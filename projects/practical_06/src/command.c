#include <stdlib.h>
#include "../include/command.h"
#include "../include/mediator.h"
#include "../include/player.h"
#include "../include/memento.h"

// Move Up Command Functions
void move_up_execute(Command* command, Mediator* mediator) 
{
    (void)command; // Mark as explicitly unused
    player_move_up(mediator->player);
}

void move_up_undo(Command* command, Mediator* mediator) 
{
    (void)command; // Mark as explicitly unused
    player_move_down(mediator->player); // Undo move by moving down
}

Command* create_move_up_command() 
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = move_up_execute;
    command->undo = move_up_undo;
    return command;
}

// Move Down Command Functions
void move_down_execute(Command* command, Mediator* mediator)
{
    (void)command; //  Mark as explicitly unused
    player_move_down(mediator->player);
}

void move_down_undo(Command* command, Mediator* mediator)
{
    (void)command; //  Mark as explicitly unused
    player_move_up(mediator->player); // Undo move by moving up
}

Command* create_move_down_command()
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = move_down_execute;
    command->undo = move_down_undo;
    return command;
}

// Move Left Command Functions
void move_left_execute(Command* command, Mediator* mediator)
{
    (void)command; //  Mark as explicitly unused
    player_move_left(mediator->player);
}

void move_left_undo(Command* command, Mediator* mediator)
{
    (void)command; // Mark as explicitly unused
    player_move_right(mediator->player); // Undo move by moving right
}

Command* create_move_left_command() 
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = move_left_execute;
    command->undo = move_left_undo;
    return command;
}

// Move Right Command Functions
void move_right_execute(Command* command, Mediator* mediator) 
{
    (void)command; //  Mark as explicitly unused
    player_move_right(mediator->player);
}

void move_right_undo(Command* command, Mediator* mediator) 
{
    (void)command; //  Mark as explicitly unused
    player_move_left(mediator->player); // Undo move by moving left
}

Command* create_move_right_command() 
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = move_right_execute;
    command->undo = move_right_undo;
    return command;
}

// Fire Command Functions
void fire_execute(Command* command, Mediator* mediator)
{
    (void)command; // Mark as explicitly unused
    player_fire(mediator->player);
}

Command* create_fire_command() 
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = fire_execute;
    return command;
}





// Execute and undo functions for each command
void jump_execute(Command* command, Mediator* mediator) 
{
    (void)command;
    player_jump(mediator->player);
}

void jump_undo(Command* command, Mediator* mediator)
{
    (void)command;  
    (void)mediator; 

}

void run_execute(Command* command, Mediator* mediator) 
{
    (void)command;
    player_run(mediator->player);
}

void run_undo(Command* command, Mediator* mediator) 
{
    (void)command;
    (void)mediator; 
    
}


void crouch_execute(Command* command, Mediator* mediator) 
{
    (void)command;
    player_crouch(mediator->player);
}

void crouch_undo(Command* command, Mediator* mediator)
{
    (void)command;   
    (void)mediator;
}

void attack_execute(Command* command, Mediator* mediator)
{
    (void)command;
    player_attack(mediator->player);
}

void attack_undo(Command* command, Mediator* mediator)
{
    (void)command;  
    (void)mediator; 
 }

void shield_execute(Command* command, Mediator* mediator) 
{
    (void)command;
    player_shield(mediator->player);
}

void shield_undo(Command* command, Mediator* mediator)
{
    (void)command;  
    (void)mediator; 
 }

Command* create_jump_command() 
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = jump_execute;
    command->undo = jump_undo;
    return command;
}

Command* create_run_command() 
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = run_execute;
    command->undo = run_undo;
    return command;
}

Command* create_crouch_command() 
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = crouch_execute;
    command->undo = crouch_undo;
    return command;
}

Command* create_attack_command()
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = attack_execute;
    command->undo = attack_undo;
    return command;
}

Command* create_shield_command() 
{
    Command* command = (Command*)malloc(sizeof(Command));
    command->execute = shield_execute;
    command->undo = shield_undo;
    return command;
}
