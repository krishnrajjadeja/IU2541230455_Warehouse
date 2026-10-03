#include "Warehouse.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// ---------- Constructor: allocate dynamic memory ----------
Warehouse::Warehouse() {
    productCap = 5;   productCount = 0;   products  = new Product[productCap];
    supplierCap = 5;  supplierCount = 0;  suppliers = new Supplier[supplierCap];
    stockCap = 5;     stockCount = 0;     stocks    = new Stock[stockCap];
    orderCap = 5;     orderCount = 0;     orders    = new Order*[orderCap];
}

// ---------- Destructor: release dynamic memory ----------
Warehouse::~Warehouse() {
    for (int i = 0; i < orderCount; i++)
        delete orders[i];
    delete[] orders;
    delete[] products;
    delete[] suppliers;
    delete[] stocks;
}

// ---------- Grow arrays when full ----------
void Warehouse::growProducts() {
    productCap *= 2;
    Product* bigger = new Product[productCap];
    for (int i = 0; i < productCount; i++) bigger[i] = products[i];
    delete[] products;
    products = bigger;
}

void Warehouse::growSuppliers() {
    supplierCap *= 2;
    Supplier* bigger = new Supplier[supplierCap];
    for (int i = 0; i < supplierCount; i++) bigger[i] = suppliers[i];
    delete[] suppliers;
    suppliers = bigger;
}

void Warehouse::growStocks() {
    stockCap *= 2;
    Stock* bigger = new Stock[stockCap];
    for (int i = 0; i < stockCount; i++) bigger[i] = stocks[i];
    delete[] stocks;
    stocks = bigger;
}

void Warehouse::growOrders() {
    orderCap *= 2;
    Order** bigger = new Order*[orderCap];
    for (int i = 0; i < orderCount; i++) bigger[i] = orders[i];
    delete[] orders;
    orders = bigger;
}

// ---------- Finders: index or -1 ----------
int Warehouse::findProduct(int id) const {
    for (int i = 0; i < productCount; i++)
        if (products[i].getId() == id) return i;
    return -1;
}

int Warehouse::findSupplier(int id) const {
    for (int i = 0; i < supplierCount; i++)
        if (suppliers[i].getId() == id) return i;
    return -1;
}

int Warehouse::findStock(int productId) const {
    for (int i = 0; i < stockCount; i++)
        if (stocks[i].getProductId() == productId) return i;
    return -1;
}

// ---------- PRODUCTS ----------
void Warehouse::addProduct() {
    int id, qty, reorder;
    string name, category;
    double price;

    cout << "Product ID: ";       cin >> id;
    if (findProduct(id) != -1)
        throw runtime_error("Product ID already exists");
    cin.ignore();
    cout << "Name: ";             getline(cin, name);
    cout << "Category: ";         getline(cin, category);
    cout << "Price: ";            cin >> price;
    cout << "Opening quantity: "; cin >> qty;
    cout << "Reorder level: ";    cin >> reorder;

    Product p(id, name, category, price);
    Stock s(id, qty, reorder);

    if (productCount == productCap) growProducts();
    if (stockCount == stockCap) growStocks();
    products[productCount++] = p;
    stocks[stockCount++] = s;
    cout << "Product added." << endl;
}

void Warehouse::displayProducts() const {
    if (productCount == 0) { cout << "No products." << endl; return; }
    for (int i = 0; i < productCount; i++) {
        products[i].display();
        int s = findStock(products[i].getId());
        if (s != -1) { cout << "   "; stocks[s].display(); }
    }
}

void Warehouse::searchProduct() const {
    int id;
    cout << "Enter Product ID: "; cin >> id;
    int i = findProduct(id);
    if (i == -1) { cout << "Not found." << endl; return; }
    products[i].display();
    int s = findStock(id);
    if (s != -1) { cout << "   "; stocks[s].display(); }
}

