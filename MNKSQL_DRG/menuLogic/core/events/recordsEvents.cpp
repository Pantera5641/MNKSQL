#include "recordsEvents.h"


void showEvent()
{
    clear();
    showTable();
    await();
}

void addEvent()
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/addEvent.txt"};

    Student student {};
    std::string tempString {};
    bool flag {};

    do
    {
        std::cout << getParam("enterFullName", path) << std::endl;
        std::cin >> student.lastName >> student.firstName >> student.surname;

        flag = !(isContainDigits(student.lastName + student.firstName + student.surname) 
        && isContainSpecialSigns(student.lastName + student.firstName + student.surname));

        if (flag)
        {
            std::cout << getParam("errorNameDigits", path) << std::endl;
        }
    }
    while (flag);

    do
    {
        std::cout << getParam("enterYearOfBirth", path) << std::endl;
        std::cin >> tempString;

        flag = !inRange(tempString, 1900, 2026);
        if (flag)
        {
            std::cout << getParam("errorYearOfBirth", path) << std::endl;
        }
    }
    while (flag);
    student.yearOfBirth = std::stoi(tempString);

    do
    {
        std::cout << getParam("enterYearOfAdmission", path) << std::endl;
        std::cin >> tempString;

        flag = !inRange(tempString, 2000, 2026);
        if (flag)
        {
            std::cout << getParam("errorYearOfAdmission", path) << std::endl;
        }
    }
    while (flag);
    student.yearOfAdmission = std::stoi(tempString);

    do
    {
        std::cout << getParam("enterCourseGroup", path) << std::endl;
        std::cin >> tempString >> student.group;

        flag = !(inRange(tempString, 0, 7) 
        && isContainSpecialSigns(student.group));
        if (flag)
        {
            std::cout << getParam("errorCourseRange", path) << std::endl;
        }
    }
    while (flag);
    student.course = std::stoi(tempString);

    addStudent(student);

    std::cout << getParam("studentAdded", path) << std::endl;

    await();
}

void loadKeyboardEvent()
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/loadKeyboardEvent.txt"};

    std::string numOfStudents {};
    bool isNumInRange {};
    do 
    {
        std::cout << getParam("enterNumOfStudents", path) << std::endl;
        std::cin >> numOfStudents;

        isNumInRange = !inRange(numOfStudents, 1, INT_MAX);
        if (isNumInRange)
        {
            std::cout << getParam("errorNumOfStudents", path) << std::endl;
        }
    }
    while (isNumInRange);

    for (int i = 0; i < std::stoi(numOfStudents); i++)
    {
        addEvent();
    }
}

