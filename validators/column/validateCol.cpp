#include "validateCol.h"


bool ValidateCol::checkParamErrors(const std::string& param)
{
    if (param == NONE) 
    {
        return true;
    }

    if (param.find(GREATER_THAN) && std::count(param.begin(), param.end(), GREATER_THAN) == 1)
    {
        bool checkX {Parser().cutAfter(param, GREATER_THAN) == "X"};
        bool checkInt {Helper().isInt(Parser().cutBefore(param,GREATER_THAN))};

        if(checkX == true && checkInt == true)
        {
            return true;
        }
    }

    if (param.find(LESS_THAN) && std::count(param.begin(), param.end(), LESS_THAN) == 1)
    {
        bool checkX {Parser().cutAfter(param, LESS_THAN) == "X"};
        bool checkInt {Helper().isInt(Parser().cutBefore(param,LESS_THAN))};
        
        if(checkX == true && checkInt == true)
        {
            return true;
        }
    }

    if (param.find(LESS_THAN) && std::count(param.begin(), param.end(), LESS_THAN) == 1)
    {
        bool checkX {Parser().extractBetween(param, LESS_THAN, LESS_THAN) == "X"};
        
        std::string cuttedParam {Parser().cutBefore(param,LESS_THAN)};
        bool checkLeftInt {Helper().isInt(cuttedParam)};
        bool checkRightInt {Helper().isInt(Parser().cutBefore(cuttedParam,LESS_THAN))};
        
        if(checkX == true && checkLeftInt == true && checkRightInt == true)
        {
            return true;
        }
    }

    return false;
}

bool ValidateCol::checkSyntaxErrors(const std::string& item)
{
    if ((item.find(LEFT_PARENTHESIS) == std::string::npos) && (item.find(LEFT_SQUARE_BRACKET) == std::string::npos))
    {
        if (item.find(RIGHT_PARENTHESIS) != std::string::npos || item.find(RIGHT_SQUARE_BRACKET) != std::string::npos)
        {
            return false;
        }

        return true;
    }

    if (item.find(LEFT_PARENTHESIS) != std::string::npos && item.find(LEFT_SQUARE_BRACKET) == std::string::npos)
    {
        if (item.find(RIGHT_PARENTHESIS) == std::string::npos || item.find(RIGHT_SQUARE_BRACKET) != std::string::npos)
        {
            return false;
        }

        int countLeftParenthesis = std::count(item.begin(), item.end(), LEFT_PARENTHESIS);
        int countRightParenthesis = std::count(item.begin(), item.end(), RIGHT_PARENTHESIS);
        if (countLeftParenthesis != 1 || countRightParenthesis != 1) 
        {
            return false;
        }

        std::string type {Parser().extractBetween(item, LEFT_PARENTHESIS, RIGHT_PARENTHESIS)};
        if (!(type == STRING || type == INT)) 
        {
            return false;
        }

        return true;
    }

    if (item.find(LEFT_PARENTHESIS) != std::string::npos && item.find(LEFT_SQUARE_BRACKET) != std::string::npos)
    {
        if (item.find(RIGHT_PARENTHESIS) == std::string::npos || item.find(RIGHT_SQUARE_BRACKET) == std::string::npos)
        {
            return false;
        }

        int countLeftParenthesis = std::count(item.begin(), item.end(), LEFT_PARENTHESIS);
        int countRightParenthesis = std::count(item.begin(), item.end(), RIGHT_PARENTHESIS);
        if (countLeftParenthesis != 1 || countRightParenthesis != 1) 
        {
            return false;
        }

        int countLeftSquareBracket = std::count(item.begin(), item.end(), LEFT_SQUARE_BRACKET);
        int countRightSquareBracket = std::count(item.begin(), item.end(), RIGHT_SQUARE_BRACKET);
        if (countLeftSquareBracket != 1 || countRightSquareBracket != 1) 
        {
            return false;
        }

        std::string param {Parser().extractBetween(item, LEFT_SQUARE_BRACKET, RIGHT_SQUARE_BRACKET)};
        if (checkParamErrors(param) == false) 
        {
            return false;
        }

        std::string type {Parser().extractBetween(item, LEFT_PARENTHESIS, LEFT_SQUARE_BRACKET)};
        if (!(type == STRING || type == INT)) 
        {
            return false;
        }

        return true;
    }

    return false;
}

std::string ValidateCol::checkAddErrors(const std::string& argsString)
{
    if (argsString.find(COMMA) == std::string::npos && checkSyntaxErrors(argsString) == true)
    {
        return NONE;
    }

    std::vector<std::string> args = Helper().strip(argsString, COMMA);
    for (std::string item : args)
    {
        if (checkSyntaxErrors(item) == false) 
        {
            return SYNTAX_ERROR;
        }
    }

    return NONE;
}