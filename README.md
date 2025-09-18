# POS Management System

A **Point of Sale (POS) Management System** built in **C++** using **Object-Oriented Programming (OOP)** principles and following the **Model-View-Controller (MVC)** architecture.

This system provides an organized way to handle **user authentication, product management, transactions, receipts, and dashboards** with role-based access (Admin/Cashier).

---

## 📂 Project Structure

```
├── controller/       # Handles business logic, connects model & view
├── data_files/       # Stores text/CSV files for persistence
├── database/         # Database handler files (if extended)
├── model/            # Core classes (Product, User, Transaction, etc.)
├── view/             # GUI/console output (Raylib UI or text-based)
├── CMakeLists.txt    # Build configuration (CMake project)
├── main.cpp          # Entry point of the application
└── cmake-build-debug # Auto-generated build files (ignored in git)
```

---

## ✨ Features

* **Login & Registration System**

  * Role-based access (Admin / Cashier)
* **Admin Dashboard**

  * Add, update, delete products
  * View all products
  * Manage users
* **Cashier Dashboard**

  * Process transactions
  * Generate receipts
* **Transaction & Receipt System**

  * Save transactions to file
  * Display receipt screen after purchase
* **File Handling**

  * Stores all persistent data (products, users, transactions) in `data_files/`
* **Scalable Architecture**

  * MVC ensures separation of concerns
  * Easy to expand with new features

---

## 🛠️ Tech Stack

* **Language**: C++
* **Paradigm**: Object-Oriented Programming (OOP)
* **Architecture**: MVC (Model–View–Controller)
* **Build System**: CMake
* **UI**: Raylib (custom GUI) / Console fallback

---

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/your-username/POS-Management-System.git
cd POS-Management-System
```

### 2. Build the project

```bash
mkdir build && cd build
cmake ..
make
```

### 3. Run the program

```bash
./POSManagementSystem
```

---

## 📸 Screens (Optional if GUI)

* **Login & Registration**
* **Admin Dashboard**
* **Cashier Transaction Screen**
* **Receipt Screen**

*(Add screenshots/gifs here once you finalize GUI views.)*

---

## 📌 Future Enhancements

* Integration with SQL/SQLite instead of flat files
* Inventory tracking with stock alerts
* Sales analytics & reports
* Barcode scanner support

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repo
2. Create a new branch (`feature-new`)
3. Commit your changes
4. Push and open a PR

---

## 📜 License

This project is licensed under the **MIT License** – free to use and modify.
