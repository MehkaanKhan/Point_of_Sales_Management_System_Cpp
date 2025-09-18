//
// Created by User on 5/23/2025.
//

#ifndef PRODUCTCONTROLLER_H
#define PRODUCTCONTROLLER_H

#include "../model/Product.h"
#include "../DataBase/ProductDataBase.h"

class ProductController {
private:
    std::vector<Product> products;

    void loadProducts();                 // Load from file
    void saveProducts();                 // Save to file
public:
    void addProduct(Product product);
    void deleteProductById(const string& id);
    void updateProductById(const string& id, const Product& updatedProduct);
    static Product findProductById(const string& id);
    void searchProduct();
    void displayAllProducts();
    void displayLowStockProducts();


};
#endif //PRODUCTCONTROLLER_H
