#include "Product.h"
#include <iostream>
#include <stdexcept>

Product::Product() : Item(), category(""), price(0.0) {}

Product::Product(int i, string n, string c, double p)
    : Item(i, n), category(c), price(0.0) {
    setPrice(p);                  // reuse validation
}

Product::~Product() {}

string Product::getCategory() const { return category; }
double Product::getPrice() const { return price; }
void Product::setCategory(string c) { category = c; }

void Product::setPrice(double p) {
    if (p < 0)
        throw invalid_argument("Price cannot be negative");  // exception handling
    price = p;
}

void Product::display() const {
    cout << id << " | " << name << " | " << category
         << " | Rs." << price << endl;
}

string Product::toFileString() const {
    return to_string(id) + "|" + name + "|" + category + "|" + to_string(price);
}