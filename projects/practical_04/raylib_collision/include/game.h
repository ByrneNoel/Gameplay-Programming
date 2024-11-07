#ifndef GAME_H
#define GAME_H

#include "../raylib_starter/raylib/src/raylib.h"
#include "collision.h"

// Define the number of NPCs
#define NUM_NPCS 5

typedef enum { CIRCLE, AABB, LINE, CAPSULE, COLLISION_RAY } ShapeType;

typedef struct 
{
    ShapeType type;
    c2Circle circle;
    AABBRectangle aabb;
    Line line;
    Capsule capsule;
    CollisionRay ray;
    Color color;
} NPC;

// Function Declarations
void InitGame();
void UpdateGame();
void DrawGame();
void CloseGame();

#endif // GAME_H
