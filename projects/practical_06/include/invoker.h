#ifndef INVOKER_H
#define INVOKER_H

#include <stdlib.h>
#include <stdio.h>
#include "command.h"
#include "mediator.h"

#define MAX_HISTORY 100

typedef struct 
{
    Command* command;
    Command* history[MAX_HISTORY];
    Command* redoHistory[MAX_HISTORY];
    int historyIndex;
    int redoIndex;
    Mediator* mediator;
} Invoker;

Invoker* create_invoker(Mediator* mediator);
void invoker_set_command(Invoker* invoker, Command* command);
void invoker_execute_command(Invoker* invoker);
void invoker_undo(Invoker* invoker);
void invoker_redo(Invoker* invoker);
void free_invoker(Invoker* invoker);

#endif
