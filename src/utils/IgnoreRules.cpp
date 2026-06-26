#include "IgnoreRules.h"

#include <unordered_set>

bool IgnoreRules::shouldIgnore(
    const std::string& name)
{
    static const std::unordered_set<std::string> ignored =
    {
    ".git",
    ".idea",
    ".vscode",
    ".settings",
    ".classpath",
    ".project",
    "target",
    "build",
    "dist",
    "node_modules"
  };

    return ignored.find(name) != ignored.end();
}