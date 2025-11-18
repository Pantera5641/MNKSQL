#pragma once
#include <string>
#include <vector>


struct Container
{
    private:
    std::vector<std::string> fields {};

    public:
    Container() = delete;
    
    Container(std::vector<std::string> fields);

    std::string getItem(int num);

    std::vector<std::string> getFields();
};