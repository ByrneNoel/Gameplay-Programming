#include "../include/invoker.h"

Invoker* create_invoker(Mediator* mediator)
{
    Invoker* invoker = (Invoker*)malloc(sizeof(Invoker));
    if (invoker == NULL) {
        printf("Failed to allocate memory for Invoker.\n");
        return NULL;
    }

    invoker->command = NULL;
    invoker->historyIndex = 0;
    invoker->redoIndex = 0;
    invoker->mediator = mediator;

    return invoker;
}

void invoker_set_command(Invoker* invoker, Command* command)
{
    invoker->command = command;
}

void invoker_execute_command(Invoker* invoker) 
{
    if (invoker->command)
    {
        //Memento* memento = player_create_memento(invoker->mediator->player);
        invoker->command->execute(invoker->command, invoker->mediator);
        invoker->history[invoker->historyIndex++] = (Command*)invoker->command;
        invoker->redoIndex = 0; // Reset redo history
    }
}

void invoker_undo(Invoker* invoker) 
{
    if (invoker->historyIndex > 0) 
    {
        Memento* lastMemento = (Memento*)invoker->history[--invoker->historyIndex];
        player_restore_state(invoker->mediator->player, lastMemento);
        Command* lastCommand = invoker->history[--invoker->historyIndex];
        lastCommand->undo(lastCommand, invoker->mediator);
        invoker->redoHistory[invoker->redoIndex++] = (Command*)lastMemento;
    }
}

void invoker_redo(Invoker* invoker) 
{
    if (invoker->redoIndex > 0) 
    {
        Memento* redoMemento = (Memento*)invoker->redoHistory[--invoker->redoIndex];
        player_restore_state(invoker->mediator->player, redoMemento);
        Command* redoCommand = invoker->redoHistory[--invoker->redoIndex];
        redoCommand->execute(redoCommand, invoker->mediator);
        invoker->history[invoker->historyIndex++] = (Command*)redoCommand;
    }
}

void free_invoker(Invoker* invoker) 
{
    if (invoker != NULL)
    {
        free(invoker);
    }
}
