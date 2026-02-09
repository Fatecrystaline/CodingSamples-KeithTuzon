#pragma once
#include "StatusEffect.h"

/*
    Bleed (StatusEffect)

    Damage-over-time effect applied by Slash.

    Mechanics:
    - Deals damage every 1 second (ignores armor)
    - Aggregates damage and reports it every 3 seconds
    - Refreshes duration if reapplied instead of stacking

    Demonstrates time-based ticking and event aggregation.
*/


class Bleed : public StatusEffect {
public:
    Bleed(int damagePerTick);

    void Update(Entity& target, float deltaTime) override;
    bool IsExpired() const override;
    
    const char* GetName() const override { return "Bleed"; }
   void Refresh() override { duration = 9.0f; }


private:
    float duration = 9.0f;

    float tickTimer = 0.0f;   // tracks per-second damage ticks
    float logTimer = 0.0f;    // tracks 3-second logging interval

    int damagePerTick;
    int accumulatedDamage = 0;
};
