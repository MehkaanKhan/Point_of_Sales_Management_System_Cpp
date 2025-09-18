//
// Created by User on 5/26/2025.
//

#ifndef CASHIER_H
#define CASHIER_H
#include "../model/User.h"

class Cashier : public User{
    public:
    Cashier();
    Cashier(string userId, string name, string password);

    void setRole(const string& role) override;
    string getRole() const override;
};

#endif //CASHIER_H
