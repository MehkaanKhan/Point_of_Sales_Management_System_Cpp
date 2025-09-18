//
// Created by User on 5/23/2025.
//

#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string userId;
    string name;
    string password;
    string role;

public:
    User();  // Default constructor
    User(std::string userId, std::string name, std::string password, std::string role);

    // Getters
    string getUserId() const;
    string getName() const;
    string getPassword() const;
    virtual string getRole() const;

    // Setters
    void setUserId(const std::string& id);
    void setName(const std::string& name);
    void setPassword(const std::string& password);
    virtual void setRole(const std::string& role);
};


#endif //USER_H
