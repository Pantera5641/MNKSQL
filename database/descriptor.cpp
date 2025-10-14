#include "descriptor.h"


Descriptor::Descriptor(const std::string& argsString)
{
    fill(argsString);
}

void Descriptor::fill(const std::string& argsString)
{
    std::vector<std::string> args = Helper().strip(argsString, SEMICOLON);

    for (std::string item : args)
    {
        if (item.find(LEFT_PARENTHESIS) != std::string::npos)
        {
            fieldNames.push_back(Parser().cutAfter(item, LEFT_PARENTHESIS));
            item = Parser().extractBetween(item, LEFT_PARENTHESIS, RIGHT_PARENTHESIS);
        }
        else
        {
            fieldNames.push_back(item);
            fieldType.push_back(STRING);
            fieldParams.push_back(NONE);
            continue;
        }
        
        if (item.find(LEFT_SQUARE_BRACKET) != std::string::npos)
        {
            fieldType.push_back(Parser().cutAfter(item, LEFT_SQUARE_BRACKET));
            item = Parser().extractBetween(item, LEFT_SQUARE_BRACKET, RIGHT_SQUARE_BRACKET);

            fieldParams.push_back(item);
        }
        else
        {
            fieldType.push_back(item);
            fieldParams.push_back(NONE);
        }
    }
}

Container Descriptor::createContainer(const std::string& fieldsString)
{
    std::vector<std::string> fields = Helper().strip(fieldsString, SEMICOLON);

    return Container(fields);
}

std::vector<std::string> Descriptor::getFieldNames()
{
    return fieldNames;
}

int Descriptor::size()
{
    return fieldNames.size();
}