#pragma once
#include "StatusEffect.h"

class Bleed : public StatusEffect {
public:
    Bleed(int damagePerTick);

    void Update(Entity& target, float deltaTime) override;
    bool IsExpired() const override;

private:
    float duration = 9.0f;

    float tickTimer = 0.0f;   // tracks per-second damage ticks
    float logTimer = 0.0f;    // tracks 3-second logging interval

    int damagePerTick;
    int accumulatedDamage = 0;
};
