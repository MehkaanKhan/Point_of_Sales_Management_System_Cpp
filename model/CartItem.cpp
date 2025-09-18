//
// Created by User on 5/24/2025.
//

#include "CartItem.h"

CartItem::CartItem()
{
    quantity = 0;
}

CartItem::CartItem(const Product& item, int quantity)
{
    this->item = item;
    this->quantity = quantity;
}


void CartItem::setQuantity( int quantity)
{
    this->quantity = quantity;
}

Product CartItem::getItem() const
{
    return item;
}

void CartItem::setItem(const Product& newItem) {
    this->item = newItem;
}

int CartItem::getQuantity() const
{
    return quantity;
}

double CartItem::getSubTotal() const
{
    double price;
    if (discountedPrice >= 0) {
        price = discountedPrice;
    }
    else {
        price = item.getPrice();
    }
    //cout << "[DEBUG] qty: " << quantity << ", unit price: " << price << ", subtotal: " << quantity * price << endl;

    return quantity * price;
}

void CartItem::setDiscountedPrice(double newDiscountedPrice) {
    this->discountedPrice = newDiscountedPrice;
}

double CartItem::getDiscountedPrice() const {
    return discountedPrice;
}

