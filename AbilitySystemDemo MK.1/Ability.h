
#pragma once
#include <string>

/*
    Ability (Base Class)

    Represents any action an Entity can perform on a target.

    Responsibilities:
    - Handle cooldown timing
    - Execute custom behavior through polymorphism (Use)
    
    This allows new abilities to be added without changing Entity or main.
*/

class Entity;

class Ability
{
protected:
    float cooldownRemaining = 0.0f;
    float cooldownDuration = 0.0f;

public:
    virtual ~Ability() = default;

    virtual std::string GetName() const = 0;
    virtual void Use(Entity& user, Entity& target) = 0;

    void UpdateCooldown(float dt)
    {
        if (cooldownRemaining > 0.0f)
            cooldownRemaining -= dt;
    }

    bool CanUse() const
    {
        return cooldownRemaining <= 0.0f;
    }

    void StartCooldown()
    {
        cooldownRemaining = cooldownDuration;
    }

    float GetRemainingCooldown() const
    {
        return cooldownRemaining;
    }
};
