#include "Supplier.h"
#include <iostream>
#include <stdexcept>

Supplier::Supplier() : Item(), phone(""), city("") {}

Supplier::Supplier(int i, string n, string ph, string c)
    : Item(i, n), phone(""), city(c) {
    setPhone(ph);
}

Supplier::~Supplier() {}

string Supplier::getPhone() const { return phone; }
string Supplier::getCity() const { return city; }
void Supplier::setCity(string c) { city = c; }

void Supplier::setPhone(string ph) {
    if (ph.length() != 10)
        throw invalid_argument("Phone must be 10 digits");
    for (char ch : ph)
        if (!isdigit(ch))
            throw invalid_argument("Phone must contain only digits");
    phone = ph;
}

void Supplier::display() const {
    cout << id << " | " << name << " | " << phone << " | " << city << endl;
}

string Supplier::toFileString() const {
    return to_string(id) + "|" + name + "|" + phone + "|" + city;
}
