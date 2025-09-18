//
// Created by User on 5/25/2025.
//

#include "CartDataBase.h"
#include <fstream>
#include <sstream>

#include "../controller/ProductController.h"
#include "../model/CartItem.h"
//#include "../model/Product.h"

const string FILENAME = "../data_files/cart.csv";

void CartDataBase::saveCartToFile(const vector<CartItem> &items) {
    ofstream file(FILENAME);
    if (file.is_open()) {
        //file << "ProductID,Quantity,SubTotal\n";  // header row

        for (auto item : items) {
            file << item.getItem().getProductId() << ",";
            file << item.getQuantity() << ",";
            file << item.getDiscountedPrice() << "\n";
        }
        file.close();
    }
    else {
        cerr<<"Failed to open file: "<<FILENAME<<" for saving cart."<<endl;
    }
}

vector<CartItem> CartDataBase::loadCartFromFile() {
    vector<CartItem> items;
    ifstream file(FILENAME);

    if (!file.is_open()) {
        cerr << "Failed to open cart file.\n";
        return items;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string productId, quantityStr, discountedStr;

        getline(ss, productId, ',');
        getline(ss, quantityStr, ',');
        getline(ss, discountedStr, '\n');

        int quantity = stoi(quantityStr);
        double discounted = stod(discountedStr);

        Product product = ProductController::findProductById(productId);
        if (!product.getProductId().empty()) {
            CartItem item(product, quantity);
            item.setDiscountedPrice(discounted);
            items.push_back(item);
        }
        else {
            cout<<"Failed to find product with ID: "<<productId<<endl;
        }
    }
    file.close();
    return items;
}

void CartDataBase::clearCartFile() {
    ofstream file(FILENAME, ios::trunc);
    if (!file.is_open()) {
        cerr << "Failed to open cart file.\n";
        return;
    }
    file.close();
}
