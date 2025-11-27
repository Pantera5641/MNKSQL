#pragma once
#include <iostream>
#include <string>


bool isDigit(char ch);

bool isDigit(const std::string& str);

bool isContainDigits(const std::string& str);

bool inRange(int num, int leftBorder, int rightBorder);

bool inRange(const std::string& numStr, int leftBorder, int rightBorder);