//
// Created by User on 5/24/2025.
//

#include "CartItemView.h"
#include "../model/CartItem.h"
#include "../view/ProductView.h"
#include "../DataBase/CartItemDataBase.h"

void CartItemView::displayCartItem(const CartItem &item) {
    ProductView::displayProduct(item.getItem());
    cout<<"Quantity: "<<item.getQuantity()<<endl;
    cout<<"Sub-Total: $"<<item.getSubTotal()<<endl;
}

void CartItemView::displayCartSummary() {
    vector<CartItem> cartItems;
    cartItems = CartItemDataBase::loadCartItemsFromFile();

    for (const CartItem &item : cartItems) {
        displayCartItem(item);
    }
}

void CartItemView::displayCartTotal() {
    double total = 0.0;
    vector<CartItem> cartItems;
    cartItems = CartItemDataBase::loadCartItemsFromFile();
    for (const CartItem &item : cartItems) {
        total += item.getSubTotal();
    }

    cout<<"Total: $"<<total<<endl;
}
