//
// Created by User on 5/23/2025.
//

#ifndef PRODUCTVIEW_H
#define PRODUCTVIEW_H

#include <iostream>
using namespace std;
#include <string>
#include "../model/Product.h"

class ProductView
{
public:
    static void displayProductTableHeader();
    static void displayProductRow(const Product& product);
    static void displayProduct(const Product& product);
    static Product promptForProductDetails();
    static string promptForProductId();
};

#endif //PRODUCTVIEW_H
