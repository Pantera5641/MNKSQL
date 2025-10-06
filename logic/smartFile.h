#pragma once

#include <iostream>
#include <string>
#include <fstream>

class SmartFile : public std::fstream
{
    private:
    bool binarMode {};

    std::string ReadTxt();

    std::string ReadBin();

    void WriteTxt(const std::string& str);

    void WriteBin(const std::string& str);

    std::vector<std::string> ReadAllTxt();

    std::vector<std::string> ReadAllBin();

    public:
    SmartFile(const std::string& path, std::ios::openmode mode);

    std::string Read();
    
    void Write(const std::string& str);

    std::vector<std::string> ReadAll();
};
