#include <iostream>
#include <limits>
#include "Warehouse.h"
using namespace std;

// Sub-menu helper: Products or Suppliers
int askTarget() {
    int t;
    cout << "  1. Products   2. Suppliers : ";
    cin >> t;
    return t;
}

void showMenu() {
    cout << "\n===== WAREHOUSE INVENTORY MANAGEMENT =====" << endl;
    cout << "1. Add Record" << endl;
    cout << "2. Display Records" << endl;
    cout << "3. Search Record" << endl;
    cout << "4. Update Record" << endl;
    cout << "5. Delete Record" << endl;
    cout << "6. Place Order (Main Transaction)" << endl;
    cout << "7. Report" << endl;
    cout << "8. Save / Load" << endl;
    cout << "9. Exit" << endl;
    cout << "Choice: ";
}

int main() {
    Warehouse w;
    try {
        w.loadAll();                    // load existing records at start
    } catch (exception &e) {
        cout << "Load error: " << e.what() << endl;
    }

    int choice = 0;
    while (choice != 9) {
        showMenu();
        if (!(cin >> choice)) {         // user typed letters
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number 1-9." << endl;
            choice = 0;
            continue;
        }

        try {
            switch (choice) {
            case 1:
                if (askTarget() == 1) w.addProduct(); else w.addSupplier();
                break;
            case 2:
                if (askTarget() == 1) w.displayProducts(); else w.displaySuppliers();
                break;
            case 3:
                if (askTarget() == 1) w.searchProduct(); else w.searchSupplier();
                break;
            case 4:
                if (askTarget() == 1) w.updateProduct(); else w.updateSupplier();
                break;
            case 5:
                if (askTarget() == 1) w.deleteProduct(); else w.deleteSupplier();
                break;
            case 6: {
                int sub;
                cout << "  1. Place Order   2. View Orders : ";
                cin >> sub;
                if (sub == 1) w.placeOrder(); else w.displayOrders();
                break;
            }
            case 7:
                w.report();
                break;
            case 8: {
                int sub;
                cout << "  1. Save   2. Load : ";
                cin >> sub;
                if (sub == 1) w.saveAll(); else w.loadAll();
                break;
            }
            case 9:
                w.saveAll();            // auto-save on exit
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
            }
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}  