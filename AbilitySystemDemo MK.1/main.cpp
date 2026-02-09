#include <memory>
#include "Entity.h"
#include "Slash.h"
#include "Stab.h"
#include "CombatLog.h"

/*
    Combat Simulation Driver

    This file contains no combat logic.

    It simply:
    - Creates entities
    - Assigns abilities
    - Advances time in 1-second steps
    - Flushes the combat log every 3 seconds

    Demonstrates separation between simulation and presentation.
*/


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
    // Tick timers/effects first so cooldown counts down cleanly each second
    player.Update(1.0f);
    skeleton.Update(1.0f);

    // Attempt actions; if on cooldown, report it (because we're logging every second)
    player.TryUseAbilities(skeleton, true);
    skeleton.TryUseAbilities(player, true);

    time += 1.0f;

    CombatLog::Flush(time);
}



    CombatLog::Flush(time);

    return 0;
}

