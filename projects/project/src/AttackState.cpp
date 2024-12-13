#include "AttackState.h"
#include "IdleState.h" 
#include "NPC.h"
#include "Player.h"
#include <iostream>
#include "AudioResources.h"
#include <cmath> 



extern Sound swordSlash;

void AttackState::enter(GameObject* entity)
{
    // Store starting position
    startPosition = entity->getPosition();

    // Get target position
    GameObject* target = entity->getTarget();
    if (!target) {
        // If no target, just return to Idle
        entity->changeState(new IdleState());
        return;
    }

    targetPosition = target->getPosition();

    // Start with the approach phase
    phase = AttackPhase::APPROACH;
    damageDealt = false;

    // Set run animation for approach phase
    if (entity->isPlayer()) 
    {
        entity->setAnimation("running", "assets/playerRun.png", 7);
    }
    else 
    {
        entity->setAnimation("running", "assets/npcRun.png", 7);
    }

    entity->setCurrentFrame(0);
    entity->setTimeSinceLastFrame(0.0f);
    entity->setFrameSpeed(0.1f);

    std::cout << entity->getName() << " begins attacking and moves towards the target!" << std::endl;
}
void AttackState::execute(GameObject* entity)
{
    float dt = GetFrameTime();
    Vector2 pos = entity->getPosition();

    switch (phase)
    {
    case AttackPhase::APPROACH:
    {
        // Move towards targetPosition
        Vector2 direction = { targetPosition.x - pos.x, targetPosition.y - pos.y };
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        entity->updateAnimation();

        if (distance > 50.0f) 
        {
           
            direction.x /= distance;
            direction.y /= distance;

            pos.x += direction.x * moveSpeed * dt;
            pos.y += direction.y * moveSpeed * dt;
            entity->setPosition(pos);
        }
        else
        {
            // Close enough to target, make attack animation
            phase = AttackPhase::ANIMATING;
            damageDealt = false;

            if (entity->isPlayer())
            {
                entity->setAnimation("attack", "assets/playerAttack.png", 6);
            }
            else 
            {
                entity->setAnimation("attack", "assets/npcAttack.png", 6);
            }

            entity->setCurrentFrame(0);
            entity->setTimeSinceLastFrame(0.0f);
            entity->setFrameSpeed(0.1f);
            std::cout << entity->getName() << " starts attacking!" << std::endl;
        }

        break;
    }
    case AttackPhase::ANIMATING:
    {
        entity->updateAnimation();

        if (!damageDealt)
        {
            GameObject* target = entity->getTarget();
            if (target)
            {
                bool targetDefending = target->isDefending();
                if (targetDefending)
                {
                    PlaySound(swordSlash);
                    std::cout << target->getName() << " is defending and takes no damage!" << std::endl;
                }
                else
                {
                    int damage = 15;
                    if (entity->isPlayer()) 
                    {
                        NPC* targetNPC = static_cast<NPC*>(target);
                        PlaySound(swordSlash);
                        targetNPC->takeDamage(damage);
                        std::cout << entity->getName() << " attacks " << targetNPC->getName()
                            << " for " << damage << " damage! Target health: " << targetNPC->getHealth() << std::endl;
                    }
                    else {
                        Player* targetPlayer = static_cast<Player*>(target);
                        PlaySound(swordSlash);
                        targetPlayer->takeDamage(damage);
                        std::cout << entity->getName() << " attacks " << targetPlayer->getName()
                            << " for " << damage << " damage! Target health: " << targetPlayer->getHealth() << std::endl;
                    }
                }
            }
            damageDealt = true;
        }

        // Once attack animation finishes, retreat
        if (entity->isAnimationComplete())
        {
            std::cout << entity->getName() << " finishes the attack and retreats!" << std::endl;
            phase = AttackPhase::RETREAT;

            // Set running animation for retreat
            if (entity->isPlayer()) 
            {
                entity->setAnimation("running", "assets/playerRun.png", 7);
            }
            else 
            {
                entity->setAnimation("running", "assets/npcRun.png", 7);
            }

            entity->setCurrentFrame(0);
            entity->setTimeSinceLastFrame(0.0f);
            entity->setFrameSpeed(0.1f);

            entity->completeAction(); // Action is done; just need to return to original position now
        }

        break;
    }
    case AttackPhase::RETREAT:
    {
        entity->updateAnimation();

        Vector2 direction = { startPosition.x - pos.x, startPosition.y - pos.y };
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distance > 1.0f)
        {
            // Normalize direction
            direction.x /= distance;
            direction.y /= distance;

            pos.x += direction.x * moveSpeed * dt;
            pos.y += direction.y * moveSpeed * dt;
            entity->setPosition(pos);
        }
        else
        {
            // Reached original position, go idle
            entity->setPosition(startPosition);
            entity->changeState(new IdleState());
        }

        break;
    }
    }
}
void AttackState::exit(GameObject* entity)
{
    std::cout << entity->getName() << " exits ATTACK state!" << std::endl;
}

void AttackState::draw(GameObject* entity)
{
    entity->draw();
}
