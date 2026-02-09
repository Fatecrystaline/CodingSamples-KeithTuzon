#pragma once
#include <vector>
#include <memory>
#include <string>

#include "StatusEffect.h"
#include "Ability.h"

class Entity {
public:
    Entity(const std::string& name, int hp, int armor, int str, int level);

    void Update(float deltaTime);
    void TryUseAbilities(Entity& target);

    void ApplyDamage(int amount, const std::string& source = "");
    void AddStatusEffect(std::unique_ptr<StatusEffect> effect);
    void AddAbility(std::unique_ptr<Ability> ability);

    bool IsAlive() const;
    
    int GetHP() const;
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
