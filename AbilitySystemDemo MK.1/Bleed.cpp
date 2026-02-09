#include "Bleed.h"
#include "Entity.h"
#include "CombatLog.h"

/*
    Bleed Implementation

    Separates damage ticking (every second) from logging (every 3 seconds).
    Ensures exactly one log per interval regardless of frame/update rate.
*/


Bleed::Bleed(int damagePerTick)
    : damagePerTick(damagePerTick) {}

void Bleed::Update(Entity& target, float deltaTime)
{
    duration -= deltaTime;
    tickTimer += deltaTime;
    logTimer += deltaTime;

    // Apply 1 damage per second
    while (tickTimer >= 1.0f)
    {
        target.ApplyDamage(damagePerTick);  // do not log here
        accumulatedDamage += damagePerTick;
        tickTimer -= 1.0f;
    }

    // Log accumulated bleed damage every 3 seconds
    if (logTimer >= 3.0f && accumulatedDamage > 0)
    {
        CombatLog::Log(
            target.GetName() + " takes " +
            std::to_string(accumulatedDamage) +
            " bleed damage (HP: " + std::to_string(target.GetHP()) + ")"
        );

        accumulatedDamage = 0;
        logTimer -= 3.0f; // subtract 3s to handle leftover time
    }
}

bool Bleed::IsExpired() const
{
    return duration <= 0.0f;
}
