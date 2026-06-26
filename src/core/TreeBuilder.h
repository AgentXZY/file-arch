#pragma once

#include <string>

class TreeBuilder
{
public:
    void build(const std::string& rootPath);

private:
    void printTree(
        const std::string& path,
        const std::string& prefix,
        bool isLast
    );
};