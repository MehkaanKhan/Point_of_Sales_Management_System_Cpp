//
// Created by User on 5/24/2025.
//

#ifndef CARTITEMVIEW_H
#define CARTITEMVIEW_H
#include <vector>

#include "../model/CartItem.h"

class CartItemView {
public:
    static void displayCartItem(const CartItem& item);
    static void displayCartSummary();
    static void displayCartTotal();

};

#endif //CARTITEMVIEW_H
