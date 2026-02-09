#include "Entity.h"
#include "Ability.h"
#include "StatusEffect.h"
#include "CombatLog.h"

/*
    Entity Implementation

    Handles updating abilities and status effects each tick.
    Contains logic for refreshing existing status effects instead of stacking.
*/


Entity::Entity(const std::string& name, int hp, int armor, int str, int level)
    : name(name), hp(hp), armor(armor), strength(str), level(level) {}

void Entity::Update(float deltaTime)
{
    for (auto& ability : abilities)
        ability->UpdateCooldown(deltaTime);

    for (auto it = effects.begin(); it != effects.end(); )
    {
        (*it)->Update(*this, deltaTime);
        if ((*it)->IsExpired())
            it = effects.erase(it);
        else
            ++it;
    }
}

void Entity::TryUseAbilities(Entity& target, bool reportStatus)
{
    for (auto& ability : abilities)
    {
        float cd = ability->GetRemainingCooldown();

        if (cd <= 0.0f)
        {
            CombatLog::Log(name + " uses " + ability->GetName() + " on " + target.GetName());
            ability->Use(*this, target);
        }
        else if (reportStatus)
        {
            CombatLog::Log(
                name + "'s " + ability->GetName() +
                " is on cooldown (" + std::to_string((int)cd) + "s remaining)"
            );
        }
    }
}



void Entity::ApplyDamage(int amount, const std::string& source)
{
    hp -= amount;
    if (hp < 0) hp = 0;

    if (!source.empty())
    {
        CombatLog::Log(name + " takes " + std::to_string(amount) + " " + source + " damage (HP: " + std::to_string(hp) + ")");
    }
}

void Entity::TakeDamage(int amount)
{
    hp -= amount;
    if (hp < 0)
        hp = 0;
}


void Entity::AddStatusEffect(std::unique_ptr<StatusEffect> effect)
{
    for (auto& existing : effects)
    {
        if (std::string(existing->GetName()) == effect->GetName())
        {
            existing->Refresh();  // refresh instead of adding
            return;
        }
    }

    effects.push_back(std::move(effect));
}


void Entity::AddAbility(std::unique_ptr<Ability> ability)
{
    abilities.push_back(std::move(ability));
}

bool Entity::IsAlive() const { return hp > 0; }
int Entity::GetArmor() const { return armor; }
int Entity::GetStrength() const { return strength; }
int Entity::GetLevel() const { return level; }
const std::string& Entity::GetName() const { return name; }
