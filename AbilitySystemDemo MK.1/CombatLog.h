#pragma once
#include <string>
#include <vector>

/*
    CombatLog

    Centralized logging system for the combat simulation.

    All gameplay systems (Entity, Ability, StatusEffect) write messages here
    instead of printing directly to the console. This keeps presentation
    decoupled from game logic and allows logs to be flushed at controlled
    intervals (every 3 seconds in main).

    This mimics how real engines separate simulation from reporting/debug output.
*/


class CombatLog {
public:
    static void Log(const std::string& message);
    static void Flush(float time);

private:
    static std::vector<std::string> messages;
};
