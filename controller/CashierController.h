//
// Created by User on 5/26/2025.
//

#ifndef CASHIERCONTROLLER_H
#define CASHIERCONTROLLER_H
#include "CartController.h"
#include "ProductController.h"

class CashierController {
private:
    ProductController productController;
    CartController cartController;

public:
    void addItemToCart();
    void applyDiscount();
    void viewCart();
    void checkout();
    void handleCashierMenu();
};

#endif //CASHIERCONTROLLER_H
