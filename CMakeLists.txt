cmake_minimum_required(VERSION 3.16)

project(FileArch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(filearch
    src/main.cpp

    src/commands/ShowTreeCommand.cpp
    src/commands/ShowSizeCommand.cpp

    src/core/TreeBuilder.cpp
    src/core/FileSizeAnalyzer.cpp
    src/core/FolderPicker.cpp

    src/utils/IgnoreRules.cpp
)