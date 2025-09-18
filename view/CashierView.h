//
// Created by User on 5/26/2025.
//

#ifndef CASHIERVIEW_H
#define CASHIERVIEW_H
#include <string>

class CashierView {
    public:
    static void showCashierMenu();
    static std::string promptProductId();
    static int promptQuantity();
    static float promptDiscount();
    static void showMessage(const std::string &message);
};

#endif //CASHIERVIEW_H
