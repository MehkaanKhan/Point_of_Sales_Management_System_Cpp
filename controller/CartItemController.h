 //
// Created by User on 5/24/2025.
//

#ifndef CARTITEMCONTROLLER_H
#define CARTITEMCONTROLLER_H
#include <string>
#include <vector>
#include "../model/CartItem.h"
class CartItemController {

 public:
  void clearCartFile();
  void removeCartItemByProductId(const std::string& id);
  void addItem(string itemId, int quantity);
  bool updateQuantity(vector<CartItem>& cartItems, const string& itemId, int newQuantity);

};

#endif //CARTITEMCONTROLLER_H
