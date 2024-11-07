#ifndef COLLISION_H
#define COLLISION_H

#include <math.h>
#include <stdbool.h>

#include "../cute_headers/cute_c2.h"

// AABBRectangle
typedef struct {
    c2AABB aabb;    // Axis-Aligned Bounding Box
    Color color;    // Color for rendering
} AABBRectangle;

// Line
typedef struct {
    c2v start;
    c2v end;
    Color color;    // Color for rendering
} Line;

typedef struct
{
    c2Capsule capsule;
    Color color;
} Capsule;

typedef struct {
    c2Ray ray;
    Color color;    // Color for rendering
} CollisionRay;

// CircleToLineCollision
bool CircleToLineCollision(const c2Circle circle, const Line line);

// Function to create a Rectangle
AABBRectangle CreateRectangle(const float x, const float y, const float width, const float height, const Color color);

// Function to create a Line
Line CreateLine(const float startX, const float startY, const float endX, const float endY, const Color color);

// functions to create Capsule and Ray
Capsule CreateCapsule(const float startX, const float startY, const float endX, const float endY, const float radius, const Color color);
CollisionRay CreateCollisionRay(const float startX, const float startY, const float dx, const float dy, const Color color);
#endif // COLLISION_H