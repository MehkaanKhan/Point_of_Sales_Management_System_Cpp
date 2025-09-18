//
// Created by User on 5/23/2025.
//

#include "ProductDataBase.h"

#include <fstream>
#include <sstream>

#include "../model/Product.h"
using namespace std;

const string FILENAME = "../data_files/products.csv";

vector<Product> ProductDataBase::loadProductData() {
    vector<Product> products;
    ifstream file(FILENAME);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, id, priceStr, stockStr, category;
        float price;
        int stock;

        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, priceStr, ',');
        getline(ss, stockStr, ',');
        getline(ss, category, ',');

        price = stof(priceStr);
        stock = stoi(stockStr);

        Product product(name, id, price, stock, category);
        products.push_back(product);
    }
    file.close();
    return products;
}
void ProductDataBase::saveProductData(const Product& product) {
    ofstream file(FILENAME, ios::app);

    if (file.is_open()) {
            file << product.getName() << ","
            << product.getProductId() << ","
            << product.getPrice() << ","
            << product.getStock() << ","
            << product.getCategory() << "\n";
        file.close();
    }
}

void ProductDataBase::saveAllProductData(const vector<Product> &products) {
    ofstream file(FILENAME, ios::trunc);
    if (file.is_open()) {
        for (const Product &product : products) {
            file << product.getName() << ","
            << product.getProductId() << ","
            << product.getPrice() << ","
            << product.getStock() << ","
            << product.getCategory() << "\n";
        }
        file.close();
    }
    else {
        cerr<<"Failed to open file for writing: " << FILENAME << std::endl;
    }
}
