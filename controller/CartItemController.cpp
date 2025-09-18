//
// Created by User on 5/24/2025.
//

#include "CartItemController.h"
#include "../DataBase/CartItemDataBase.h"
#include "../DataBase/ProductDataBase.h"
#include "../model/CartItem.h"
#include "../controller/ProductController.h"
#include <fstream>
#include <string>
using namespace std;
#include <iostream>

const string FILENAME =  "../data_files/cartItems.csv";

void CartItemController::clearCartFile() {
    ofstream file(FILENAME, ios::trunc); // trunc = truncate = clear contents
    if (!file) {
        cerr << "Failed to open file to clear: " << FILENAME << endl;
    }
}

void CartItemController::removeCartItemByProductId(const std::string &id) {
    vector<CartItem> cartItems = CartItemDataBase::loadCartItemsFromFile();
    vector<CartItem> updatedCartItems;
    bool itemRemoved = false;

    for (const auto& item : cartItems) {
        if (item.getItem().getProductId() != id) {
            updatedCartItems.push_back(item);
        }
        else {
            itemRemoved = true;
        }
    }

    //overwrite the file with updated List
    ofstream file(FILENAME, ios::trunc);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    for (const auto& item : updatedCartItems) {
        file << item.getItem().getProductId() << ",";
        file << item.getQuantity() << "\n";
    }
    file.close();

    if (itemRemoved) {
        cout<<"Cart Item successfully removed."<<endl;
    }
    else {
        cout<<"Cart Item could not be removed."<<endl;
    }
}

void CartItemController::addItem(string itemId, int quantity) {
    vector<CartItem> cartItems = CartItemDataBase::loadCartItemsFromFile();

    bool found = false;

    for (auto& item : cartItems) {
        if (item.getItem().getProductId() == itemId) {
            item.setQuantity(item.getQuantity() + quantity);
            found = true;
            break;
        }
    }

    if (!found) {
        Product newProduct = ProductController::findProductById(itemId);

        if (!newProduct.getProductId().empty()) {
            CartItem newCartItem(newProduct, quantity);
            cartItems.push_back(newCartItem);
        }
        else {
            //cerr<<"Product with ID: "<< itemId <<"not found."<<endl;
            return;
        }
    }
    CartItemDataBase::saveAllCartItemsToFile(cartItems);
}

bool CartItemController::updateQuantity(vector<CartItem> &cartItems, const string &itemId, int newQuantity) {
    for ( auto& item : cartItems) {
        if (item.getItem().getProductId() == itemId) {
            item.setQuantity(newQuantity);
            return true;
        }
    }
    return false;
}
