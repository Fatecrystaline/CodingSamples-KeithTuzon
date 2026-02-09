#pragma once
class Entity;

class Ability {
public:
    virtual ~Ability() = default;

    virtual void Use(Entity& user, Entity& target) = 0;

    void UpdateCooldown(float deltaTime);
    bool IsReady() const;

protected:
    float cooldown = 3.0f;
    float currentCooldown = 0.0f;
};
