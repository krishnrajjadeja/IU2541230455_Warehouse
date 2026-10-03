#include <iostream>
#include "Product.h"
#include "Supplier.h"
#include "Stock.h"

int main() {
    try {
        Supplier s(1, "Ravi Traders", "9876543210", "Rajkot");
        s.display();

        Stock st(1, 10, 5);
        st.addStock(20);
        st.removeStock(28);
        st.display();                 // Qty 2, LOW STOCK
        st.removeStock(50);           // should throw
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
