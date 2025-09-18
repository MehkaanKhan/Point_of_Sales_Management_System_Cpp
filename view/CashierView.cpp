//
// Created by User on 5/26/2025.
//

#include "CashierView.h"

#include "ProductView.h"

void CashierView::showCashierMenu() {
    cout << "\n------ Cashier Dashboard ------\n";
    cout << "1. Add Item to Cart\n";
    cout << "2. Apply Discount\n";
    cout << "3. View Cart\n";
    cout << "4. Checkout\n";
    cout << "0. Logout\n";
    cout << "Enter your choice: ";
}

std::string CashierView::promptProductId() {
    return ProductView::promptForProductId();
}
int CashierView::promptQuantity() {
    int quantity = 0;
    cout<<"Enter Quantity: ";
    cin>>quantity;
    return quantity;
}
float CashierView::promptDiscount() {
    float discount = 0;
    cout<<"Enter Discount: ";
    cin>>discount;
    return discount;
}
void CashierView::showMessage(const std::string &message) {
    cout<<message<<endl;
}