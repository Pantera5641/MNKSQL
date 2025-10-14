#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "content/constants.h"
#include "logic/helper.h"
#include "logic/parser.h"

#include "container.h"


struct Descriptor
{
    private:
    std::vector<std::string> fieldNames {};
    std::vector<std::string> fieldType {};
    std::vector<std::string> fieldParams {};

    public:
    Descriptor() = default;

    Descriptor(const std::string& argsString);

    void fill(const std::string& argsString);

    Container createContainer(const std::string& fieldsString);

    std::vector<std::string> getFieldNames();

    int size();
};