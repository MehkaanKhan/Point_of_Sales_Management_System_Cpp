//
// Created by User on 5/26/2025.
//

#ifndef ADMINVIEW_H
#define ADMINVIEW_H
#include <string>
#include "../model/Product.h"
using namespace std;

class AdminView {
    public:
    static void showAdminMenu();
    static Product promptAddProduct();
    static string promptProductId();
    static void showMessage(const string& message);
};
#endif //ADMINVIEW_H
