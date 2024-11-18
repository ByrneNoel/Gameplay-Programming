#ifndef MEMENTO_H
#define MEMENTO_H

#include "../include/memento.h"
#include "../include/player.h"
#include <stdlib.h>  
#include <stddef.h>   


typedef struct Memento 
{
    Player playerState; 
} Memento;

// Create a new Memento
Memento* create_memento(const Player* player) 
{
    Memento* memento = (Memento*)malloc(sizeof(Memento));
    if (memento != NULL) 
    {
        memento->playerState = *player; // Copy player state
    }
    return memento;
}

// Restore a player's state
void restore_from_memento(Player* player, const Memento* memento)
{
    if (memento != NULL) {
        *player = memento->playerState;
    }
}

// Free Memento
void free_memento(Memento* memento)
{
    free(memento);
}

#endif 
