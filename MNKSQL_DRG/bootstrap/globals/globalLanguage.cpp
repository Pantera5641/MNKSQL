#include "globalLanguage.h"


std::string globalLanguage {getParam("language")};


void setLanguage(std::string language)
{
    globalLanguage = language;
    setParam("language", language);
}