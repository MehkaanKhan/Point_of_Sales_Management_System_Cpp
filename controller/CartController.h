//
// Created by User on 5/25/2025.
//

#ifndef CARTCONTROLLER_H
#define CARTCONTROLLER_H
#include <vector>
#include "../model/CartItem.h"

class CartController {
private:
    static float currentDiscount;
    public:
    static vector<CartItem> loadCart();
    static void saveCart(const vector<CartItem> &cart);
    static void addProductToCart(const CartItem &item);
    static void removeProductFromCart(const CartItem &item);
    static void updateQuantity(const std::string& productId, int newQuantity);
    static void applyDiscount(const float discount);
    static void clearCart();
    static void checkout();
};
#endif //CARTCONTROLLER_H
