//
// Created by User on 5/25/2025.
//

#ifndef CART_H
#define CART_H
#include <iostream>
#include <vector>
using namespace std;
#include <string>
#include "CartItem.h"

class Cart
{
private:
    vector<CartItem> items;
    double discount;

public:
    Cart();
    Cart(vector<CartItem>);
    void addItem(const CartItem& item);
    void removeItemById(const string& id);


};
#endif //CART_H
