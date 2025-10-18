#pragma once
#include <vector>
#include <string>

#include "dataStore.h"
#include "helper.h"
#include "symbols.h"


struct UtilsRow
{
    public:
    bool inDiapasone(int num, const std::string& argsString);

    bool validator(const std::string& rowElement, int index);
};