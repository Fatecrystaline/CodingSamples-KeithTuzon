#pragma once
#include <string>
#include <vector>

class CombatLog {
public:
    static void Log(const std::string& message);
    static void Flush(float time);

private:
    static std::vector<std::string> messages;
};
