#pragma once
#include <string>
#include <vector>


struct Student 
{
    std::string lastName {};
    std::string firstName {};
    std::string surname {};
    int yearOfBirth {};
    int yearOfAdmission {};
    int course {};
    std::string group {};
};

extern std::vector<Student> studentsList;


std::string getFieldByIndex(Student student, int index);

std::vector<std::string> getColumn(int index);

std::vector<std::string> getLine(int index);

void addStudent(Student student);

void removeStudent(int index);