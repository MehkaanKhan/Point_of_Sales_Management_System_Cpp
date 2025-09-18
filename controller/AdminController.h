//
// Created by User on 5/26/2025.
//

#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include "ProductController.h"

class AdminController {
    private:
    ProductController productController;

    public:
    void addProduct();
    void deleteProduct();
    void updateProduct();
    void showAllProducts();
    void handleAdminMenu();
};
#endif //ADMINCONTROLLER_H
