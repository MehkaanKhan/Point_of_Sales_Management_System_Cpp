//
// Created by User on 5/23/2025.
//

#include "Product.h"
using namespace std;;

Product::Product()
{
    name = "";
    productId = "";
    price = 0.0;
    stock = 0;
    category = "";
}

Product::Product(string name, string productId, float price, int stock, string category)
{
    this->name = name;
    this->productId = productId;
    this->price = price;
    this->stock = stock;
    this->category = category;
}

void Product::setName(const string name)
{
    this->name = name;
}

void Product::setProductId(const string productId)
{
    this->productId = productId;
}

void Product::setPrice(float price) {
    this->price = price;
}
void Product::setStock(int stock) {
    this->stock = stock;
}
void Product::setCategory(const string category) {
    this->category = category;
}
string Product::getName() const{
    return name;
}
string Product::getProductId() const{
    return productId;
}
float Product::getPrice() const{
    return price;
}
int Product::getStock() const{
    return stock;
}
string Product::getCategory() const{
    return category;
}

