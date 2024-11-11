#include"../raylib_starter/raylib/src/raylib.h"
#include "stdio.h"
#include "../include/game.h"
#include "../include/constants.h"
#include "../include/collision.h"

// Global Game Variables
static NPC npcs[NUM_NPCS]; // Array of NPCs
static int counter = 0;
static char message[200];

// Function to initialize NPCs
void InitNPCs(NPC npcs[], int count)
{
    for (int i = 0; i < count; i++)
    {
        switch (i % NUM_NPCS)
        { // Cycle through CIRCLE, AABB, LINE
        case 0:
            npcs[i].type = CIRCLE;
            npcs[i].circle.p = c2V(SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 2.0f);
            npcs[i].circle.r = 30.0f;
            npcs[i].color = BLUE;
            break;
        case 1:
            npcs[i].type = AABB;
            npcs[i].aabb = CreateRectangle(300, 150, 50, 80, BLUE);
            npcs[i].color = BLUE;
            break;
        case 2:
            npcs[i].type = LINE;
            npcs[i].line = CreateLine(500.0f, 100.0f, 700.0f, 400.0f, BLUE);
            npcs[i].color = BLUE;
            break;
         case 3:  // Capsule
            npcs[i].type = CAPSULE;
            npcs[i].capsule = CreateCapsule(150, 150, 200, 200, 35, BLUE);
            npcs[i].color = BLUE;
            break;
        case 4:  // Ray
            npcs[i].type = COLLISION_RAY;
            npcs[i].ray = CreateCollisionRay(200, 400, 1, 1, BLUE); 
            npcs[i].color = BLUE;
            break;
        }
    }
}

// Game Initialization
void InitGame()
{
    printf("Game Initialized!\n");
    InitNPCs(npcs, NUM_NPCS); // Initialize NPCs
}

// Game Update Logic
void UpdateGame() {
    Vector2 mousePosition = GetMousePosition();
    c2Circle player;
    player.p = c2V(mousePosition.x, mousePosition.y);
    player.r = 10.0f;

    int collisionDetected = 0; // Flag to track if any collision occurs
    c2Raycast raycastHit;

    // Check for collisions with all NPCs
    for (int i = 0; i < NUM_NPCS; i++) {
        switch (npcs[i].type) {
            case CIRCLE:
                collisionDetected = c2CircletoCircle(npcs[i].circle, player);
                npcs[i].color = (collisionDetected) ? RED : BLUE;
                break;

            case AABB:
                collisionDetected = c2CircletoAABB(player, npcs[i].aabb.aabb);
                npcs[i].aabb.color = (collisionDetected) ? RED : BLUE;
                break;

            case LINE:
                collisionDetected = CircleToLineCollision(player, npcs[i].line);
                npcs[i].line.color = (collisionDetected) ? RED : BLUE;
                break;

            case CAPSULE:
                collisionDetected = c2CircletoCapsule(player, npcs[i].capsule.capsule);
                  npcs[i].color = (collisionDetected) ? RED : BLUE;
                break;

            case COLLISION_RAY:
                collisionDetected = c2RaytoCircle(npcs[i].ray.ray, player,&raycastHit);             
                npcs[i].color = (collisionDetected) ? RED : BLUE;
                break;
        }

        // If any collision is detected, break the loop early
        if (collisionDetected) {
            break; // Exit the loop early if a collision is found
        }
    }

    // Update collision status message after checking all NPCs
    sprintf(message, "Counter : %d Collision : %s", counter, (collisionDetected ? "Collision" : "All Safe"));

    counter++;
}

