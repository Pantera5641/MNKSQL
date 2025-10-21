#include "validateFile.h"


bool ValidateFile::isTableExists(const std::string& tableName)
{
    std::string path {Path().construct(tableName)};

    return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
}

std::string ValidateFile::checkSaveErrors(const std::string& fileName, const std::string& password)
{
    std::string extension {Parser().cutBefore(fileName, DOT)};
    if (extension != "txt" && extension != "bin") 
    {
        return "ERROR: You cannot use this extension";
    }

    return NONE;
}

std::string ValidateFile::checkLoadAndRemoveErrors(const std::string& fileName, const std::string& password)
{
    if (isTableExists(fileName) == false) 
    {
        return "ERROR: File does not exist";
    }

    std::string currentPassword {UtilsTable().loadFile(fileName).at(0)};
    if ((LEFT_PARENTHESIS + password + RIGHT_PARENTHESIS) != currentPassword)
    {
        return "ERROR: Incorrect password";
    }

    return NONE;
}