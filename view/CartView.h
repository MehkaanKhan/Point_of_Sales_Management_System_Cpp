//
// Created by User on 5/25/2025.
//

#ifndef CARTVIEW_H
#define CARTVIEW_H
#include <vector>
#include "../model/CartItem.h"

class CartView {

    public:
    static void displayCart(const std::vector<CartItem> &cart);
    static void showEmptyCartMessage();
    static string promptForProductId();
    static int promptForQuantity();
    static void showClearCartMessage();
    static void showCheckoutSummary(const vector<CartItem> &cart);
};

#endif //CARTVIEW_H
