#pragma once
class Entity;

class StatusEffect {
public:
    virtual ~StatusEffect() = default;
    virtual void Update(Entity& target, float deltaTime) = 0;
    virtual bool IsExpired() const = 0;
};
