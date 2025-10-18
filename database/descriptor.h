#pragma once
#include <string>
#include <vector>
#include <typeindex>

#include "symbols.h"
#include "types.h"
#include "helper.h"
#include "parser.h"

#include "container.h"


struct Descriptor
{
    private:
    std::vector<std::string> fieldNames {};
    std::vector<std::type_index> fieldTypes {};
    std::vector<std::string> fieldParams {};

    std::type_index setType(const std::string& typeString);

    std::string getType(std::type_index type);

    public:
    Descriptor() = default;

    Descriptor(const std::string& argsString);

    void fill(const std::string& argsString);

    void clear();

    Container createContainer(const std::string& argsString);

    std::vector<std::string> getFieldNames();

    std::vector<std::type_index> getFieldTypes();

    std::vector<std::string> getFieldParams();

    std::vector<std::string> getAllField();

    int size();
};