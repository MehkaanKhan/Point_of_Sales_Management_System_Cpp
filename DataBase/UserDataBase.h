//
// Created by User on 5/23/2025.
//

#ifndef USERDATABASE_H
#define USERDATABASE_H

#include "../model/User.h"
#include <vector>
#include <string>

class UserDataBase {
public:
    static std::vector<User> loadUsersFromFile();         // Load users from CSV file
    static void saveUserToFile(const User& user);         // Save a new user to CSV file
};

#endif //USERDATABASE_H
