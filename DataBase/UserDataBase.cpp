//
// Created by User on 5/23/2025.
//

#include "UserDataBase.h"
#include <fstream>
#include <sstream>
#include "../model/User.h"
using namespace std;

const string FILENAME = "../data_files/users.csv";

// Load all users from file and return them as a vector
vector<User> UserDataBase::loadUsersFromFile() {
    vector<User> users;
    ifstream file(FILENAME);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string userId, name, password, role;

        getline(ss, userId, ',');
        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');

        users.emplace_back(userId, name, password, role);
    }

    file.close();
    return users;
}

// Save a single user to the file
void UserDataBase::saveUserToFile(const User& user) {
    ofstream file(FILENAME, ios::app);  // append mode

    if (file.is_open()) {
        file << user.getUserId() << ","
            << user.getName() << ","
            << user.getPassword() << ","
            << user.getRole() << "\n";
        file.close();
    }
}
