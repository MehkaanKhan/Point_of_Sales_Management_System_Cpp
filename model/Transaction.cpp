//
// Created by User on 5/26/2025.
//


#include "Transaction.h"
#include <sstream>
#include <iomanip>

Transaction::Transaction(std::string billId, vector<CartItem> items, float totalAmount, float discount) {
    this->billId = billId;
    this->items = items;
    this->totalAmount = totalAmount;
    this->discount = discount;

    // Get current time
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::ostringstream oss;
    oss << std::put_time(ltm, "%Y-%m-%d %H:%M:%S");
    timeStamp = oss.str();
}

std::string Transaction::getBillId() const {
    return billId;

}
vector<CartItem> Transaction::getItems() const {
    return items;

}
float Transaction::getTotalAmount() const {
    return totalAmount;
}
float Transaction::getDiscount() const {
    return discount;
}
float Transaction::getFinalAmount() const {
    return totalAmount - (totalAmount * discount/100.0f);
}
std::string Transaction::getTimestamp() const {
    return timeStamp;
}
