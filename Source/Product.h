#ifndef PRODUCT_H
#define PRODUCT_H
#include "Item.h"

class Product : public Item {     // Product inherits from Item
private:                          // encapsulation: data is hidden
    string category;
    double price;
public:
    Product();
    Product(int i, string n, string c, double p);
    ~Product();

    string getCategory() const;
    double getPrice() const;
    void setCategory(string c);
    void setPrice(double p);      // validates price

    void display() const override;
    string toFileString() const override;
};
#endif