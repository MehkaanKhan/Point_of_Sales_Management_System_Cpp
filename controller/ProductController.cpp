//
// Created by User on 5/23/2025.
//

#include "ProductController.h"

#include <algorithm>

#include "../view/ProductView.h"

const string FILENAME = "../data_files/products.csv";
#include "fstream"

void ProductController::addProduct(Product product) {
    if (product.getProductId().empty()) {
        cout<<"Can't add a null product."<<endl;
        return;
    }

    products.push_back(product);

    ProductDataBase::saveProductData(product);

    //cout<<"Product added successfully!"<<endl;

}

void ProductController::deleteProductById(const string& id) {

    vector<Product> products = ProductDataBase::loadProductData();

    // Get original size
    size_t originalSize = products.size();

    // Remove matching products
    products.erase(remove_if(products.begin(), products.end(),
        [&id](const Product &product) {
            return product.getProductId() == id;
        }), products.end()
    );

    // Check if any product was deleted
    if (products.size() < originalSize) {
        ofstream file(FILENAME, ios::trunc);
        if (file.is_open()) {
            for (const auto &product : products) {
                file << product.getName() << ","
                     << product.getProductId() << ","
                     << product.getPrice() << ","
                     << product.getStock() << ","
                     << product.getCategory() << "\n";
            }
            file.close();
        }

        //cout << "Product deleted successfully!" << endl;
    } else {
        cout << "Product with ID '" << id << "' not found." << endl;
    }

}
void ProductController::updateProductById(const string& id, const Product& updatedProduct) {
    vector<Product> allProducts = ProductDataBase::loadProductData();

    bool found = false;
    for (auto &product : allProducts) {
        if (product.getProductId() == id) {
            product = updatedProduct;
            found = true;
            break;
        }
    }

    if (found) {
        ProductDataBase::saveAllProductData(allProducts);
        //cout << "Product updated successfully.\n";
    } else {
        cout << "Product ID not found. No update performed.\n";
    }
}

Product ProductController::findProductById(const string &id) {
    vector<Product> products = ProductDataBase::loadProductData();

    for (auto &product : products) {
        if (product.getProductId() == id) {
            //cout<<"Product with ID "<< id<<" found."<<endl;
            return product;
        }
    }
    cout<<"Product with ID "<< id<<" not found."<<endl;
    return Product();
}


void ProductController::searchProduct() {
    vector<Product> products = ProductDataBase::loadProductData();
    int response;

    cout<<"Which way do want to search?"<<endl;
    cout<<"1. Name"<<endl;
    cout<<"2. Category"<<endl;
    cout<<"Enter your choice: ";
    cin>>response;

    switch (response) {
        case 1: {
            string name;
            cout<<"Enter name to search: ";
            cin.ignore();
            getline(cin, name);

            bool found = false;
            for (auto &product : products) {
                if (product.getName() == name) {
                    ProductView::displayProduct(product);
                    found = true;
                }
            }

            if (!found) {
                cout<<"No product with name: "<<name<<" found."<<endl;
            }
            break;
        }
        case 2: {
            string category;
            cout<<"Enter category to search: ";
            cin.ignore();
            getline(cin, category);

            bool found = false;
            for (auto &product : products) {
                if (product.getCategory() == category) {
                    ProductView::displayProduct(product);
                    found = true;
                }
            }

            if (!found) {
                cout<<"No product with category: "<<category<<" found."<<endl;
            }
            break;
        }
            default:
            cout<<"Wrong choice."<<endl;
    }

}
void ProductController::displayAllProducts() {
    vector<Product> products = ProductDataBase::loadProductData();
    if (products.empty()) {
        cout<<"No product found in the system."<<endl;
        return;
    }

    //cout<<"Displaying all products...."<<endl;

    ProductView::displayProductTableHeader();
    for (const auto& product : products) {
        ProductView::displayProductRow(product);
    }

}

void ProductController::displayLowStockProducts() {
    int minimum_stock = 10;
    vector<Product> products = ProductDataBase::loadProductData();
    if (products.empty()) {
        cout<<"No product found in the system."<<endl;
        return;
    }

    cout<<"Displaying low Stock products..."<<endl;
    for (auto &product : products) {
        if (product.getStock() < minimum_stock) {
            cout<<product.getName()<<" with ID: "<<product.getProductId()<<" has "<<product.getStock() << " stocks left."<<endl;
        }
    }
}
