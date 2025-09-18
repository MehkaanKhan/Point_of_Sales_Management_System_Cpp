//
// Created by User on 5/26/2025.
//

#include "AdminView.h"

#include "ProductView.h"

void AdminView::showAdminMenu() {
    cout << "\n------ Admin Menu ------\n";
    cout << "1. Add Product\n";
    cout << "2. Delete Product\n";
    cout << "3. Update Product\n";
    cout << "4. View All Products\n";
    cout << "0. Logout\n";
    cout << "Enter your choice: ";
}

Product AdminView::promptAddProduct() {
    return ProductView::promptForProductDetails();
}

string AdminView::promptProductId() {
    return ProductView::promptForProductId();
}

void AdminView::showMessage(const string &message) {
    cout << message << endl;
}
