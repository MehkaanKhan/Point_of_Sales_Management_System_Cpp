//
// Created by User on 5/26/2025.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <vector>
#include <string>
#include <ctime>

#include "CartItem.h"
using namespace std;

class Transaction {
private:
    std::string billId;
    vector<CartItem> items;
    float totalAmount;
    float discount;
    std::string timeStamp;

    public:
    Transaction(std::string billId, vector<CartItem> items, float totalAmount, float discount);

    std::string getBillId() const;
    vector<CartItem> getItems() const;
    float getTotalAmount() const;
    float getDiscount() const;
    float getFinalAmount() const;
    std::string getTimestamp() const;
};
#endif //TRANSACTION_H
