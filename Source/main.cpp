#include <iostream>
#include "Product.h"

int main() {
    try {
        Product p(1, "Laptop", "Electronics", 55000);
        p.display();
        Product bad(2, "Pen", "Stationery", -5);   // should throw
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}