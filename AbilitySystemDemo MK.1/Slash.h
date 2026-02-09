#pragma once
#include "Ability.h"

/*
    Slash (Ability)

    Player ability.

    Damage Formula:
        (Strength * 3) / Target Armor

    Applies Bleed to the target.
*/

class Slash : public Ability
{
public:
    Slash()
    {
        cooldownDuration = 3.0f;
    }

    std::string GetName() const override { return "Slash"; }

    void Use(Entity& user, Entity& target) override;
};
