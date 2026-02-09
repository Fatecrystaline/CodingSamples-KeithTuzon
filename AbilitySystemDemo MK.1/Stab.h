#pragma once
#include "Ability.h"

class Stab : public Ability {
public:
    void Use(Entity& user, Entity& target) override;
};
