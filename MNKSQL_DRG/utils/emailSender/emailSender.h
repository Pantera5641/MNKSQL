#include <iostream>
#include <stdlib.h>
#include <string>
#include <thread>

#include "helper/helper.h"
#include "globals/globalLanguage.h"


void sendEmail(std::string userName, std::string emailAddress, std::string code);

void sendEmailAsync(std::string userName, std::string emailAddress, std::string code);