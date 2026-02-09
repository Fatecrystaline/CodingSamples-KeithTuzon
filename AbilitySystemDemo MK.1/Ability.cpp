#include "Ability.h"

void Ability::UpdateCooldown(float deltaTime)
{
    if (currentCooldown > 0.0f)
        currentCooldown -= deltaTime;
}

bool Ability::IsReady() const
{
    return currentCooldown <= 0.0f;
}
