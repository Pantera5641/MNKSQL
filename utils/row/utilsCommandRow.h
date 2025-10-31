#pragma once
#include <vector>
#include <string>
#include <algorithm>

#include "dataStore.h"
#include "helper.h"
#include "symbols.h"
#include "messages.h"


struct UtilsCommandRow
{
    private:
    bool inStringDigits(const std::string& str);

    bool inRange(int num, const std::string& argsString);

    public:
    bool validator(const std::string& rowElement, int index);

    std::string prepareArgs(const std::string& argsString);
};