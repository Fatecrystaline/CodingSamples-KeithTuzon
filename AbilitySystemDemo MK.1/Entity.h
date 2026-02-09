#pragma once
#include <vector>
#include <memory>
#include <string>

#include "StatusEffect.h"
#include "Ability.h"

/*
    Entity

    Represents any combat participant (Player, Skeleton, NPC, etc).

    Holds:
    - Core stats (HP, Armor, Strength, Level)
    - Active abilities
    - Active status effects

    Responsible for:
    - Updating cooldowns and effects every tick
    - Preventing duplicate status effects (refresh instead of stacking)
    - Acting as the core unit in the combat simulation
*/


class Entity {
public:
    Entity(const std::string& name, int hp, int armor, int str, int level);

    void Update(float deltaTime);
    void TryUseAbilities(Entity& target, bool reportStatus);
   
    void TakeDamage(int amount);

    void ApplyDamage(int amount, const std::string& source = "");
    void AddStatusEffect(std::unique_ptr<StatusEffect> effect);
    void AddAbility(std::unique_ptr<Ability> ability);

    bool IsAlive() const;
    
   // HP accessor (inline)
   int GetHP() const { return hp; }
    int GetArmor() const;
    int GetStrength() const;
    int GetLevel() const;
    const std::string& GetName() const;

private:
    std::string name;
    int hp;
    int armor;
    int strength;
    int level;

    std::vector<std::unique_ptr<Ability>> abilities;
    std::vector<std::unique_ptr<StatusEffect>> effects;
};
