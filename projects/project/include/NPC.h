#ifndef NPC_H
#define NPC_H

#include "GameObject.h"
#include "raylib.h"
#include <string>

enum class NPCState 
{
    IDLE,
    RUNNING_TO_ATTACK,
    ATTACKING,
    DEFENDING,
    USING_MAGIC,
    DEAD
};

class NPC : public GameObject
{
private:
    NPCState state;

    Texture2D idleTexture;
    Texture2D runningToAttackTexture;
    Texture2D attackingTexture;
    Texture2D defendingTexture;
    Texture2D magicTexture;
    Texture2D deadTexture;

    Vector2 position;

public:
    NPC(std::string name, int health = 100, int x = 500, int y = 300);
    ~NPC(); // Destructor to unload textures

    void taunt();
    void walk() override;
    void attack(GameObject& target) override;
    void flameBreath(GameObject& target);
    void tailSwipe(GameObject& target);
    void defend() override;

    void update();
    void draw();
};

#endif // NPC_H