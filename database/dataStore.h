#pragma once
#include <vector>
#include <variant>

#include "descriptor.h"
#include "container.h"


struct DataStore
{
    private:
    DataStore() = default;
    ~DataStore() = default;
    DataStore(const DataStore&) = delete;
    DataStore& operator = (const DataStore&) = delete;

    public:
    Descriptor descriptor {};
    std::vector<Container> database {};

    static DataStore& getInstance();

    void newDescriptor(const std::string& argsString);

    std::vector<std::string> getLine(int num);

    std::vector<std::string> getColumn(int num);
};