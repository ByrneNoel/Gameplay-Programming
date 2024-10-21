#include <./include/Player.h>        // Include the Player header
#include <iostream>       // For std::cout
#include <string>         // For std::string

// Method for Player to charge at an enemy
void Player::charge() 
{
    std::cout << name << " charges at the enemy!" << std::endl;
}

// Specific implementation of walk()
void Player::walk()
{
    std::cout << name << " walks forward." << std::endl;
}

// Implementation of pure virtual attack method
void Player::attack(GameObject& target)
{
    std::cout << "Choose an attack:\n1. Basic Attack\n2. Sword Slash\n3. Shield Bash\n4. Defensive Stance\n" ;
    int option;
    std::cin >> option;

    switch (option)
    {
    case 1:
        basicAttack(target);
        break; 
    case 2:
        swordSlash(target);
        break;
    case 3:
        shieldBash(target);
        break;
    case 4:
        defend();
        break;
    default:
        std::cout << "Invalid choice. Defaulting to basic attack" << std::endl;
        basicAttack(target);
        break;
    }
}
void Player::basicAttack(GameObject& target)
{
    std::cout << name << " attacks " << target.getName() << " with a Basic Attacl\n";
    target.takeDamage(7);
}

void Player::swordSlash(GameObject& target)
{
    if (cooldown == 0)
    {
        std::cout << name << " attacks " << target.getName() << " with Sword Slash\n";
        target.takeDamage(15);
        cooldown = 1;
    }

    else
    {
        std::cout << name << "'s Sword Slash is on cooldown for " << cooldown << " more turns.\n";
    }
}

void Player::shieldBash(GameObject& target)
{
    if (cooldown == 0)
    {
        std::cout << name << " attacks " << target.getName() << " with Shield Bash\n";
        target.takeDamage(25);
        cooldown = 2;
    }
}
// Optionally override defend method
void Player::defend() 
{
    std::cout << name << " takes a defensive stance." << std::endl;
    cooldown = 3;
}
