#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "../model/User.h"
#include <stdexcept>

class UserController {
private:
    static User* currentUser;  // Pointer to currently logged-in user

public:
    static bool handleLogin();
    static void registerUser();

    // Returns reference to current user (throws if none logged in)
    static User* getCurrentUser();

    static void logout();

    static bool isAdmin();

    // Helper to check if a user is logged in
    static bool isLoggedIn();
};

#endif //USERCONTROLLER_H
