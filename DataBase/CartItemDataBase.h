//
// Created by User on 5/24/2025.
//

#ifndef CARTITEMDATABASE_H
#define CARTITEMDATABASE_H
#include <vector>
#include "../model/CartItem.h"
using namespace std;
class CartItemDataBase {

    public:
    static std::vector<CartItem> loadCartItemsFromFile();
    static void saveCartItemToFile(const CartItem &item);
    static void saveAllCartItemsToFile(const std::vector<CartItem> &cartItems);


};
#endif //CARTITEMDATABASE_H
