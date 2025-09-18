//
// Created by User on 5/23/2025.
//

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;
#include <string>


class Product
{
private:
    string name;
    string productId;
    float price;
    int stock;
    string category;

public:
    Product();
    Product(string name, string productId, float price, int stock, string category);
    void setName(const string name);
    void setProductId(const string productId);
    void setPrice(float price);
    void setStock(int stock);
    void setCategory(const string category);
    string getName() const;
    string getProductId() const;
    float getPrice() const;
    int getStock() const;
    string getCategory() const;
};


#endif //PRODUCT_H
