#include <./include/GameObject.h>

// Implementation of GameObject Methods

// Getter for name, marked as const
std::string GameObject::getName() const
{
    return name;
}

// Getter for health, marked as const
int GameObject::getHealth() const
{
    return health;
}

int GameObject::getCooldown() const
{
    return cooldown;
}

void GameObject::setCooldown(int cd)
{
    cooldown = cd;
}

bool GameObject::isDefending() const
{
    return defending;
}

void GameObject::setDefending(bool value)
{
    defending = value;
}

void GameObject::defend()
{
    defending = true;
}

// Default walk implementation
void GameObject::walk()
{
    std::cout << name << " GameObject : Walking..." << std::endl;
}

// Default takeDamage implementation
 void GameObject::takeDamage(int damage)
{
    if (defending == true)
    {
        std::cout << name << " is defending and takes no damage!\n";
    }
    else 
    {
        health -= damage;
        std::cout << name << " takes " << damage << " damage and now has " << health << " health left.\n";
    }
 }
