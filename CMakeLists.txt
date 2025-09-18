cmake_minimum_required(VERSION 3.31)
project(first)

set(CMAKE_CXX_STANDARD 20)

add_executable(first main.cpp
        view/UserView.cpp
        view/UserView.h
        model/User.cpp
        model/User.h
        DataBase/UserDataBase.cpp
        DataBase/UserDataBase.h
        controller/UserController.cpp
        controller/UserController.h
        model/Product.cpp
        model/Product.h
        view/ProductView.cpp
        view/ProductView.h
        DataBase/ProductDataBase.cpp
        DataBase/ProductDataBase.h
        controller/ProductController.cpp
        controller/ProductController.h
        model/CartItem.cpp
        model/CartItem.h
        view/CartItemView.cpp
        view/CartItemView.h
        DataBase/CartItemDataBase.cpp
        DataBase/CartItemDataBase.h
        controller/CartItemController.cpp
        controller/CartItemController.h
        model/Cart.cpp
        model/Cart.h
        DataBase/CartDataBase.cpp
        DataBase/CartDataBase.h
        controller/CartController.cpp
        controller/CartController.h
        view/CartView.cpp
        view/CartView.h
        model/Admin.cpp
        model/Admin.h
        view/AdminView.cpp
        view/AdminView.h
        controller/AdminController.cpp
        controller/AdminController.h
        model/Cashier.cpp
        model/Cashier.h
        view/CashierView.cpp
        view/CashierView.h
        controller/CashierController.cpp
        controller/CashierController.h
        model/Transaction.cpp
        model/Transaction.h
        view/TransactionView.cpp
        view/TransactionView.h)
