//
// Created by User on 5/23/2025.
//

#include "UserView.h"
#include <iostream>

using namespace std;

// Prompt the user to enter login credentials
pair<string, string> UserView::promptLogin() {
    string userId, password;

    cout << "Enter User ID: ";
    cin >> userId;

    cout << "Enter Password: ";
    cin >> password;

    return { userId, password };
}

// Prompt the user for registration details
User UserView::promptUserRegistration() {
    string userId, name, password, role;

    cout << "Register New User:\n";

    cout << "Enter User ID: ";
    cin >> userId;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Password: ";
    cin >> password;

    cout << "Enter Role (Admin/Cashier): ";
    cin >> role;

    return User(userId, name, password, role);
}
