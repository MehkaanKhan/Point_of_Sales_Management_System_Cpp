//
// Created by User on 5/23/2025.
//

#include "ProductView.h"
#include "../model/Product.h"
#include <iostream>
using namespace std;

void ProductView::displayProduct(const Product& product)
{
    cout << "Product Name: " << product.getName() << endl;
    cout << "Product ID: " << product.getProductId() << endl;
    cout << "Price: $" << product.getPrice() << endl;
    cout << "Stock: " << product.getStock() << endl;
    cout << "Category: " << product.getCategory() << endl;

}

#include <iomanip>

void ProductView::displayProductTableHeader() {
    cout << left << setw(15) << "Product ID"
         << setw(25) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Stock"
         << setw(15) << "Category" << endl;

    cout << string(75, '-') << endl;
}

void ProductView::displayProductRow(const Product& product) {
    cout << left << setw(15) << product.getProductId()
         << setw(25) << product.getName()
         << "$" << setw(9) << fixed << setprecision(2) << product.getPrice()
         << setw(10) << product.getStock()
         << setw(15) << product.getCategory() << endl;
}


Product ProductView::promptForProductDetails() {
    string id, name, category;
    float price;
    int stock;

    cout << "Enter Product ID: ";
    cin.ignore();
    cin >> id;

    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter product price: ";
    cin >> price;

    cout << "Enter product stock: ";
    cin >> stock;

    cout << "Enter product category: ";
    cin.ignore();
    getline(cin, category);

    return Product(name, id, price, stock, category); // empty ID for now
}

string ProductView::promptForProductId() {
    string productId;
    cout << "Enter Product ID: " ;
    cin >> productId;

    return productId;
}
