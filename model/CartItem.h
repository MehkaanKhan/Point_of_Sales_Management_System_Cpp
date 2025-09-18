#pragma once
#ifndef CARTITEM_H
#define CARTITEM_H
#include <iostream>
using namespace std;
#include <string>
#include "Product.h"

class CartItem
{
private:
    Product item;
    int quantity;
    double discountedPrice = -1; // -1 means no discount
public:
    CartItem();
    CartItem(const Product& item, int quantity);
    void setQuantity(const int quantity);
    Product getItem() const;
    void setItem(const Product& newItem);
    int getQuantity() const;
    double getSubTotal() const;
    void setDiscountedPrice(double newDiscountedPrice);
    double getDiscountedPrice() const;
};

#endif
