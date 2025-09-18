//
// Created by User on 5/25/2025.
//

#include "CartView.h"
#include "../model/CartItem.h"
#include <vector>
#include <iomanip>
#include "../DataBase/CartDataBase.h"

void CartView::displayCart(const std::vector<CartItem> &cart) {
    if (cart.empty()) {
        cout<<"Cart is empty."<<endl;
        return;
    }

    double total = 0.0;

    cout << "-------------------- CART --------------------\n";
    cout << left << setw(18) << "Product Name"
         << "| " << setw(12) << "Product ID"
         << "| " << setw(8) << "Price"
         << "| " << setw(6) << "Qty"
         << "| Subtotal\n";
    cout << "--------------------------------------------------------\n";

    for (const auto &item : cart) {
        const Product & p = item.getItem();
        double subTotal = item.getSubTotal();
        total += subTotal;

        cout << left << setw(18) << p.getName()
        << "| " << setw(12) << p.getProductId()
        << "| " << setw(8) << p.getPrice()
        << "| " << setw(6) << item.getQuantity()
        << "| " << subTotal << "\n";
    }

    cout << "--------------------------------------------------------\n";
    cout << "Total Amount: " << total << '\n';
    cout << "----------------------------------------------\n";
}
void CartView::showEmptyCartMessage() {
    vector<CartItem> cart = CartDataBase::loadCartFromFile();
    if (cart.empty()) {
        cout<<"Cart is empty."<<endl;
    }
    else {
        cout << "Cart has items." << endl;
    }
}
string CartView::promptForProductId() {
    string productId;
    cout << "Enter Product ID: ";
    cin >> productId;
    return productId;
}
int CartView::promptForQuantity() {
    int quantity;
    cout << "Enter Quantity: ";
    cin >> quantity;

    while (quantity <= 0) {
        cout<<"Invalid input. Please enter a positive integer."<<endl;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }
    return quantity;

}
void CartView::showClearCartMessage() {
    cout<<"The cart has been cleared."<<endl;
}
void CartView::showCheckoutSummary(const vector<CartItem> &cart) {
    if (cart.empty()) {
        cout<<"Checkout failed: Cart is empty."<<endl;
    }

    double total = 0.0;
    cout << "\n----- Checkout Summary -----\n";
    for (const auto &item : cart) {
        cout<< item.getItem().getName()
        << " (x"  << item.getQuantity()
        << ") = $" << item.getSubTotal() <<endl;
        total += item.getSubTotal();
    }

    cout << "-----------------------------\n";
    cout<<"Total Amount: " << total << endl;
    cout<<"Thank you for shopping with us!\n";

}