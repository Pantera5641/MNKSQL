#include "dataStore.h"


std::vector<Student> studentsList {};


std::string getFieldByIndex(Student student, int index)
{
    switch (index) 
    {
        case 0:
            return student.lastName;

        case 1:
            return student.firstName;

        case 2:
            return student.surname;

        case 3:
            return std::to_string(student.yearOfBirth);

        case 4:
            return std::to_string(student.yearOfAdmission);

        case 5:
            return std::to_string(student.course);

        case 6:
            return student.group;
    }

    return std::string();
}

Student setFieldByIndex(Student student, const std::string& field, int index)
{
    switch (index) 
    {
        case 0:
            student.lastName = field;
            break;

        case 1:
            student.firstName = field;
            break;

        case 2:
            student.surname = field;
            break;

        case 3:
            student.yearOfBirth = std::stoi(field);
            break;

        case 4:
            student.yearOfAdmission = std::stoi(field);
            break;

        case 5:
            student.course = std::stoi(field);
            break;

        case 6:
            student.group = field;
            break;
    }

    return student;
}

std::vector<std::string> getColumn(int index)
{
    std::vector<std::string> column {};

    for (int i = 0; i < studentsList.size(); i++) 
    {
        column.push_back(getFieldByIndex(studentsList.at(i), index));
    }

    return column;
}

std::vector<std::string> getLine(Student student)
{
    std::vector<std::string> line {
        student.lastName, 
        student.firstName,
        student.surname,
        std::to_string(student.yearOfBirth),
        std::to_string(student.yearOfAdmission),
        std::to_string(student.course),
        student.group
    };

    return line;
}

std::vector<std::string> getLine(int index)
{
    return getLine(studentsList.at(index));
}

void addStudent(Student student)
{
    studentsList.push_back(student);
}

void removeStudent(int index)
{
    studentsList.erase(studentsList.begin() + index);
}

void sort(const std::vector<int>& indexs, bool DESC)
{   
    std::vector<int> reverseIndexs {};

    for (int i = indexs.size() - 1; i >= 0; i--)
    {
        reverseIndexs.push_back(indexs.at(i));
    }
    

    for (int i = 0; i < indexs.size(); i++) 
    {
        bubbleSort(reverseIndexs.at(i), studentsList, DESC);
    }
}


void rewriteData(const std::vector<Student>& students)
{
    studentsList = students;
}

void rewriteData(const std::vector<std::string>& students)
{
    std::vector<Student> newStudentsList {};
    
    for (int i = 0; i < students.size(); i++)
    {
        Student student {};
        std::vector<std::string> fields {strip(students.at(i), ',')};

        student.lastName = fields.at(0);
        student.firstName = fields.at(1);
        student.surname = fields.at(2);
        student.yearOfBirth = std::stoi(fields.at(3));
        student.yearOfAdmission = std::stoi(fields.at(4));
        student.course = std::stoi(fields.at(5));
        student.group = fields.at(6);

        newStudentsList.push_back(student);
    }
    
    rewriteData(newStudentsList);
}