void editEvent()
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/editEvent.txt"};

    int index {};
    std::string tempString {};
    Student student {};
    bool isEditing { true };
    bool flag {};

    showTable();

    do
    {
        std::cout << getParam("enterEditIndex", path) << std::endl;
        std::cin >> tempString;
    }
    while (!inRange(tempString, 0, studentsList.size() + 1));

    index = std::stoi(tempString);
    if (index == 0) return;

    student = studentsList.at(index - 1);



    while (isEditing)
    {
        clear();

        std::string title {getParam("studentEditMenuTitle", path)};
        std::vector<std::string> fields
        {
            getParam("editingStudent", path),
            connect(getLine(index - 1), ','),
            std::string(),
            getParam("editOptionLastName", path),
            getParam("editOptionYearOfBirth", path),
            getParam("editOptionYearOfAdmission", path),
            getParam("editOptionCourse", path),
            getParam("editOptionGroup", path),
            getParam("editOptionExit", path)
        };

        do 
        {
            show(LOGO_PATH_DRG, "\033[0;31m");
            showMenu(title, fields);
            std::cin >> tempString;
            clear();
        }
        while (!inRange(tempString, 0, 6));


        switch (std::stoi(tempString))
        {
            case 1:
            {
                std::string tempLastName {};
                std::string tempFirstName {};
                std::string tempSurname {};

                do
                {
                    std::cout << getParam("enterFullName", path) << std::endl;
                    std::cin >> tempLastName >> tempFirstName >> tempSurname;

                    flag = !(isContainDigits(tempLastName + tempFirstName + tempSurname) 
                    && isContainSpecialSigns(tempLastName + tempFirstName + tempSurname));
                    if (flag)
                    {
                        std::cout << getParam("errorNameDigits", path) << std::endl;
                    }
                }
                while (flag);

                student.lastName = tempLastName;
                student.firstName = tempFirstName;
                student.surname = tempSurname;

                break;
            }

            case 2:
            {
                do
                {
                    std::cout << getParam("enterYearOfBirth", path) << std::endl;
                    std::cin >> tempString;

                    flag = !inRange(tempString, 1900, 2026);
                    if (flag)
                    {
                        std::cout << getParam("invalidYear", path) << std::endl;
                    }
                }
                while (flag);

                student.yearOfBirth = std::stoi(tempString);
                break;
            }

            case 3:
            {
                do
                {
                    std::cout << getParam("enterYearOfAdmission", path) << std::endl;
                    std::cin >> tempString;

                    flag = !inRange(tempString, 2000, 2026);
                    if (flag)
                    {
                        std::cout << getParam("invalidYear", path) << std::endl;
                    }
                }
                while (flag);

                student.yearOfAdmission = std::stoi(tempString);
                break;
            }

            case 4:
            {
                do
                {
                    std::cout << getParam("enterCourse", path) << std::endl;
                    std::cin >> tempString;

                    flag = !inRange(tempString, 0, 7);
                    if (flag)
                    {
                        std::cout << getParam("errorCourseRange", path) << std::endl;
                    }
                }
                while (flag);

                student.course = std::stoi(tempString);
                break;
            }

            case 5:
            {
                do
                {
                    std::cout << getParam("enterGroup", path) << std::endl;
                    std::cin >> tempString;

                    flag = !isContainSpecialSigns(tempString);
                    if (flag)
                    {
                        std::cout << getParam("errorGroupChars", path) << std::endl;
                    }
                }
                while (flag);

                student.group = tempString;
                break;
            }

            case 0:
            {
                isEditing = false;
                break;
            }
        }

        studentsList.at(index - 1) = student;
    }

    std::cout << getParam("studentEdited", path) << std::endl;
    await();
}

void removeEvent()
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/removeEvent.txt"};

    int index {};
    std::string tempString {};

    showTable();

    do 
    {
        std::cout << getParam("enterRemoveIndex", path) << std::endl;
        std::cin >> tempString;
    }
    while (!inRange(tempString, 0, studentsList.size() + 1));
    index = std::stoi(tempString);

    if (index == 0) return;

    removeStudent(index - 1);

    std::cout << getParam("lineRemoved", path) << std::endl;

    await();
}

void queryEvent()
{
    clear();

    sort({5, 3});
    showTable();
    
    await();
}

void sortEvent()
{
    clear();

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/sortEvent.txt"};


    std::string indexsStr {};
    std::vector<std::string> indexs {};
    bool flag {};

    
    std::string title {getParam("sortMenuTitle", path)};
    std::vector<std::string> fields 
    {
        getParam("sortSelectFields", path),
        std::string(),
        getParam("sortOption1", path),
        getParam("sortOption2", path),
        getParam("sortOption3", path),
        getParam("sortOption4", path),
        getParam("sortOption5", path),
        getParam("sortOption6", path),
        getParam("sortOption7", path)
    };

    if (studentsList.empty()) 
    {
        std::cout << getParam("errorNoRecords", path) << std::endl;
        await();
        return;
    }

    do 
    {
        flag = true;

        show(LOGO_PATH_DRG, "\033[0;31m");
        showMenu(title, fields);
        std::cout << std::endl;
        showTable();
        std::getline(std::cin >> std::ws, indexsStr);

        indexs = strip(indexsStr, ' ');

        if (isDigit(connect(indexs, '0'))) 
        {
            for (int i = 0; i < indexs.size(); i++)
                flag *= inRange(indexs.at(i), 0, 8);
        }
    }
    while (!flag);

    clear();

    sort(changeValuesOn(stripToInt(indexsStr, ' '), -1));
    showTable();

    
    await(true);
}