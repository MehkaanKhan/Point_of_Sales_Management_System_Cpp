//
// Created by User on 5/25/2025.
//

#ifndef CARTDATABASE_H
#define CARTDATABASE_H
#include "../model/CartItem.h"
using namespace std;
#include <vector>


class CartDataBase{
    public:
    static void saveCartToFile(const vector<CartItem> &items);
    static vector<CartItem> loadCartFromFile();
    static void clearCartFile();
};
#endif //CARTDATABASE_H
