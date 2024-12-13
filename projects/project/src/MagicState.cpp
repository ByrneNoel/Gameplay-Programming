#include "MagicState.h"
#include "IdleState.h"
#include "NPC.h"
#include "Player.h"
#include <iostream>
#include "AudioResources.h"
#include <vector>
#include "ExplosionEffect.h"

extern Sound magicCast;
extern std::vector<ExplosionEffect> explosions;

extern Texture2D explosionTexture;

const int halfSpriteWidth = 432; 
const int halfSpriteHeight = 24;  
const int additionalYOffset = 40;  
const int xOffsetAdjustment = 500;
const int npcxOffsetAdjustment = 250;


void MagicState::enter(GameObject* entity)
{
    entity->setCurrentFrame(0);
    entity->setTimeSinceLastFrame(0.0f);
    entity->setFrameSpeed(0.15f);

    if (entity->isPlayer())
    {
        entity->setAnimation("magic", "assets/playerMagic.png", 6);
    }
    else
    {
        entity->setAnimation("magic", "assets/npcMagic.png", 6);
    }

    std::cout << entity->getName() << " begins casting magic!" << std::endl;
}



void MagicState::execute(GameObject* entity)
{
    entity->updateAnimation();

    static bool damageDealt = false;
    if (!damageDealt)
    {
        PlaySound(magicCast);
        GameObject* target = entity->getTarget();
        if (target)
        {
            bool targetDefending = target->isDefending();
            int magicDamage = 20;

            if (entity->isPlayer())
            {
                NPC* targetNPC = static_cast<NPC*>(target);

                if (targetDefending) 
                {
                    PlaySound(magicCast);
                    std::cout << targetNPC->getName() << " is defending and takes no magic damage!" << std::endl;
                }

                else 
                {
                    targetNPC->takeDamage(magicDamage);
                    PlaySound(magicCast);
                    std::cout << entity->getName() << " casts a powerful spell on "
                        << targetNPC->getName() << " for " << magicDamage
                        << " damage! Target health: " << targetNPC->getHealth() << std::endl;
                }

                Vector2 explosionPos = targetNPC->getPosition();
                explosionPos.x += (halfSpriteWidth - xOffsetAdjustment); 
                explosionPos.y += (halfSpriteHeight + additionalYOffset); 

                // Spawn explosion at NPC's position
                explosions.emplace_back(explosionPos, explosionTexture, 8, 0.08f);
            }
            else
            {
                Player* targetPlayer = static_cast<Player*>(target);
                if (targetDefending)
                {
                    PlaySound(magicCast);
                    std::cout << targetPlayer->getName() << " is defending and takes no magic damage!" << std::endl;
                }
                else
                {
                    targetPlayer->takeDamage(magicDamage);
                    PlaySound(magicCast);
                    std::cout << entity->getName() << " casts a powerful spell on "
                        << targetPlayer->getName() << " for " << magicDamage
                        << " damage! Target health: " << targetPlayer->getHealth() << std::endl;
                }

                Vector2 explosionPos = targetPlayer->getPosition();
                explosionPos.x += (halfSpriteWidth - npcxOffsetAdjustment);
                explosionPos.y += (halfSpriteHeight + additionalYOffset);

                // Spawn explosion at Player's position
                explosions.emplace_back(explosionPos, explosionTexture, 8, 0.08f);
            }
        }
        damageDealt = true;
    }

    // Complete action after animation finishes
    if (entity->isAnimationComplete())
    {
        entity->completeAction();
        entity->changeState(new IdleState());
        damageDealt = false;
    }
}


void MagicState::exit(GameObject* entity)
{
    std::cout << entity->getName() << " finishes casting magic!" << std::endl;
}

void MagicState::draw(GameObject* entity)
{
    entity->draw();
}
