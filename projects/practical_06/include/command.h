#ifndef COMMAND_H
#define COMMAND_H

// Forward declaration of the Mediator struct
typedef struct Mediator Mediator;


typedef struct Command
{
    void (*execute)(struct Command* command, Mediator* mediator);
    void (*undo)(struct Command* command, Mediator* mediator);
}Command;

typedef enum {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    FIRE,
    JUMP,
    RUN,
    CROUCH,
    ATTACK,
    SHIELD,
    NONE
} CommandType;

// Function to create and initialize commands
Command* create_move_up_command();
Command* create_move_down_command();
Command* create_move_left_command();
Command* create_move_right_command();
Command* create_fire_command();
Command* create_run_command();
Command* create_jump_command();
Command* create_crouch_command();
Command* create_attack_command();
Command* create_shield_command();

#endif // COMMAND_H