void Warehouse::updateProduct() {
    int id;
    cout << "Enter Product ID to update: "; cin >> id;
    int i = findProduct(id);
    if (i == -1) { cout << "Not found." << endl; return; }

    string name, category;
    double price;
    cin.ignore();
    cout << "New name: ";     getline(cin, name);
    cout << "New category: "; getline(cin, category);
    cout << "New price: ";    cin >> price;

    products[i].setPrice(price);
    products[i].setName(name);
    products[i].setCategory(category);
    cout << "Product updated." << endl;
}

void Warehouse::deleteProduct() {
    int id;
    cout << "Enter Product ID to delete: "; cin >> id;
    int i = findProduct(id);
    if (i == -1) { cout << "Not found." << endl; return; }

    for (int j = i; j < productCount - 1; j++)
        products[j] = products[j + 1];
    productCount--;

    int s = findStock(id);
    if (s != -1) {
        for (int j = s; j < stockCount - 1; j++)
            stocks[j] = stocks[j + 1];
        stockCount--;
    }
    cout << "Product deleted." << endl;
}

// ---------- SUPPLIERS ----------
void Warehouse::addSupplier() {
    int id;
    string name, phone, city;

    cout << "Supplier ID: "; cin >> id;
    if (findSupplier(id) != -1)
        throw runtime_error("Supplier ID already exists");
    cin.ignore();
    cout << "Name: ";  getline(cin, name);
    cout << "Phone (10 digits): "; getline(cin, phone);
    cout << "City: ";  getline(cin, city);

    Supplier s(id, name, phone, city);
    if (supplierCount == supplierCap) growSuppliers();
    suppliers[supplierCount++] = s;
    cout << "Supplier added." << endl;
}

void Warehouse::displaySuppliers() const {
    if (supplierCount == 0) { cout << "No suppliers." << endl; return; }
    for (int i = 0; i < supplierCount; i++)
        suppliers[i].display();
}

void Warehouse::searchSupplier() const {
    int id;
    cout << "Enter Supplier ID: "; cin >> id;
    int i = findSupplier(id);
    if (i == -1) { cout << "Not found." << endl; return; }
    suppliers[i].display();
}

void Warehouse::updateSupplier() {
    int id;
    cout << "Enter Supplier ID to update: "; cin >> id;
    int i = findSupplier(id);
    if (i == -1) { cout << "Not found." << endl; return; }

    string name, phone, city;
    cin.ignore();
    cout << "New name: ";  getline(cin, name);
    cout << "New phone: "; getline(cin, phone);
    cout << "New city: ";  getline(cin, city);

    suppliers[i].setPhone(phone);
    suppliers[i].setName(name);
    suppliers[i].setCity(city);
    cout << "Supplier updated." << endl;
}

void Warehouse::deleteSupplier() {
    int id;
    cout << "Enter Supplier ID to delete: "; cin >> id;
    int i = findSupplier(id);
    if (i == -1) { cout << "Not found." << endl; return; }
    for (int j = i; j < supplierCount - 1; j++)
        suppliers[j] = suppliers[j + 1];
    supplierCount--;
    cout << "Supplier deleted." << endl;
}

// ---------- ORDERS (main transaction) ----------
void Warehouse::placeOrder() {
    int type, oid, pid, qty;
    string date;

    cout << "Order type (1 = Incoming, 2 = Outgoing): "; cin >> type;
    if (type != 1 && type != 2)
        throw invalid_argument("Order type must be 1 or 2");
    cout << "Order ID: "; cin >> oid;
    for (int i = 0; i < orderCount; i++)
        if (orders[i]->getOrderId() == oid)
            throw runtime_error("Order ID already exists");
    cout << "Product ID: "; cin >> pid;
    int s = findStock(pid);
    if (findProduct(pid) == -1 || s == -1)
        throw runtime_error("Product not found");
    cout << "Quantity: "; cin >> qty;
    cout << "Date (dd/mm/yyyy): "; cin >> date;

    Order* o;
    if (type == 1) o = new IncomingOrder(oid, pid, qty, date);
    else           o = new OutgoingOrder(oid, pid, qty, date);

    try {
        o->process(stocks[s]);          // runtime polymorphism
    } catch (...) {
        delete o;
        throw;
    }

    if (orderCount == orderCap) growOrders();
    orders[orderCount++] = o;
    cout << "Order placed. ";
    stocks[s].display();
}

