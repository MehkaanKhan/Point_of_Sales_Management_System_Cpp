//
// Created by User on 5/23/2025.
//

#include "UserController.h"
#include "../view/UserView.h"
#include "../DataBase/UserDataBase.h"
#include "../model/User.h"
#include <iostream>
#include <vector>

using namespace std;

User* UserController::currentUser = nullptr;


bool UserController::handleLogin()                  // Returns true if login successful
{
    auto credentials = UserView::promptLogin();
    string enteredId = credentials.first;
    string enteredPassword = credentials.second;

    vector<User> users = UserDataBase::loadUsersFromFile();

    for (const auto& user : users) {
        if (user.getUserId() == enteredId && user.getPassword() == enteredPassword) {
            currentUser = new User(user);

            cout << "Login successful! Welcome, " << user.getName() << "." << endl;
            return true;
        }

    }

    // If no match is found, show an error message
    //cout << "Invalid credentials. Try again." << endl;
    return false;
}
void UserController::registerUser()                  // Adds new user (admin only)
{
    User newUser = UserView::promptUserRegistration();
    UserDataBase::saveUserToFile(newUser);

    cout << "User registered successfully!" << endl;
}
User* UserController::getCurrentUser() {
    if (currentUser == nullptr) {
        throw std::runtime_error("No user currently logged in.");
    }
    return currentUser;
}

void UserController::logout() {
    if (currentUser != nullptr) {
        delete currentUser;  // If you allocated dynamically, else skip
        currentUser = nullptr;
    }
}

bool UserController::isAdmin() {
    if (!isLoggedIn()) return false;
    return currentUser->getRole() == "Admin";
}

bool UserController::isLoggedIn() {
    return currentUser != nullptr;
}