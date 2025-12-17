#include "events.h"


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

        flag = !isContainDigits(student.lastName + student.firstName + student.surname);
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

        flag = !inRange(tempString, 0, 7);
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

void editEvent()
{
    clear();

    int index {};
    std::string tempString {};
    Student student {};
    bool isEditing { true };
    bool flag {};

    showTable();

    do
    {
        std::cout << "Enter index of line to edit (0 - exit):" << std::endl;
        std::cin >> tempString;
    }
    while (!inRange(tempString, 0, studentsList.size() + 1));

    index = std::stoi(tempString);
    if (index == 0) return;

    student = studentsList.at(index - 1);



    while (isEditing)
    {
        clear();

        do 
        {
            std::cout << "Editing student:" << std::endl;
            std::cout << connect(getLine(index - 1), ',') << std::endl;

            std::cout << std::endl;
            std::cout << "1 - Edit lastname / firstname / surname" << std::endl;
            std::cout << "2 - Edit year of birth" << std::endl;
            std::cout << "3 - Edit year of admission" << std::endl;
            std::cout << "4 - Edit course" << std::endl;
            std::cout << "5 - Edit group" << std::endl;
            std::cout << "0 - Save and exit" << std::endl;

            std::cin >> tempString;
            clear();
        }
        while (!inRange(tempString, 0, 5));


        switch (std::stoi(tempString))
        {
            case 1:
            {
                std::string tempLastName {};
                std::string tempFirstName {};
                std::string tempSurname {};

                do
                {
                    std::cout << "Enter new lastname, firstname and surname:" << std::endl;
                    std::cin >> tempLastName >> tempFirstName >> tempSurname;

                    flag = !isContainDigits(tempLastName + tempFirstName + tempSurname);
                    if (flag)
                    {
                        std::cout << "Error: names must not contain digits" << std::endl;
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
                    std::cout << "Enter new yearOfBirth:" << std::endl;
                    std::cin >> tempString;

                    flag = !inRange(tempString, 1900, 2026);
                    if (flag)
                    {
                        std::cout << "Error: invalid year" << std::endl;
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
                    std::cout << "Enter new yearOfAdmission:" << std::endl;
                    std::cin >> tempString;

                    flag = !inRange(tempString, 2000, 2026);
                    if (flag)
                    {
                        std::cout << "Error: invalid year" << std::endl;
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
                    std::cout << "Enter new course:" << std::endl;
                    std::cin >> tempString;

                    flag = !inRange(tempString, 0, 7);
                    if (flag)
                    {
                        std::cout << "Error: course must be between 0 and 6" << std::endl;
                    }
                }
                while (flag);

                student.course = std::stoi(tempString);
                break;
            }

            case 5:
            {

                std::cout << "Enter new group:" << std::endl;
                std::cin >> tempString >> student.group;
            
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

    std::cout << "Student edited!" << std::endl;
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

    showTable();

    std::string indexsStr {};
    std::vector<std::string> indexs {};
    bool flag {};

    do 
    {
        flag = true;

        std::cout << "Enter indexs: (indexes start from 1 and field lastname)" << std::endl;
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

    if (studentsList.empty()) 
    {
        showTable();
        await(true);
        return;
    }

    sort(changeValuesOn(stripToInt(indexsStr, ' '), -1));
    showTable();

    
    await(true);
}

void saveTxtEvent()
{
    clear();
    saveTxt("pipa");
    await();
}

void saveBinEvent()
{
    clear();
    saveBin("pipa2");
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

void loadTxtEvent()
{
    clear();
    rewriteData(loadTxt("pipa"));
    await();
}

void loadBinEvent()
{
    clear();
    rewriteData(loadBin("pipa2"));
    await();
}

void convertTxtToBinEvent()
{
    clear();

    std::vector<Student> tempList {studentsList};

    rewriteData(loadTxt("pipa"));
    saveBin("pipa3");
    rewriteData(tempList);

    await();
}

void convertBinToTxtEvent()
{
    clear();

    std::vector<Student> tempList {studentsList};

    rewriteData(loadBin("pipa1"));
    saveTxt("pipa4");
    rewriteData(tempList);

    await();
}

void registrationEvent()
{
    clear();

    std::string email {}, userCode {}, userName {}, password1 {}, password2 {};

    srand(time(NULL));
    std::string code {std::to_string(rand() % (9999 - 1111 + 1) + 1111)};

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/registrationEvent.txt"};

    std::cout << getParam("enterEmail", path);
    std::cin >> email;

    std::fstream file(USERS_PATH, std::ios::in);
    std::string str {};
    while (std::getline(file, str)) 
    {
        if (strip(str, ',').at(1) == email) 
        {
            std::cout << getParam("emailExists", path) << std::endl;
            await();
            return;
        }
    }
    file.close();

    std::cout << getParam("enterUsername", path);
    std::cin >> userName;

    sendEmailAsync(userName, email, code);

    std::cout << getParam("enterOtp", path);
    std::cin >> userCode;

    if (code != userCode) 
    {
        std::cout << getParam("invalidOtp", path) << std::endl;
        await();
        return;
    }

    std::cout << getParam("enterPassword", path);
    std::cin >> password1;

    std::cout << getParam("repeatPassword", path);
    std::cin >> password2;

    if (password1 != password2) 
    {
        std::cout << getParam("passwordsMismatch", path) << std::endl;
        await();
        return;
    }

    file.open(USERS_PATH, std::ios::out | std::ios::app);
    file << userName << ',' << email << ',' << password1 << '\n';
    std::cout << getParam("registrationSuccess", path) << std::endl;

    await();
}

MenuType loginEvent()
{
    clear();

    std::string login {}, password {};
    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/loginEvent.txt"};

    std::cout << getParam("enterLogin", path);
    std::cin >> login;

    std::cout << getParam("enterPassword", path);
    std::cin >> password;

    std::fstream file(USERS_PATH, std::ios::in);
    std::string str {};
    bool flag {};
    while (std::getline(file, str)) 
    {
        std::vector<std::string> userData {strip(str, ',')};
        if (userData.at(0) == login && userData.at(2) == password) 
        {
            flag = true;
        }
    }

    if (flag == true) 
    {
        std::cout << getParam("loginSuccess", path) << std::endl;
        await();
        return MenuType::Admin;
    } 

    std::cout << getParam("loginFailed", path) << std::endl;
    await();
    return MenuType::Main;
}