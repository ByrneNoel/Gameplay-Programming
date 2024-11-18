#ifndef MEMENTO_H
#define MEMENTO_H

#include "../include/player.h" 
typedef struct Player Player;


typedef struct Memento 
{
    Player* playerState;  
} Memento;


Memento* create_memento(const Player* player);
void restore_from_memento(Player* player, const Memento* memento);


#endif
