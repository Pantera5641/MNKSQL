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

    Student student {};
    std::string tempString {};
    
    do
    {
        std::cout << "Enter lastname, firstname and surname:" << std::endl;
        std::cin >> student.lastName >> student.firstName >> student.surname;
    }
    while (!isContainDigits(student.lastName + student.firstName + student.surname));

    do 
    {
        std::cout << "Enter yearOfBirth:" << std::endl;
        std::cin >> tempString;
    }
    while (!inRange(tempString, 1900, 2026));
    student.yearOfBirth = std::stoi(tempString);

    do 
    {
        std::cout << "Enter yearOfAdmission:" << std::endl;
        std::cin >> tempString;
    }
    while (!inRange(tempString, 2000, 2026));
    student.yearOfAdmission = std::stoi(tempString);

    do 
    {
        std::cout << "Enter course and group" << std::endl;
        std::cin >> tempString >> student.group;
    }
    while (!inRange(tempString, 0, 7));
    student.course = std::stoi(tempString);

    for (int i = 0; i < 3; i++)
    {
        std::string field {getFieldByIndex(student, i)};
        toUpper(field.at(0));
        student = setFieldByIndex(student, field, i);
    }

    addStudent(student);

    std::cout << "Student added!" << std::endl;

    await();
}

void editEvent()
{
    clear();

    int index {};
    std::string tempString {};
    Student student {};
    Student newStudent {};

    showTable();

    do 
    {
        std::cout << "Enter index of line to edit: (0 - to exit)" << std::endl;
        std::cin >> tempString;
    }
    while (!inRange(tempString, -1, studentsList.size() + 1));
    index = std::stoi(tempString);

    if (index == 0) return;

    clear();
    
    student = studentsList.at(index - 1);

    bool isFieldContainDigits {true};
    do
    {   
        std::cout << "Enter new lastname, firstname and surname: (0 - to skip)" << std::endl;
        std::cin >> newStudent.lastName >> newStudent.firstName >> newStudent.surname;
        isFieldContainDigits = true;

        for (int i = 0; i < 3; i++)
        {
            std::string field {getFieldByIndex(newStudent, i)};
            isFieldContainDigits *= isContainDigits(field) || field == "0";
        }
    }
    while (!(isFieldContainDigits));

    clear();

    do 
    {
        std::cout << "Enter new yearOfBirth: (0 - to skip)" << std::endl;
        std::cin >> tempString;
    }
    while (!(tempString == "0" || inRange(tempString, 1900, 2026)));
    newStudent.yearOfBirth = std::stoi(tempString);

    clear();

    do 
    {
        std::cout << "Enter new yearOfAdmission: (0 - to skip)" << std::endl;
        std::cin >> tempString;
    }
    while (!(tempString == "0" || inRange(tempString, 2000, 2026)));
    newStudent.yearOfAdmission = std::stoi(tempString);

    clear();
    
    do 
    {
        std::cout << "Enter new course and group (0 - to skip)" << std::endl;
        std::cin >> tempString >> newStudent.group;
    }
    while (!(tempString == "0" || inRange(tempString, 0, 7)));
    newStudent.course = std::stoi(tempString);

    for (int i = 0; i < 7; i++)
    {   
        std::string newStudentField {getFieldByIndex(newStudent, i)};

        if (newStudentField != "0")
            student = setFieldByIndex(student, newStudentField, i);
    }

    for (int i = 0; i < 3; i++)
    {
        std::string field {getFieldByIndex(student, i)};
        toUpper(field.at(0));
        student = setFieldByIndex(student, field, i);
    }

    studentsList.at(index - 1) = student;

    std::cout << "Student edited!" << std::endl;

    await();
}

void removeEvent()
{
    clear();

    int index {};
    std::string tempString {};

    showTable();

    do 
    {
        std::cout << "Enter index of line to remove: (0 - to exit)" << std::endl;
        std::cin >> tempString;
    }
    while (!inRange(tempString, -1, studentsList.size() + 1));
    index = std::stoi(tempString);

    if (index == 0) return;

    removeStudent(index - 1);

    std::cout << "Line removed" << std::endl;

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
    addEvent();
    await();
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