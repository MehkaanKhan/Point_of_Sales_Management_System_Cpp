//
// Created by User on 5/25/2025.
//

#include "Cart.h"

#include "../DataBase/CartDataBase.h"

Cart::Cart() {
    items.clear();
}
Cart::Cart(vector<CartItem> items) {
    this->items = items;
}
void Cart::addItem(const CartItem& item) {
    items = CartDataBase::loadCartFromFile();
    for (CartItem& ci : items) {
        if (ci.getItem().getProductId() == item.getItem().getProductId()) {
            ci.setQuantity(ci.getQuantity() + item.getQuantity());
            CartDataBase::saveCartToFile(items);
            return;
        }
    }
    items.push_back(item);
    CartDataBase::saveCartToFile(items);
}

void Cart::removeItemById(const string& id) {
    // Not used — handled in CartController.
}