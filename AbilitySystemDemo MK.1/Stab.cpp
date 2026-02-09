#include "Stab.h"
#include "Entity.h"
#include "CombatLog.h"

void Stab::Use(Entity& user, Entity& target)
{
    int damage = (user.GetStrength() * 2) / target.GetArmor();

    target.ApplyDamage(damage, "physical");

    currentCooldown = cooldown;
}

