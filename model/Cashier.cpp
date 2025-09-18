//
// Created by User on 5/26/2025.
//

#include "Cashier.h"
#include <stdexcept>

Cashier::Cashier() : User("", "", "", "Cashier") {}
Cashier::Cashier(string userId, string name, string password) : User(userId, name, password, "Cashier") {}
void Cashier::setRole(const string& role) {
    if (role == "Cashier")
        this->role = role;
    else
        throw runtime_error("Invalid role for Cashier");
}

string Cashier::getRole() const {
    return this->role;
}

