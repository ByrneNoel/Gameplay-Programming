#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "raylib.h"
#include <string>

// Enum for player states
enum class PlayerState 
{
    IDLE,
    RUNNING_TO_ATTACK,
    ATTACKING,
    DEFENDING,
    USING_MAGIC,
    DEAD
};

class Player : public GameObject
{
private:
    PlayerState state;
    int swordCooldown;
    int shieldCooldown;
    int magicCooldown;

    Texture2D idleTexture;
    Texture2D runningToAttackTexture;
    Texture2D attackingTexture;
    Texture2D defendingTexture;
    Texture2D magicTexture;
    Texture2D deadTexture;

    Vector2 position;


public:
    Player(std::string name, int health = 100, int x = 300, int y = 300);
    ~Player(); // Destructor to unload textures

    void charge();
    void walk() override;
    void attack(GameObject& target) override;
    void basicAttack(GameObject& target);
    void swordSlash(GameObject& target);
    void shieldBash(GameObject& target);
    void defend() override;
    void useMagic(GameObject& target);

    void update();
    void draw();
    void handleInput();
};

#endif // PLAYER_H
