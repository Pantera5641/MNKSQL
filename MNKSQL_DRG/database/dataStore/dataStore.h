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

#include "../helper/helper.h"

extern std::vector<Student> studentsList;


std::string getFieldByIndex(Student student, int index);

Student setFieldByIndex(Student student, const std::string& field, int index);

std::vector<std::string> getColumn(int index);

std::vector<std::string> getLine(Student student);

std::vector<std::string> getLine(int index);

void addStudent(Student student);

void removeStudent(int index);

void sort(const std::vector<int>& indexs);

void rewriteData(const std::vector<Student>& students);

void rewriteData(const std::vector<std::string>& students);