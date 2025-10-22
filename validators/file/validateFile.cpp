#include "validateFile.h"


bool ValidateFile::isTableExists(const std::string& tableName)
{
    std::string path {Path().construct(tableName)};

    return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
}

std::string ValidateFile::checkSaveErrors(const std::string& fileName, const std::string& password)
{
    DataStore& store = DataStore::getInstance();
    if (store.descriptor.size() == 0) 
    {
        return CANNOT_SAVE_EMPTY_DATABASE_ERROR;
    }

    std::string extension {Parser().cutBefore(fileName, DOT)};
    if (extension != "txt" && extension != "bin") 
    {
        return EXTENSION_NOT_ALLOWED_ERROR;
    }

    return NONE;
}

std::string ValidateFile::checkLoadAndRemoveErrors(const std::string& fileName, const std::string& password)
{
    if (isTableExists(fileName) == false) 
    {
        return FILE_NOT_FOUND_ERROR;
    }

    std::string currentPassword {UtilsTable().loadFile(fileName).at(0)};
    if ((LEFT_PARENTHESIS + password + RIGHT_PARENTHESIS) != currentPassword)
    {
        return INCORRECT_PASSWORD_ERROR;
    }

    return NONE;
}