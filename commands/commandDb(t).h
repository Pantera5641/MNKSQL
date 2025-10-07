#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>

#include "database/database.h"
//?
#include "logic/parser.h"
#include "logic/helper.h"
#include "logic/path.h"
#include "logic/smartFile.h"
#include "content/globals.h"


enum class CommandName
{
    Create,
    Show,
    Delete,
    Unknown
};

struct CommandDb
{
    private:
    CommandName strToAction(const std::string& str);

    void Create(const std::string& typeName);

    void Show(const std::string& fileName);

    void Delete();

    public:
    void Execute(const std::vector<std::string>& arr);
};