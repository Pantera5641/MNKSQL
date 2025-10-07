#include "database.h"


Database::Database(const std::string& typeName)
{   
    std::string temp = typeName;
    std::transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c){return std::toupper(c);});

    if (temp == "STUDENT22") type = Type::TStudent22;
}

void Database::Add(const std::vector<std::string>& args)
{
    switch (type)
    {
        case Type::TStudent22:
        {
            Student22 var(args);
            db.push_back(var);
            break;
        }
        
        case Type::Unknown:
        {
            break;
        }
    }
}

std::vector<StructVariant> Database::GetVector()
{
    return db;
}
