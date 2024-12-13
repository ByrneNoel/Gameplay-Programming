#ifndef EXPLOSION_EFFECT_H
#define EXPLOSION_EFFECT_H

#include "raylib.h"

class ExplosionEffect {
public:
    ExplosionEffect(Vector2 position, Texture2D texture, int frames, float frameSpeed)
        : pos(position), tex(texture), totalFrames(frames), frameSpeed(frameSpeed)
    {
        currentFrame = 0;
        timeSinceLastFrame = 0.0f;
        frameWidth = tex.width / frames;
        frameHeight = tex.height;
        active = true;
    }

    void update(float dt) 
    {
        if (!active) return;

        timeSinceLastFrame += dt;

        if (timeSinceLastFrame >= frameSpeed) 
        {
            timeSinceLastFrame = 0.0f;
            currentFrame++;

            if (currentFrame >= totalFrames) 
            {
                // Animation finished
                active = false;
            }
        }
    }

    void draw() 
    {
        if (!active) return;

        Rectangle source = { (float)(frameWidth * currentFrame), 0.0f, (float)frameWidth, (float)frameHeight };
        Rectangle dest = { pos.x, pos.y, (float)frameWidth * 2.0f, (float)frameHeight * 2.0f };

       
        Vector2 origin = { (float)frameWidth / 2.0f, (float)frameHeight / 2.0f };

        DrawTexturePro(tex, source, dest, origin, 0.0f, WHITE);
    }

    bool isActive() const { return active; }

private:
    Vector2 pos;
    Texture2D tex;
    int totalFrames;
    int currentFrame;
    float frameSpeed;
    float timeSinceLastFrame;
    int frameWidth, frameHeight;
    bool active;
};

#endif // EXPLOSION_EFFECT_H