void Warehouse::displayOrders() const {
    if (orderCount == 0) { cout << "No orders." << endl; return; }
    for (int i = 0; i < orderCount; i++)
        orders[i]->display();
}

// ---------- REPORT ----------
void Warehouse::report() const {
    cout << "===== WAREHOUSE REPORT =====" << endl;
    cout << "Products : " << productCount << endl;
    cout << "Suppliers: " << supplierCount << endl;
    cout << "Orders   : " << orderCount << endl;

    double totalValue = 0;
    for (int i = 0; i < productCount; i++) {
        int s = findStock(products[i].getId());
        if (s != -1)
            totalValue += products[i].getPrice() * stocks[s].getQuantity();
    }
    cout << "Total stock value: Rs." << totalValue << endl;

    cout << "--- Low stock items ---" << endl;
    bool any = false;
    for (int i = 0; i < stockCount; i++) {
        if (stocks[i].isLow()) {
            stocks[i].display();
            any = true;
        }
    }
    if (!any) cout << "None." << endl;
}

// ---------- SAVE ----------
void Warehouse::saveAll() const {
    vector<string> lines;

    for (int i = 0; i < productCount; i++)
        lines.push_back(products[i].toFileString());
    fm.saveLines("Data/products.txt", lines);

    lines.clear();
    for (int i = 0; i < supplierCount; i++)
        lines.push_back(suppliers[i].toFileString());
    fm.saveLines("Data/suppliers.txt", lines);

    lines.clear();
    for (int i = 0; i < stockCount; i++)
        lines.push_back(to_string(stocks[i].getProductId()) + "|" +
                        to_string(stocks[i].getQuantity()) + "|" +
                        to_string(stocks[i].getReorderLevel()));
    fm.saveLines("Data/stocks.txt", lines);

    lines.clear();
    for (int i = 0; i < orderCount; i++)
        lines.push_back(orders[i]->toFileString());
    fm.saveLines("Data/orders.txt", lines);

    cout << "Data saved." << endl;
}

// ---------- LOAD ----------
void Warehouse::loadAll() {
    for (int i = 0; i < orderCount; i++) delete orders[i];
    productCount = supplierCount = stockCount = orderCount = 0;

    vector<string> lines = fm.loadLines("Data/products.txt");
    for (const string &l : lines) {
        vector<string> p = fm.split(l, '|');
        if (p.size() < 4) continue;
        if (productCount == productCap) growProducts();
        products[productCount++] = Product(stoi(p[0]), p[1], p[2], stod(p[3]));
    }

    lines = fm.loadLines("Data/suppliers.txt");
    for (const string &l : lines) {
        vector<string> p = fm.split(l, '|');
        if (p.size() < 4) continue;
        if (supplierCount == supplierCap) growSuppliers();
        suppliers[supplierCount++] = Supplier(stoi(p[0]), p[1], p[2], p[3]);
    }

    lines = fm.loadLines("Data/stocks.txt");
    for (const string &l : lines) {
        vector<string> p = fm.split(l, '|');
        if (p.size() < 3) continue;
        if (stockCount == stockCap) growStocks();
        stocks[stockCount++] = Stock(stoi(p[0]), stoi(p[1]), stoi(p[2]));
    }

    lines = fm.loadLines("Data/orders.txt");
    for (const string &l : lines) {
        vector<string> p = fm.split(l, '|');
        if (p.size() < 5) continue;
        if (orderCount == orderCap) growOrders();
        // stock is already saved, so we do NOT call process() again
        if (p[1] == "INCOMING")
            orders[orderCount++] = new IncomingOrder(stoi(p[0]), stoi(p[2]), stoi(p[3]), p[4]);
        else
            orders[orderCount++] = new OutgoingOrder(stoi(p[0]), stoi(p[2]), stoi(p[3]), p[4]);
    }
    cout << "Data loaded." << endl;
}
