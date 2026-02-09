#include "CombatLog.h"
#include <iostream>

std::vector<std::string> CombatLog::messages;

void CombatLog::Log(const std::string& message)
{
    messages.push_back(message);
}

void CombatLog::Flush(float time)
{
    std::cout << "---- Time: " << time << "s ----\n";
    for (const auto& msg : messages)
        std::cout << msg << "\n";

    std::cout << "\n";
    messages.clear();
}
