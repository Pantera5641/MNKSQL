#pragma once
#include <iostream>


struct CommandFile
{
    private:
    enum Commands
    {
        Save,
        Load,
        Unknown
    };

    Commands strToAction(const std::string& str);

    void save(const std::string& fileName);

    void load(const std::string& fileName);

    public:
    void execute(const std::vector<std::string>& arr);
};