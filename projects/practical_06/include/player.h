#ifndef PLAYER_H
#define PLAYER_H
#include "../include/memento.h"

typedef struct Memento Memento;

typedef struct Player
{
    int x;
    int y;
    int health;
} Player;



void player_move_up(Player* player);
void player_move_down(Player* player);
void player_move_left(Player* player);
void player_move_right(Player* player);
void player_jump(Player* player);
void player_run(Player* player);
void player_crouch(Player* player);
void player_attack(Player* player);
void player_shield(Player* player);
void player_fire(Player* player);

Memento* player_create_memento(const Player* player);
void player_restore_state(Player* player, const Memento* memento);

#endif
