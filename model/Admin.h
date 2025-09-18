//
// Created by User on 5/26/2025.
//

#ifndef ADMIN_H
#define ADMIN_H
#include "../model/User.h"

class Admin: public User {
    public:
    Admin();
    Admin(string userId, string name, string password);

    void setRole(const string& role) override;
    string getRole() const override;
};

#endif //ADMIN_H
