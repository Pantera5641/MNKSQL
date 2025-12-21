#include "helper.h"


std::string repeat(int num, char item)
{
    std::string result {};

    for (int i = 0; i < num; i++)
    {
        result+= item;
    }
    
    return result;
}

std::string cutAfter(const std::string& line, char item)
{
    int index = line.find_first_of(item);
    std::string result = line.substr(0, index);

    return result;
}

std::string cutBefore(const std::string& line, char item)
{
    int index = line.find_first_of(item);
    std::string result = line.substr(index + 1);

    return result;
}

std::vector<std::string> strip(const std::string& str, char toRemove)
{
    std::vector<std::string> list {};
    std::string item {};

    std::istringstream iss(str);

    while (std::getline(iss, item, toRemove))
    {
        item.erase(std::remove(item.begin(), item.end(), toRemove), item.end());
        list.push_back(item);
    }

    return list;
}

std::vector<int> stripToInt(const std::string& str, char toRemove)
{
    std::vector<std::string> strings {strip(str, toRemove)};
    std::vector<int> ints {};

    for (int i = 0; i < strings.size(); i++)
    {
        ints.push_back(std::stoi(strings.at(i)));
    }
    
    return ints;
}

void bubbleSort(int index, std::vector<Student>& list, bool DESC) 
{
    for (int i = 0; i < list.size() - 1; i++) 
    {
        bool swapped {};
        for (int j = 0; j < list.size() - i - 1; j++) 
        {
            std::string a {getFieldByIndex(list.at(j), index)};
            std::string b {getFieldByIndex(list.at(j + 1), index)};
            if ((DESC && a < b) || (!DESC && a > b)) 
            {
                Student temp = list.at(j);
                list.at(j) = list.at(j + 1);
                list.at(j + 1) = temp;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

std::string connect(const std::vector<std::string>& vector, char item)
{
    std::string line {};

    for (int i = 0; i < vector.size() - 1; i++)
    {
        line += vector.at(i) + item;
    }

    line += vector.back();

    return line;
}

std::vector<int> changeValuesOn(const std::vector<int>& nums, int on)
{
    std::vector<int> newNums {};
    for (int i = 0; i < nums.size(); i++) 
    {
        newNums.push_back(nums.at(i) + on);
    }

    return newNums;
}

int getMaxValue(const std::vector<int>& nums)
{
    int maxValue {};

    for (int i = 0; i < nums.size(); i++) 
        maxValue = nums.at(i) > maxValue ? nums.at(i) : maxValue;

    return maxValue;
}

int getMaxLength(const std::vector<std::string>& items)
{
    std::vector<int> lengths {};

    for (int i = 0; i < items.size(); i++) 
        lengths.push_back(utf8Length(items.at(i)));

    return getMaxValue(lengths);
}

int utf8Length(const std::string& str)
{
    int count {};

    for (int i = 0; i < str.size(); i++) 
    {
        unsigned char ch = static_cast<unsigned char>(str[i]);
        if ((ch & 0b11000000) != 0b11000000) 
            count++;
    }

    return count;
}