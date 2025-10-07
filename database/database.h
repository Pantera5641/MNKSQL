#pragma once

#include <any>
#include <algorithm>
#include <string>
#include <vector>
#include <variant>
#include <cctype>

#include "student22/student22.h"

using StructVariant = std::variant<Student22>;


struct Database
{
    private:
    enum Type
    {
        TStudent22,
        Unknown
    };

    Type type = Type::Unknown;
    std::vector<StructVariant> db {};

    public:
    Database(const std::string& typeName);

    void Add(const std::vector<std::string>& args);

    std::vector<StructVariant> GetVector();
};
