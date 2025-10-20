#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct SmartFile : public std::fstream
{
    private:
    bool binarMode {};

    std::string readTxt();

    std::string readBin();

    void writeTxt(const std::string& str);

    void writeBin(const std::string& str);

    std::vector<std::string> readAllTxt();

    std::vector<std::string> readAllBin();

    public:
    SmartFile(const std::string& path, std::ios::openmode mode);

    std::string smartRead();
    
    void smartWrite(const std::string& str);

    std::vector<std::string> readAll();
};
