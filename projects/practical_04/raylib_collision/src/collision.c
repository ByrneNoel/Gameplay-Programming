#include "../raylib_starter/raylib/src/raylib.h"
#include "stdio.h"

// Specific define for CUTE_HEADERS
#define CUTE_C2_IMPLEMENTATION

#include "../include/collision.h"

bool CircleToLineCollision(const c2Circle circle, const Line line) {
    
    // Vector from line start to line end
    c2v d = c2Sub(line.end, line.start);
    
    // Vector from line start to circle center
    c2v f = c2Sub(circle.p, line.start);
    
    // Calculate length squared of line segment
    float d_squared = d.x * d.x + d.y * d.y;
    
    // Avoid division by zero if line segment has zero length
    if (d_squared == 0.0f) {
        // In this case, just check distance to start point
        float dist_squared = f.x * f.x + f.y * f.y;
        return dist_squared <= circle.r * circle.r;
    }
    
    // Project f onto d to get position along line segment (parameter t)
    float t = (f.x * d.x + f.y * d.y) / d_squared;
    
    // Clamp t to [0,1] to get nearest point on line segment
    t = t < 0.0f ? 0.0f : (t > 1.0f ? 1.0f : t);
    
    // Calculate closest point on line
    c2v closest = {
        line.start.x + t * d.x,
        line.start.y + t * d.y
    };
    
    // Calculate vector from closest point to circle center
    c2v diff = c2Sub(circle.p, closest);
    
    // Check if distance is less than or equal to radius
    float dist_squared = diff.x * diff.x + diff.y * diff.y;
    return dist_squared <= circle.r * circle.r;
}

// Function to create a rectangle
AABBRectangle CreateRectangle(const float x, const float y, const float width, const float height, const Color color) {
    AABBRectangle rect;
    rect.aabb.min = c2V(x, y);
    rect.aabb.max = c2V(x + width, y + height);
    rect.color = color;
    return rect;
}

// Function to create a Line
Line CreateLine(const float startX, const float startY, const float endX, const float endY, const Color color) 
{
    Line line;
    line.start = c2V(startX, startY);
    line.end = c2V(endX, endY);
    line.color = color;
    return line;
}

Capsule CreateCapsule(const float startX, const float startY, const float endX, const float endY, const float radius, const Color color) 
{
    Capsule capsule;
    capsule.capsule.a = c2V(startX, startY);
    capsule.capsule.b = c2V(endX, endY);
    capsule.capsule.r = radius;
    capsule.color = color;
    return capsule;
}

CollisionRay CreateCollisionRay(const float startX, const float startY, const float dx, const float dy, const Color color)
 {
    CollisionRay ray;
    ray.ray.p = c2V(startX, startY);
    ray.ray.d = c2V(dx, dy);  // Direction 
    ray.color = color;
    return ray;
}