//
// Created by User on 5/24/2025.
//
#include "CartItemDataBase.h"
#include <fstream>
#include <sstream>

#include "ProductDataBase.h"

const string FILENAME =  "../data_files/cartItems.csv";

std::vector<CartItem> CartItemDataBase::loadCartItemsFromFile() {
    vector<CartItem> cartItems;
    vector<Product> products = ProductDataBase::loadProductData();
    string id, quantityStr;
    ifstream file(FILENAME);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);;

        getline(ss, id, ',');
        getline(ss, quantityStr, ',');

        int quantity = stoi(quantityStr);

        for (const auto& item : products) {
            if (item.getProductId() == id) {
                CartItem cartItem(item, quantity);
                cartItems.push_back(cartItem);
                break;
            }
        }
    }
    file.close();
    return cartItems;
}

void CartItemDataBase::saveCartItemToFile(const CartItem &item) {
    ofstream file(FILENAME, ios::app);
    if (file.is_open()) {
        file << item.getItem().getProductId() << ",";
        file << item.getQuantity() << "\n";
        file.close();
    }
}

void CartItemDataBase::saveAllCartItemsToFile(const std::vector<CartItem> &cartItems) {
    ofstream file(FILENAME, ios::trunc);

    if (file.is_open()) {
        for (const auto& item : cartItems) {
            file << item.getItem().getProductId() << ",";
            file << item.getQuantity() << "\n";
        }
        file.close();
    }
    else {
        cerr << "Can't open file: " << FILENAME << endl;
    }
}

