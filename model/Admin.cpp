//
// Created by User on 5/26/2025.
//

#include "Admin.h"
#include <stdexcept>

Admin::Admin() : User("", "", "", "Admin") {}
Admin::Admin(string userId, string name, string password) : User(userId, name, password, "Admin") {
}
void Admin::setRole(const string& role) {
    // You can restrict the role to "Admin" only
    if (role == "Admin")
        this->role = role;
    else
        throw runtime_error("Invalid role for Admin");
}
string Admin::getRole() const {
    return this->role;
}