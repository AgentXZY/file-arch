#include "TreeBuilder.h"
#include "../utils/IgnoreRules.h"

#include <filesystem>
#include <iostream>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

void TreeBuilder::build(const std::string& rootPath)
{
    fs::path root(rootPath);

    std::cout << root.filename().string() << "/\n";

    printTree(rootPath, "", true);
}

void TreeBuilder::printTree(
    const std::string& path,
    const std::string& prefix,
    bool isLast)
{
    std::vector<fs::directory_entry> entries;

    for (const auto& entry : fs::directory_iterator(path))
    {
        std::string name =
            entry.path().filename().string();

        if (IgnoreRules::shouldIgnore(name))
            continue;

        entries.push_back(entry);
    }

    // Sort folders first, then alphabetically
    std::sort(
        entries.begin(),
        entries.end(),
        [](const fs::directory_entry& a,
           const fs::directory_entry& b)
        {
            if (a.is_directory() != b.is_directory())
                return a.is_directory();

            return a.path().filename().string()
                 < b.path().filename().string();
        });

    for (size_t i = 0; i < entries.size(); i++)
    {
        const auto& entry = entries[i];

        bool lastEntry =
            (i == entries.size() - 1);

        std::string name =
            entry.path().filename().string();

        std::cout
            << prefix
            << (lastEntry ? "└── " : "├── ")
            << name
            << '\n';

        if (entry.is_directory())
        {
            printTree(
                entry.path().string(),
                prefix + (lastEntry ? "    " : "│   "),
                lastEntry
            );
        }
    }
}