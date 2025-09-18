//
// Created by User on 5/25/2025.
//

#include "CartController.h"

#include "../DataBase/CartDataBase.h"
#include "../model/CartItem.h"
#include "../view/CartView.h"
#include "../model/Transaction.h"
#include "../view/TransactionView.h"
#include "../DataBase/ProductDataBase.h"
#include <cstdlib>
#include <fstream>

float CartController::currentDiscount = 0.0f;


vector<CartItem> CartController::loadCart() {
    vector<CartItem> cart = CartDataBase::loadCartFromFile();
    return cart;
}

void CartController::saveCart(const vector<CartItem> &cart) {
    CartDataBase::saveCartToFile(cart);
}

void CartController::addProductToCart(const CartItem &item) {
    vector<CartItem> cart = CartDataBase::loadCartFromFile();
    bool existingItem = false;
    bool productAdded = false;

    for (auto &cartItem : cart) {
        if (cartItem.getItem().getProductId() == item.getItem().getProductId()) {
            cartItem.setQuantity(cartItem.getQuantity() + item.getQuantity());
            existingItem = true;
            productAdded = true;
            break;
        }
    }

    if (existingItem == false) {
        cart.push_back(item);
        productAdded = true;
    }

    CartDataBase::saveCartToFile(cart);

    // if (productAdded) {
    //     cout<<"Product Added to Cart successfully!"<<endl;
    // }
    // else {
    //     cout<<"Failed to add Product to Cart."<<endl;
    // }
}
void CartController::removeProductFromCart(const CartItem &item) {
    vector<CartItem> cart = CartDataBase::loadCartFromFile();
    vector<CartItem> updatedCart;
    bool itemRemoved = false;

    for (auto &cartItem : cart) {
        if (cartItem.getItem().getProductId() != item.getItem().getProductId()) {
            updatedCart.push_back(cartItem);
        }
        else {
            itemRemoved = true;
        }
    }

    CartDataBase::clearCartFile();
    CartDataBase::saveCartToFile(updatedCart);

    if (itemRemoved) {
        cout<<"Product removed from cart successfully!" << endl;
    }
    else {
        cout<<"Failed to remove product from cart."<<endl;
    }
}
void CartController::updateQuantity(const string& productId, int newQuantity) {
    vector<CartItem> cart = CartDataBase::loadCartFromFile();
    bool quantityUpdated = false;

    for (auto &cartItem : cart) {
        if (cartItem.getItem().getProductId() == productId) {
            cartItem.setQuantity(newQuantity);
            quantityUpdated = true;
            break;
        }
    }

    if (quantityUpdated) {
        CartDataBase::clearCartFile();
        CartDataBase::saveCartToFile(cart);
        cout<<"Product quantity updated successfully!"<<endl;
    }
    else {
        cout<<"Failed to update product quantity."<<endl;
    }

}
void CartController::applyDiscount(const float discount) {
    if (discount < 0.0f || discount > 100.0f) {
        cout << "Invalid discount percentage. Must be between 0 and 100.\n";
        return;
    }

    currentDiscount = discount;

    //cout << "Discount of " << discount << "% will be applied at checkout.\n";
}

void CartController::clearCart() {
    CartDataBase::clearCartFile();
}
void CartController::checkout() {
    vector<CartItem> cart = CartDataBase::loadCartFromFile();


    if (cart.empty()) {
        cout << "Cart is empty. Nothing to checkout." << endl;
        return;
    }

    double totalAmount = 0.0;
    for (auto &cartItem : cart) {
        totalAmount += cartItem.getSubTotal();
    }

    // Step 1: Load all products
    vector<Product> allProducts  = ProductDataBase::loadProductData();

    // Update stock in the actual product list
    for (auto &cartItem : cart) {
        string id = cartItem.getItem().getProductId();
        int qtyPurchased = cartItem.getQuantity();

        bool matched = false;
        for (auto &product : allProducts) {
            if (product.getProductId() == id) {
                int currentStock = product.getStock();
                int newStock = currentStock - qtyPurchased;
                if (newStock < 0) {
                    cout << "Warning: Purchase quantity exceeds available stock for " << id << ". Capping at zero.\n";
                    newStock = 0;
                }
                cout << "Updating " << id << ": " << currentStock << " -> " << newStock << endl;
                product.setStock(newStock);
                matched = true;
                break;
            }
        }

        if (!matched) {
            cout << "Error: Product ID " << id << " not found in product list.\n";
        }
    }

    // Save updated products back to file
    ProductDataBase::saveAllProductData(allProducts);  // you’ll need this function!


    // Generate random bill ID
    string billId = "BILL" + to_string(rand() % 100000 + 10000);

    Transaction transaction(billId, cart, totalAmount, currentDiscount);
    TransactionView::displayReceipt(transaction);

    // Clear cart
    CartDataBase::saveCartToFile({});
    currentDiscount = 0;
}
