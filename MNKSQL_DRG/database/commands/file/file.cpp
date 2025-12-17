#include "file.h"

struct BinStudent
{
    char lastName[1000] {};
    char firstName[1000] {};
    char surname[1000] {};
    int yearOfBirth {};
    int yearOfAdmission {};
    int course {};
    char group[1000] {};
};

void saveTxt(const std::string& fileName)
{
    std::fstream file(TO_TABLE_PATH + fileName + ".txt", std::ios::out);
    for (int i = 0; i < studentsList.size(); i++) 
    {
        file << connect(getLine(i), ',') << '\n';
    }
}

void saveBin(const std::string& fileName)
{
    std::fstream file(TO_TABLE_PATH + fileName + ".bin", std::ios::out | std::ios::binary);

    for (int i = 0; i < studentsList.size(); i++)
    {
        Student student {studentsList.at(i)};
        
        BinStudent binStudent {};
        strcpy_s(binStudent.lastName, sizeof(binStudent.lastName), student.lastName.c_str());
        strcpy_s(binStudent.firstName, sizeof(binStudent.firstName), student.firstName.c_str());
        strcpy_s(binStudent.surname, sizeof(binStudent.surname), student.surname.c_str());
        binStudent.yearOfBirth = student.yearOfBirth;
        binStudent.yearOfAdmission = student.yearOfAdmission;
        binStudent.course = student.course;
        strcpy_s(binStudent.group, sizeof(binStudent.group), student.group.c_str());
        
        file.write((char *)&binStudent, sizeof(binStudent));
    }
}

std::vector<std::string> loadTxt(const std::string& fileName)
{
    std::fstream file(TO_TABLE_PATH + fileName + ".txt", std::ios::in);

    std::vector<std::string> rawData {};
    std::string line {};

    while(std::getline(file, line)) 
    {
        rawData.push_back(line);
    }

    return rawData;
}

std::vector<std::string> loadBin(const std::string& fileName)
{
    std::fstream file(TO_TABLE_PATH + fileName + ".bin", std::ios::in  | std::ios::binary);

    std::vector<std::string> rawData {};
    BinStudent binStudent {};

    while (file.read((char *)&binStudent, sizeof(binStudent))) 
    {
        Student student {};
        student.lastName = binStudent.lastName;
        student.firstName = binStudent.firstName;
        student.surname = binStudent.surname;
        student.yearOfBirth = binStudent.yearOfBirth;
        student.yearOfAdmission = binStudent.yearOfAdmission;
        student.course = binStudent.course;
        student.group = binStudent.group;

        rawData.push_back(connect(getLine(student), ','));
    }

    return rawData;
}