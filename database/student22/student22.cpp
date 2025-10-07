#include "Student22.h"


const std::vector<std::string> Student22::fieldNames = {"id", "name", "lastName", "birthYear", "enrollmentYear", "course", "group"};

Student22::Student22(const std::vector<std::string>& args)
{
    id = std::stoi(args[0]);
    name = args[1];
    lastName = args[2];
    birthYear = std::stoi(args[3]);
    enrollmentYear = std::stoi(args[4]);
    course = args[5];
    group = args[6];
}

void Student22::ChangeID(int num)
{
    id = num;
}

void Student22::Fill(const std::vector<std::string>& args)
{
    name = args[0];
    lastName = args[1];
    birthYear = std::stoi(args[2]);
    enrollmentYear = std::stoi(args[3]);
    course = args[4];
    group = args[5];
}