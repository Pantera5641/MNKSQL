#include "fileEvents.h"


std::string getFileNameFromUser(const std::string& menuTitle, const std::string& text, const std::string& extension)
{
    std::vector<std::string> filesList {getFilesList(extension)};
    std::string input {};

    std::vector<std::string> fields {};
    for (int i = 0; i < filesList.size(); i++)
        fields.push_back("(" + std::to_string(i + 1) + ") " + text + "\"" +filesList.at(i) + "\"");
    fields.push_back("(0) Back");
    
    do
    {
        show(LOGO_PATH_DRG, "\033[0;31m");
        showMenu(menuTitle, fields);
        std::cin >> input;
    } 
    while (!inRange(input, 0, filesList.size() + 1));

    if (input == "0") return "none";

    return filesList.at(std::stoi(input) - 1);
}

void saveEvent(bool binaryMode)
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/saveEvent.txt"};

    std::string fileName {};
    bool flag {};

    do 
    {
        std::cout << getParam("enterFilename", path) << std::endl;
        std::cin >> fileName;

        flag = !isContainSpecialSigns(fileName);
        if (flag) 
        {
            std::cout << getParam("invalidFilename", path) << std::endl;
        }
    }
    while (flag);

    binaryMode ? saveBin(fileName) : saveTxt(fileName);
    await();
}

void loadTxtEvent()
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/loadEvent.txt"};

    std::string fileName {getFileNameFromUser(
        getParam("loadTxtMenuTitle", path),
        getParam("loadFrom", path),
        "txt"
        )};

    if (fileName == "none") return;

    rewriteData(loadTxt(fileName));
    
    clear();
    std::cout << getParam("dataLoaded", path) << std::endl;
    await();
}

void loadBinEvent()
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/loadEvent.txt"};

    std::string fileName {getFileNameFromUser(
        getParam("loadBinMenuTitle", path),
        getParam("loadFrom", path),
        "bin"
        )};

    if (fileName == "none") return;

    rewriteData(loadBin(fileName));

    clear();
    std::cout << getParam("dataLoaded", path) << std::endl;
    await();
}

void convertTxtToBinEvent()
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/convertEvent.txt"};

    std::vector<Student> tempList {studentsList};
    std::string fileName {getFileNameFromUser(
        getParam("convertToBinMenuTitle", path),
        getParam("convertFrom", path),
        "txt"
        )};

    if (fileName == "none") return;

    rewriteData(loadTxt(fileName));
    saveBin(fileName);
    rewriteData(tempList);

    clear();
    std::cout << getParam("fileConverted", path) << std::endl;
    await();
}

void convertBinToTxtEvent()
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/convertEvent.txt"};

    std::vector<Student> tempList {studentsList};
    std::string fileName {getFileNameFromUser(
        getParam("convertToTxtMenuTitle", path),
        getParam("convertFrom", path),
        "bin"
        )};

    if (fileName == "none") return;

    rewriteData(loadBin(fileName));
    saveTxt(fileName);
    rewriteData(tempList);

    clear();
    std::cout << getParam("fileConverted", path) << std::endl;
    await();
}