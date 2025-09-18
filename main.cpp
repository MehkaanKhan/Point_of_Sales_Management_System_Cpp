#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

#include "controller/UserController.h"
#include "controller/ProductController.h"
#include "controller/CartController.h"
#include "controller/AdminController.h"
#include "controller/CashierController.h"
#include "view/CartView.h"
#include "DataBase/CartDataBase.h"

enum RunResult {
    ExitProgram,
    LogoutUser,
    LoggedIn
};

// Run User Registration/Login System
RunResult runPOSApp(UserController& userController, User*& currentUser){
    int choice;
    while (true) {
        cout << "\n===================================\n";
        cout << "       POS Management System       \n";
        cout << "===================================\n";

        if (!userController.isLoggedIn()) {
            cout << "1. Register User\n";
            cout << "2. Login\n";
            cout << "0. Exit\n";
        } else {
            cout << "3. Show Current User\n";
            cout << "4. Logout\n";
            cout << "5. Go to Menu\n";
            //cout << "0. Exit\n";
        }

        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        try {
            if (!userController.isLoggedIn()) {
                switch (choice) {
                    case 1:
                        userController.registerUser();
                        break;
                    case 2: // login
                        if (userController.handleLogin()) {
                            currentUser = userController.getCurrentUser();
                            return LoggedIn;
                        } else {
                            cout << "Login failed.\n";
                        }
                        break;

                    case 0: // exit
                        cout << "Exiting program. Goodbye!\n";
                        return ExitProgram;
                }
            } else {
                switch (choice) {
                    case 3: {
                        User* user = userController.getCurrentUser();
                        cout << user->getName() << " | Role: " << user->getRole() << endl;
                        break;
                    }
                    case 4: // logout
                        userController.logout();
                        cout << "Logged out successfully.\n";
                        return LogoutUser;

                    case 5: // go to menu
                        currentUser = userController.getCurrentUser();
                        return LoggedIn;
                        case 0:
                        cout << "Exiting program. Goodbye!\n";
                        return ExitProgram;
                    default:
                        cout << "Invalid choice.\n";
                }
            }
        } catch (const std::exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}


int main() {
    srand((unsigned)time(nullptr));  // for billId randomness

    UserController userController;
    ProductController productController;
    CartController cartController;

    bool exitProgram = false;

    while (!exitProgram) {
        User* currentUser = nullptr;
        RunResult result = runPOSApp(userController, currentUser);

        switch (result) {
            case ExitProgram:
                exitProgram = true;
                break;

            case LogoutUser:
                cout << "No user logged in. Returning to login menu...\n";
                continue;

            case LoggedIn: {
                string role = currentUser->getRole();
                if (role == "Admin") {
                    AdminController adminController;
                    adminController.handleAdminMenu();
                } else if (role == "Cashier") {
                    CashierController cashierController;
                    cashierController.handleCashierMenu();
                } else {
                    cout << "Unrecognized role. Access denied.\n";
                }

                cout << "\nUser exited menu. Returning to main menu...\n";
                break;
            }
        }
    }
    return 0;
}
