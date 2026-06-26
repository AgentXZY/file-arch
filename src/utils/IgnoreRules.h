#pragma once

#include <string>

class IgnoreRules
{
public:
    static bool shouldIgnore(
        const std::string& name
    );
};