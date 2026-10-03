#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "Product.h"
#include "Supplier.h"
#include "Stock.h"
#include "Order.h"
#include "FileManager.h"

class Warehouse {
private:
    // Dynamic arrays (created with new[], freed with delete[])
    Product*  products;   int productCount;   int productCap;
    Supplier* suppliers;  int supplierCount;  int supplierCap;
    Stock*    stocks;     int stockCount;     int stockCap;
    Order**   orders;     int orderCount;     int orderCap;

    FileManager fm;

    int findProduct(int id) const;
    int findSupplier(int id) const;
    int findStock(int productId) const;
    void growProducts();
    void growSuppliers();
    void growStocks();
    void growOrders();

public:
    Warehouse();
    ~Warehouse();

    void addProduct();
    void displayProducts() const;
    void searchProduct() const;
    void updateProduct();
    void deleteProduct();

    void addSupplier();
    void displaySuppliers() const;
    void searchSupplier() const;
    void updateSupplier();
    void deleteSupplier();

    void placeOrder();
    void displayOrders() const;

    void report() const;

    void saveAll() const;
    void loadAll();
};
#endif
