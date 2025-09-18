//
// Created by User on 5/23/2025.
//

#include "User.h"
using namespace std;
User::User() {
    userId = "";
    name = "";
    password = "";
    role = "";
}

User::User(string userId, string name, string password, string role)
    : userId(userId), name(name), password(password), role(role) {
}

string User::getUserId() const {
    return userId;
}

string User::getName() const {
    return name;
}

string User::getPassword() const {
    return password;
}

void User::setUserId(const string& id) {
    userId = id;
}

void User::setName(const string& n) {
    name = n;
}

void User::setPassword(const string& p) {
    password = p;
}
string User::getRole() const {
    return role;
}

void User::setRole(const string& role) {
    this->role = role;
}