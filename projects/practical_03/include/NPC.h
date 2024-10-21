#ifndef NPC_H
#define NPC_H

#include <./include/GameObject.h> // Include the GameObject header

// NPC is a GameObject
class NPC : public GameObject
{
public:
    NPC(std::string name, int health = 100, int cooldown = 0) : GameObject(name, health, cooldown) {} // Constructor to initialize name and health

    void taunt();                             // Method for NPC to taunt the player
    void walk() override;                     // Specific implementation of walk()
    void attack(GameObject& target) override; // Implementation of pure virtual attack method
    void flameBreath(GameObject& target);     // Attack move
    void tailSwipe(GameObject& target);       // Attack move
    void defend() override;                   // Optionally override defend method
};

#endif // NPC_H
