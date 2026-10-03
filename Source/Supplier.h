
#ifndef SUPPLIER_H
#define SUPPLIER_H
#include "Item.h"

class Supplier : public Item {     // also inherits from Item
private:
    string phone;
    string city;
public:
    Supplier();
    Supplier(int i, string n, string ph, string c);
    ~Supplier();

    string getPhone() const;
    string getCity() const;
    void setPhone(string ph);      // validates phone
    void setCity(string c);

    void display() const override;
    string toFileString() const override;
};
#endif