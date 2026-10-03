#include <iostream>
#include "Order.h"
using namespace std;

int main() {
    try {
        Stock st(1, 10, 5);
        Order* orders[2];                                   // base pointers
        orders[0] = new IncomingOrder(101, 1, 20, "03/10/2026");
        orders[1] = new OutgoingOrder(102, 1, 5, "03/10/2026");

        for (int i = 0; i < 2; i++) {
            orders[i]->process(st);     // correct version called at runtime
            orders[i]->display();
        }
        st.display();                   // 10 + 20 - 5 = 25

        Order* big = new OutgoingOrder(103, 1, 999, "03/10/2026");
        delete orders[0];
        delete orders[1];
        try { big->process(st); }
        catch (exception &e) { cout << "Error: " << e.what() << endl; }
        delete big;
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
