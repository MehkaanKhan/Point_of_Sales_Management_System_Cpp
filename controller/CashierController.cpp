//
// Created by User on 5/26/2025.
//

#include "CashierController.h"

#include "../DataBase/CartDataBase.h"
#include "../view/CartView.h"
#include "../view/ProductView.h"

void CashierController::addItemToCart() {
    string productId = ProductView::promptForProductId();
    int quantity = CartView::promptForQuantity();

    Product product = productController.findProductById(productId);
    if (product.getProductId().empty()) {
        cout << "Product not found.\n";
        return;
    }
    if (quantity > product.getStock()) {
        cout << "Insufficient stock.\n";
        return;
    }

    CartItem item(product, quantity);
    cartController.addProductToCart(item);
    cout << "Item added to cart.\n";
}

void CashierController::applyDiscount() {
    float discount;
    cout << "Enter discount percentage (0-100): ";
    cin >> discount;

    if (discount < 0 || discount > 100) {
        cout << "Invalid discount value.\n";
        return;
    }

    cartController.applyDiscount(discount);
    cout << "Discount applied successfully!\n";
}
void CashierController::viewCart() {
    vector<CartItem> cart = CartDataBase::loadCartFromFile();

    if (cart.empty()) {
        cout << "Cart is empty.\n";
        return;
    }

    CartView::displayCart(cart);

}
void CashierController::checkout() {
    cartController.checkout();

}
void CashierController::handleCashierMenu() {
    int choice;

    do {
        cout << "\n------ Cashier Menu ------\n";
        cout << "1. Add Item to Cart\n";
        cout << "2. Apply Discount\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "0. Exit Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItemToCart(); break;
            case 2: applyDiscount(); break;
            case 3: viewCart(); break;
            case 4: checkout(); break;
            case 0: cout << "Logging out...\n"; break;
            default: cout << "Invalid choice. Try again.\n"; break;
        }

    } while (choice != 0);
}
