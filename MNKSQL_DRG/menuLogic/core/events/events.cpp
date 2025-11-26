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
    std::cout << "Enter lastname, firstname and surname:" << std::endl;
    std::cin >> student.lastName >> student.firstName >> student.surname;

    std::cout << "Enter yearOfBirth:" << std::endl;
    std::cin >> student.yearOfBirth;

    std::cout << "Enter yearOfAdmission, course and group" << std::endl;
    std::cin >> student.yearOfAdmission >> student.course >> student.group;

    addStudent(student);

    std::cout << "Student added!" << std::endl;

    await();
}

void removeEvent()
{
    int index {};

    clear();
    showTable();

    std::cout << "Enter index of line to remove:" << std::endl;
    std::cin >> index;

    removeStudent(index - 1);

    std::cout << "Line removed" << std::endl;

    await();
}

void queryEvent()
{
    clear();

    sort({3, 5});
    showTable();
    
    await();
}

void sortEvent()
{
    clear();
    std::string indexsString {};
    std::cout << "Enter indexs:" << std::endl;
    std::getline(std::cin, indexsString);

    sort(strip(indexsString, ' '));
    showTable();
    
    await();
}