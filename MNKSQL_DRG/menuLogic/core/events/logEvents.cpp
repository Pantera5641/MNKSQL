#include "logEvents.h"


void registrationEvent()
{
    clear();

    std::string email {}, userCode {}, userName {}, password1 {}, password2 {};

    srand(time(NULL));
    std::string code {std::to_string(rand() % (9999 - 1111 + 1) + 1111)};

    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/registrationEvent.txt"};

    std::cout << getParam("enterEmail", path);
    std::cin >> email;

    std::fstream file(USERS_PATH, std::ios::in);
    std::string str {};
    while (std::getline(file, str)) 
    {
        if (strip(str, ',').at(1) == email) 
        {
            std::cout << getParam("emailExists", path) << std::endl;
            await();
            return;
        }
    }
    file.close();

    std::cout << getParam("enterUsername", path);
    std::cin >> userName;

    sendEmailAsync(userName, email, code);

    std::cout << getParam("enterOtp", path);
    std::cin >> userCode;

    if (code != userCode) 
    {
        std::cout << getParam("invalidOtp", path) << std::endl;
        await();
        return;
    }

    std::cout << getParam("enterPassword", path);
    std::cin >> password1;

    std::cout << getParam("repeatPassword", path);
    std::cin >> password2;

    if (password1 != password2) 
    {
        std::cout << getParam("passwordsMismatch", path) << std::endl;
        await();
        return;
    }

    file.open(USERS_PATH, std::ios::out | std::ios::app);
    file << userName << ',' << email << ',' << password1 << '\n';
    std::cout << getParam("registrationSuccess", path) << std::endl;

    await();
}

MenuType loginEvent()
{
    clear();

    std::string login {}, password {};
    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/loginEvent.txt"};

    std::cout << getParam("enterLogin", path);
    std::cin >> login;

    std::cout << getParam("enterPassword", path);
    std::cin >> password;

    std::fstream file(USERS_PATH, std::ios::in);
    std::string str {};
    bool flag {};
    while (std::getline(file, str)) 
    {
        std::vector<std::string> userData {strip(str, ',')};
        if (userData.at(0) == login && userData.at(2) == password) 
        {
            flag = true;
        }
    }

    if (flag == true) 
    {
        std::cout << getParam("loginSuccess", path) << std::endl;
        await();
        return MenuType::Admin;
    } 

    std::cout << getParam("loginFailed", path) << std::endl;
    await();
    return MenuType::Main;
}