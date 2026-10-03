#include "Order.h"
#include <iostream>
#include <stdexcept>

// ---------- Order (base) ----------
Order::Order() : orderId(0), productId(0), quantity(0), date("") {}

Order::Order(int oid, int pid, int qty, string d)
    : orderId(oid), productId(pid), quantity(qty), date(d) {
    if (qty <= 0)
        throw invalid_argument("Order quantity must be positive");
}

Order::~Order() {}

int Order::getOrderId() const { return orderId; }
int Order::getProductId() const { return productId; }
int Order::getQuantity() const { return quantity; }
string Order::getDate() const { return date; }

void Order::display() const {
    cout << orderId << " | " << getType() << " | Product " << productId
         << " | Qty " << quantity << " | " << date << endl;
}

string Order::toFileString() const {
    return to_string(orderId) + "|" + getType() + "|" + to_string(productId)
         + "|" + to_string(quantity) + "|" + date;
}

// ---------- IncomingOrder ----------
IncomingOrder::IncomingOrder() : Order() {}
IncomingOrder::IncomingOrder(int oid, int pid, int qty, string d)
    : Order(oid, pid, qty, d) {}

void IncomingOrder::process(Stock &s) {
    s.addStock(quantity);          // stock increases
}
string IncomingOrder::getType() const { return "INCOMING"; }

// ---------- OutgoingOrder ----------
OutgoingOrder::OutgoingOrder() : Order() {}
OutgoingOrder::OutgoingOrder(int oid, int pid, int qty, string d)
    : Order(oid, pid, qty, d) {}

void OutgoingOrder::process(Stock &s) {
    s.removeStock(quantity);       // stock decreases (throws if not enough)
}
string OutgoingOrder::getType() const { return "OUTGOING"; }
