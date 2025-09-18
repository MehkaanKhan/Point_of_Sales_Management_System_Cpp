//
// Created by User on 5/23/2025.
//

#ifndef USERVIEW_H
#define USERVIEW_H

#include "../model/User.h"
#include <string>
#include <utility>

class UserView {
public:
    static std::pair<std::string, std::string> promptLogin();       // Prompts for userId and password
    static User promptUserRegistration();                            // Prompts for registration data
};


#endif //USERVIEW_H
