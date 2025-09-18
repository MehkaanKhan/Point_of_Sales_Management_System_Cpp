//
// Created by User on 5/23/2025.
//

#ifndef PRODUCTDATABASE_H
#define PRODUCTDATABASE_H
#include "UserDataBase.h"
#include "../model/Product.h"

class ProductDataBase {
public:
    // static std::vector<User> loadUsersFromFile();         // Load users from CSV file
    // static void saveUserToFile(const User& user);

    static std::vector<Product> loadProductData();
    static void saveProductData(const Product& product);
    static void saveAllProductData(const vector<Product> &products);

};


#endif //PRODUCTDATABASE_H
