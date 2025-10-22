#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "symbols.h"
#include "types.h"
#include "utilsTable.h"
#include "utilsCommandPwd.h"
#include "validatePwd.h"


struct CommandPwd
{
    private:
    enum Commands
    {
        Set,
        Edit,
        Unknown
    };

    Commands strToAction(const std::string& str);

    void set(const std::string& fileName, const std::string& newPassword);

    void edit(const std::string& fileName, const std::string& oldPassword, const std::string& newPassword);

    public:
    void execute(const std::vector<std::string>& items);
};