#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <typeindex>

#include "content/constants.h"
#include "logic/helper.h"
#include "logic/parser.h"

#include "container.h"


struct Descriptor
{
    private:
    std::vector<std::string> fieldNames {};
    std::vector<std::type_index> fieldType {};
    std::vector<std::string> fieldParams {};

    std::type_index getType(const std::string& typeString);

    public:
    Descriptor() = default;

    Descriptor(const std::string& argsString);

    void fill(const std::string& argsString);

    Container createContainer(const std::string& fieldsString);

    std::vector<std::string> getFieldNames();

    int size();
};