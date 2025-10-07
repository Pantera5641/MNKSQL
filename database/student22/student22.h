#pragma once

struct Student22
{
    static const std::vector<std::string> fieldNames;

    int id {};
    std::string name {};
    std::string lastName {};
    int birthYear {};
    int enrollmentYear {};
    std::string course {};
    std::string group {};

    Student22(const std::vector<std::string>& args);

    void ChangeID(int num);

    void Fill(const std::vector<std::string>& args);
};