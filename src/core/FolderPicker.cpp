#include "FolderPicker.h"

#include <iostream>

std::string FolderPicker::pickFolder()
{
    std::string path;

    std::cout << "Enter project path: ";
    std::getline(std::cin, path);

    return path;
}