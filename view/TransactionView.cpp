//
// Created by User on 5/26/2025.
//

#include "TransactionView.h"
#include <iostream>
#include <iomanip>

void TransactionView::displayReceipt(const Transaction &transaction) {
    cout << "\n========== RECEIPT ==========\n";
    cout << "Bill ID: " << transaction.getBillId() << "\n";
    cout << "Timestamp: " << transaction.getTimestamp() << "\n";
    cout << "\nItems:\n";

    for (const auto &item : transaction.getItems()) {
        cout << left << setw(15) << item.getItem().getName()
             << "Qty: " << item.getQuantity()
             << " | Subtotal: $" << fixed << setprecision(2) << item.getSubTotal() << "\n";
    }

    cout << "\nTotal: $" << fixed << setprecision(2) << transaction.getTotalAmount();
    cout << "\nDiscount: " << transaction.getDiscount() << "%";
    cout << "\nFinal Amount: $" << fixed << setprecision(2) << transaction.getFinalAmount();
    cout << "\n==============================\n";
}