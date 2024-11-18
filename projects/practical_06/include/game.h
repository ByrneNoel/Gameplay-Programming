#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "mediator.h"
#include "invoker.h"


typedef struct GameData 
{
    Player player;
    Invoker* invoker;
    Mediator* mediator;
} GameData;


void InitGame(GameData* gameData);
void UpdateGame(GameData* gameData);
void DrawGame(GameData* gameData);
void ExitGame(GameData* gameData);

#endif // GAME_H
