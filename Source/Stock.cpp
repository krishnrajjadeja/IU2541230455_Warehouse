#include "Stock.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stock::Stock() : productId(0), quantity(0), reorderLevel(0) {}

Stock::Stock(int pid, int qty, int reorder)
    : productId(pid), quantity(qty), reorderLevel(reorder) {
    if (qty < 0 || reorder < 0)
        throw invalid_argument("Quantity cannot be negative");
}

Stock::~Stock() {}

int Stock::getProductId() const { return productId; }
int Stock::getQuantity() const { return quantity; }
int Stock::getReorderLevel() const { return reorderLevel; }

void Stock::addStock(int qty) {
    if (qty <= 0) throw invalid_argument("Quantity must be positive");
    quantity += qty;
}

void Stock::removeStock(int qty) {
    if (qty <= 0) throw invalid_argument("Quantity must be positive");
    if (qty > quantity) throw runtime_error("Insufficient stock");
    quantity -= qty;
}

bool Stock::isLow() const { return quantity < reorderLevel; }

void Stock::display() const {
    cout << "Product " << productId << " | Qty: " << quantity
         << " | Reorder at: " << reorderLevel
         << (isLow() ? " | LOW STOCK" : "") << endl;
}
