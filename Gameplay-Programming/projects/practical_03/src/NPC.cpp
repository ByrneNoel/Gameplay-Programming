#include <./include/NPC.h> // Include the NPC header
#include <iostream>        // For std::cout
#include <string>          // For std::string

// Method for NPC to taunt the player
void NPC::taunt()
{
    std::cout << name << " taunts you: 'Is that all you've got?'" << std::endl;
}

// Specific implementation of walk()
void NPC::walk()
{
    std::cout << name << " walks forward." << std::endl;
}

// Implementation of pure virtual attack method
void NPC::attack(GameObject &target)
{
    int option = rand() % 2 + 1;    // random attack
    switch (option)
    {
    case 1:
        flameBreath(target);
        break;
    case 2:
        tailSwipe(target);
        break;
    case 3:
        defend();
        break;
    default:
        flameBreath(target);
        break;
    }
}

void NPC::flameBreath(GameObject& target)
{
    if (cooldown == 0)
    {
        std::cout << name << " attacks " << target.getName() << " with Flame Breath\n";
        target.takeDamage(20);
        cooldown = 3;
    }

    else
    {
        std::cout << name << " ;s Flame Breath is on cooldown for " << cooldown << " more turns\n";
    }
}

void NPC::tailSwipe(GameObject& target)
{
    if (cooldown == 0)
    {
        std::cout << name << " attacks " << target.getName() << " with Tail Swipe\n";
        target.takeDamage(15);
        cooldown = 2;
    }

    else
    {
        std::cout << name << " ;s Tail Swipe is on cooldown for " << cooldown << " more turns\n";
    }
}


// Optionally override defend method
void NPC::defend()
{
    std::cout << name << " uses Scales Of Protection" << std::endl;
    cooldown = 3;
}
