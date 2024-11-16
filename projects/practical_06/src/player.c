#include <stdio.h>

#include "../include/player.h"

// Move player up
void player_move_up(Player* player)
{
    player->y -= 1;
    printf("Player moved up to (%d, %d)\n", player->x, player->y);
}

// Move player down
void player_move_down(Player* player) 
{
    player->y += 1;
    printf("Player moved down to (%d, %d)\n", player->x, player->y);
}

// Move player left
void player_move_left(Player* player) 
{
    player->x -= 1;
    printf("Player moved left to (%d, %d)\n", player->x, player->y);
}

// Move player right
void player_move_right(Player* player) 
{
    player->x += 1;
    printf("Player moved right to (%d, %d)\n", player->x, player->y);
}

// Player fires
void player_fire(Player* player)
{
    printf("Player fired at position (%d, %d)\n", player->x, player->y);
}

// Player jumps
void player_jump(Player* player)
{
    printf("Player jumped from (%d, %d)\n", player->x, player->y);
}

// Player runs
void player_run(Player* player) 
{
    printf("Player is running at (%d, %d)\n", player->x, player->y);
}

// Player crouches
void player_crouch(Player* player) 
{
    printf("Player is crouching at (%d, %d)\n", player->x, player->y);
}

// Player attacks
void player_attack(Player* player)
{
    printf("Player attacks at (%d, %d)\n", player->x, player->y);
}

// Player shields
void player_shield(Player* player)
{
    printf("Player shields at (%d, %d)\n", player->x, player->y);
}