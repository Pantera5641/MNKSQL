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

std::string SmartFile::smartRead()
{
    if (binarMode == false) {return readTxt();}
    return readBin();
}

void SmartFile::smartWrite(const std::string& str)
{
    if (binarMode == false) {return writeTxt(str);}
    return writeBin(str);
}

std::vector<std::string> SmartFile::readAll()
{
    if (binarMode == false) {return readAllTxt();}
    return readAllBin();
}

std::string SmartFile::readTxt()
{    
    std::string line {};

    std::getline(*this, line);

    return line;
}

std::string SmartFile::readBin()
{
    std::size_t len {};
    std::string line(len, '\0');

    this->read(reinterpret_cast<char*>(&len), sizeof(len));
    this->read(line.data(), len);

    return line;
}

void SmartFile::writeTxt(const std::string& str)
{
    *this << str;
}

void SmartFile::writeBin(const std::string& line)
{
    std::size_t len = line.size();

    this->write(reinterpret_cast<const char*>(&len), sizeof(len));
    this->write(line.data(), len);  
}

std::vector<std::string> SmartFile::readAllTxt()
{
    std::vector<std::string> lines {};
    std::string line {};
    char symbol {};

    while (this->get(symbol))
    {
        if (symbol == '\n')
        {
            lines.push_back(line);
            line.clear();
        }
        else
        {
            line += symbol;
        }
    }
    lines.push_back(line);
    
    return lines;
}

std::vector<std::string> SmartFile::readAllBin()
{
    std::vector<std::string> lines;

    while (this->peek() != EOF) 
    {
        size_t len;
        this->read(reinterpret_cast<char*>(&len), sizeof(len));

        if (this->eof()) break;  // защита на случай неполных данных

        std::string line(len, '\0');
        this->read(line.data(), len);

        lines.push_back(line);
    }

    return lines;
}