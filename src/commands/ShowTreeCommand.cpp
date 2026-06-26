#include "ShowTreeCommand.h"
#include "../core/FolderPicker.h"
#include "../core/TreeBuilder.h"

void ShowTreeCommand::execute()
{
    std::string path = FolderPicker::pickFolder();

    if(path.empty())
        return;

    TreeBuilder builder;
    builder.build(path);
}