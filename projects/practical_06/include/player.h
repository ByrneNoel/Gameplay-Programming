#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int x;
    int y;
    int health;
} Player;

void player_move_up(Player* player);
void player_move_down(Player* player);
void player_move_left(Player* player);
void player_move_right(Player* player);
void player_fire(Player* player);
void player_jump(Player* player);
void player_run(Player* player);
void player_crouch(Player* player);
void player_attack(Player* player);
void player_shield(Player* player);

#endif