// Game Drawing Logic
void DrawGame()
{
    ClearBackground(RAYWHITE);

    // Draw Title Message
    const char *title = "Hello, Raylib Collision Starter Kit!";
    int textWidth = MeasureText(title, 20);
    int screenWidth = GetScreenWidth();
    int xPosition = (screenWidth - textWidth) / 2;

    DrawText(title, xPosition, 20, 20, DARKBLUE);

    // Draw Collision Message
    textWidth = MeasureText(message, 20);
    screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    xPosition = (screenWidth - textWidth) / 2;
    int yPosition = screenHeight - 40; // 20 for font 20 Margin

    DrawText(message, xPosition, yPosition, 20, LIGHTGRAY);

    Vector2 mousePosition = GetMousePosition();
    c2Circle player;
    player.p = c2V(mousePosition.x, mousePosition.y);
    player.r = 10.0f;

    // Draw NPCs and Player
    for (int i = 0; i < NUM_NPCS; i++)
    {
        switch (npcs[i].type)
        {
        case CIRCLE:
            DrawCircle(npcs[i].circle.p.x, npcs[i].circle.p.y, npcs[i].circle.r, npcs[i].color);
            break;
        case AABB:
            DrawRectangle(npcs[i].aabb.aabb.min.x, npcs[i].aabb.aabb.min.y,
                          (npcs[i].aabb.aabb.max.x - npcs[i].aabb.aabb.min.x),
                          (npcs[i].aabb.aabb.max.y - npcs[i].aabb.aabb.min.y), npcs[i].aabb.color);
            break;
        case LINE:
            DrawLine((int)npcs[i].line.start.x, (int)npcs[i].line.start.y,
                     (int)npcs[i].line.end.x, (int)npcs[i].line.end.y, npcs[i].line.color);
            DrawCircle((int)npcs[i].line.start.x, (int)npcs[i].line.start.y, 10, npcs[i].line.color);
            DrawCircle((int)npcs[i].line.end.x, (int)npcs[i].line.end.y, 10, npcs[i].line.color);
            break;
        case CAPSULE:
            // Draw the main line segment of the capsule
            DrawLine((int)npcs[i].capsule.capsule.a.x, (int)npcs[i].capsule.capsule.a.y,
                (int)npcs[i].capsule.capsule.b.x, (int)npcs[i].capsule.capsule.b.y, npcs[i].color);

            // Draw the circles at each endpoint of the capsule
            DrawCircle((int)npcs[i].capsule.capsule.a.x, (int)npcs[i].capsule.capsule.a.y, npcs[i].capsule.capsule.r, npcs[i].color);
            DrawCircle((int)npcs[i].capsule.capsule.b.x, (int)npcs[i].capsule.capsule.b.y, npcs[i].capsule.capsule.r, npcs[i].color);

            // Direction vector
            float dx = npcs[i].capsule.capsule.b.x - npcs[i].capsule.capsule.a.x;
            float dy = npcs[i].capsule.capsule.b.y - npcs[i].capsule.capsule.a.y;
            float length = sqrtf(dx * dx + dy * dy);

           
            if (length > 0.0f)
            {
                // Calculate the  direction for the rectangle width
                float perpX = dy * (npcs[i].capsule.capsule.r / length);
                float perpY = -dx * (npcs[i].capsule.capsule.r / length);

               
                Vector2 rectPoints[4] =
                {
                    { npcs[i].capsule.capsule.a.x + perpX, npcs[i].capsule.capsule.a.y + perpY },
                    { npcs[i].capsule.capsule.a.x - perpX, npcs[i].capsule.capsule.a.y - perpY },
                    { npcs[i].capsule.capsule.b.x - perpX, npcs[i].capsule.capsule.b.y - perpY },
                    { npcs[i].capsule.capsule.b.x + perpX, npcs[i].capsule.capsule.b.y + perpY }
                };
                
               
                DrawTriangle(rectPoints[0], rectPoints[1], rectPoints[2], npcs[i].color);
                DrawTriangle(rectPoints[2], rectPoints[3], rectPoints[0], npcs[i].color);
            }
            break;

        case COLLISION_RAY:
             DrawCircle((int)npcs[i].ray.ray.p.x, (int)npcs[i].ray.ray.p.y, 15, npcs[i].color);  // The circle radius is 10

             DrawLine((int)npcs[i].ray.ray.p.x, (int)npcs[i].ray.ray.p.y,
                    (int)(npcs[i].ray.ray.p.x + npcs[i].ray.ray.d.x * 200), 
                    (int)(npcs[i].ray.ray.p.y + npcs[i].ray.ray.d.y * 200), npcs[i].color);
             break;
    
        }
    }

    DrawCircle(player.p.x, player.p.y, player.r, GREEN); // Draw Player

}

// Game Cleanup
void CloseGame()
{
    printf("Game Closed!\n");
}
