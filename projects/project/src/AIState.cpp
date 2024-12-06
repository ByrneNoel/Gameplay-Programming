#include "AIState.h"
#include "GameObject.h"

void AIState::enter(GameObject* gameObject) 
{
    (void)gameObject;
    // Set initial state for the AI
}

void AIState::execute(GameObject* gameObject)
{
    (void)gameObject;
    // Implement AI logic for decision making and actions
}

void AIState::exit(GameObject* gameObject) 
{
    (void)gameObject;
    // Reset or clean up state if needed
}
