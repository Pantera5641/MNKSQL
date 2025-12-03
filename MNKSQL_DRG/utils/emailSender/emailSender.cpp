#include "emailSender.h"


void sendEmail(std::string userName, std::string emailAddress, std::string code)
{
    std::string params 
    {
        connect({userName, emailAddress, code, globalLanguage}, ' ')
    };

    #ifdef _WIN32
        system(("EmailSender.exe " + params).c_str());
    #else
        system("chmod +x EmailSender");
        system(("./EmailSender " + params).c_str());
    #endif
}

void sendEmailAsync(std::string userName, std::string emailAddress, std::string code)
{
    std::thread t(sendEmail, userName, emailAddress, code);
    t.detach();
}