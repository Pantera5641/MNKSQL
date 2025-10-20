#include "validateFile.h"


bool ValidateFile::isTableExists(const std::string& tableName)
{
    std::string path {Path().construct(tableName)};

    return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
}