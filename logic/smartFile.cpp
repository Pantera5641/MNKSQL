#include "smartFile.h"


SmartFile::SmartFile(const std::string& path, std::ios::openmode mode)
{
    if (path.substr(path.size() - 4) == ".txt")
    {
        this->open(path, mode);
        binarMode = false;
    }
    else
    {
        this->open(path, mode | std::ios::binary);
        binarMode = true;
    }
}

std::string SmartFile::Read()
{
    if (binarMode == false) {return ReadTxt();}
    return ReadBin();
}

void SmartFile::Write(const std::string& str)
{
    if (binarMode == false) {return WriteTxt(str);}
    return WriteBin(str);
}

std::string SmartFile::ReadTxt()
{    
    std::string line {};

    std::getline(*this, line);

    return line;
}

std::string SmartFile::ReadBin()
{
    int len {};
    this->read(reinterpret_cast<char*>(&len), sizeof(len)); 

    std::string str(len, '\0');
    this->read(&str[0], len);

    return str;
}

void SmartFile::WriteTxt(const std::string& str)
{
    *this << str;
}

void SmartFile::WriteBin(const std::string& str)
{
    int len {};

    this->write(reinterpret_cast<char*>(&len), sizeof(len));
    this->write(str.c_str(), len);
}