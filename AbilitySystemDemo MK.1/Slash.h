#pragma once
#include "Ability.h"

class Slash : public Ability {
public:
    void Use(Entity& user, Entity& target) override;
};
