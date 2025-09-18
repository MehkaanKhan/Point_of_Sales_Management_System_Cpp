//
// Created by User on 5/26/2025.
//

#include "AdminController.h"
#include "../view/ProductView.h"


void AdminController::addProduct() {
    Product product = ProductView::promptForProductDetails();
    productController.addProduct(product);
    cout<< "Product added successfully!"<<endl;
}
void AdminController::deleteProduct() {
    string productId = ProductView::promptForProductId();
    productController.deleteProductById(productId);
    cout<< "Product deleted successfully!"<<endl;
}
void AdminController::updateProduct() {
    string productId = ProductView::promptForProductId();
    Product existingProduct = productController.findProductById(productId);

    if (existingProduct.getProductId().empty()) {
        cout << "Product not found.\n";
        return;
    }

    cout << "Product found:\n";
    ProductView::displayProduct(existingProduct);

    char updateMore;
    do {
        int choice;
        cout << "\nWhich field do you want to update?\n";
        cout << "1. Name\n";
        cout << "2. Price\n";
        cout << "3. Stock\n";
        cout << "4. Category\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string newName;
                cin.ignore();
                cout << "Enter new name: ";
                getline(cin, newName);
                existingProduct.setName(newName);
                break;
            }
            case 2: {
                double newPrice;
                cout << "Enter new price: ";
                cin >> newPrice;
                existingProduct.setPrice(newPrice);
                break;
            }
            case 3: {
                int newStock;
                cout << "Enter new stock: ";
                cin >> newStock;
                existingProduct.setStock(newStock);
                break;
            }
            case 4: {
                string newCategory;
                cin.ignore();
                cout << "Enter new category: ";
                getline(cin, newCategory);
                existingProduct.setCategory(newCategory);
                break;
            }
            default:
                cout << "Invalid choice.\n";
                break;
        }

        cout << "Do you want to update another field? (y/n): ";
        cin >> updateMore;
    } while (tolower(updateMore) == 'y');

    productController.updateProductById(productId, existingProduct);
    cout << "Product updated successfully.\n";
}

void AdminController::showAllProducts() {
    productController.displayAllProducts();
}
void AdminController::handleAdminMenu() {
    int choice;
    do {
        cout << "\n------ Admin Dashboard ------\n";
        cout << "1. Add Product\n";
        cout << "2. Delete Product\n";
        cout << "3. Update Product\n";
        cout << "4. View All Products\n";
        cout << "0. Exit Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: deleteProduct(); break;
            case 3: updateProduct(); break;
            case 4: showAllProducts(); break;
            case 0: ; break;
            default: cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 0);
}