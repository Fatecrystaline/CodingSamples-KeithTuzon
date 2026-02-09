#include "Slash.h"
#include "Entity.h"
#include "Bleed.h"
#include "CombatLog.h"

void Slash::Use(Entity& user, Entity& target)
{
    int damage = (user.GetStrength() * 3) / target.GetArmor();

    target.ApplyDamage(damage, "physical");  // log immediately as physical damage

    // Apply bleed
    target.AddStatusEffect(std::make_unique<Bleed>(user.GetLevel()));

    currentCooldown = cooldown;
}

