#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "Stock.h"
using namespace std;

// Base class
class Order {
protected:
    int orderId;
    int productId;
    int quantity;
    string date;
public:
    Order();
    Order(int oid, int pid, int qty, string d);
    virtual ~Order();

    int getOrderId() const;
    int getProductId() const;
    int getQuantity() const;
    string getDate() const;

    // Each child writes its own version (runtime polymorphism)
    virtual void process(Stock &s) = 0;
    virtual string getType() const = 0;
    virtual void display() const;
    string toFileString() const;
};

// Stock comes IN from a supplier
class IncomingOrder : public Order {
public:
    IncomingOrder();
    IncomingOrder(int oid, int pid, int qty, string d);
    void process(Stock &s) override;
    string getType() const override;
};

// Stock goes OUT to a customer
class OutgoingOrder : public Order {
public:
    OutgoingOrder();
    OutgoingOrder(int oid, int pid, int qty, string d);
    void process(Stock &s) override;
    string getType() const override;
};
#endif
