#include "descriptor.h"


std::type_index Descriptor::setType(const std::string& typeString)
{
    if (typeString == STRING) {return STRING_TYPE;};
    return INT_TYPE;
}

std::string Descriptor::getType(std::type_index type)
{
    if (type == STRING_TYPE) {return STRING;};
    return INT;
}

Descriptor::Descriptor(const std::string& argsString)
{
    fill(argsString);
}

void Descriptor::fill(const std::string& argsString)
{
    std::vector<std::string> args = Helper().strip(argsString, COMMA);

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
            fieldTypes.push_back(STRING_TYPE);
            fieldParams.push_back(NONE);
            continue;
        }
        
        if (item.find(LEFT_SQUARE_BRACKET) != std::string::npos)
        {
            fieldTypes.push_back(setType(Parser().cutAfter(item, LEFT_SQUARE_BRACKET)));
            item = Parser().extractBetween(item, LEFT_SQUARE_BRACKET, RIGHT_SQUARE_BRACKET);

            fieldParams.push_back(item);
        }
        else
        {
            fieldTypes.push_back(setType(item));
            fieldParams.push_back(NONE);
        }
    }
}

void Descriptor::removeByIndex(int index)
{
    fieldNames.erase(fieldNames.begin() + index);
    fieldTypes.erase(fieldTypes.begin() + index);
    fieldParams.erase(fieldParams.begin() + index);
}

void Descriptor::clear()
{
    fieldNames.clear();
    fieldTypes.clear();
    fieldParams.clear();
}

Container Descriptor::createContainer(const std::string& argsString)
{
    std::vector<std::string> args {Helper().strip(argsString, COMMA)};

    return Container(args);
}

std::vector<std::string> Descriptor::getFieldNames()
{
    return fieldNames;
}

std::vector<std::type_index> Descriptor::getFieldTypes()
{
    return fieldTypes;
}

std::vector<std::string> Descriptor::getFieldParams()
{
    return fieldParams;
}

std::vector<std::string> Descriptor::getAllField()
{
    std::vector<std::string> fields {};
    for (int i = 0; i < size(); i++) 
    {
        std::string name = fieldNames[i] + LEFT_PARENTHESIS;
        std::string type =  getType(fieldTypes[i]) + LEFT_SQUARE_BRACKET;
        std::string param = fieldParams[i] + RIGHT_SQUARE_BRACKET + RIGHT_PARENTHESIS;

        fields.push_back(name + type + param);
    }

    return fields;
}

int Descriptor::size()
{
    return fieldNames.size();
}