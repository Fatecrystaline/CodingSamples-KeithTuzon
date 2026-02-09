#include <memory>
#include "Entity.h"
#include "Slash.h"
#include "Stab.h"
#include "CombatLog.h"

int main()
{
    Entity player("Player", 40, 3, 2, 1);
    Entity skeleton("Skeleton", 60, 4, 2, 1);

    player.AddAbility(std::make_unique<Slash>());
    skeleton.AddAbility(std::make_unique<Stab>());

    float time = 0.0f;
    float logTimer = 0.0f;

    while (player.IsAlive() && skeleton.IsAlive())
    {
        player.Update(1.0f);
        skeleton.Update(1.0f);

        player.TryUseAbilities(skeleton);
        skeleton.TryUseAbilities(player);

        time += 1.0f;
        logTimer += 1.0f;

        if (logTimer >= 3.0f)
        {
            CombatLog::Flush(time);
            logTimer = 0.0f;
        }
    }

    CombatLog::Flush(time);

    return 0;
}
