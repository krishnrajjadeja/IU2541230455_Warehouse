#ifndef STOCK_H
#define STOCK_H

class Stock {
private:
    int productId;
    int quantity;
    int reorderLevel;
public:
    Stock();
    Stock(int pid, int qty, int reorder);
    ~Stock();

    int getProductId() const;
    int getQuantity() const;
    int getReorderLevel() const;

    void addStock(int qty);        // incoming
    void removeStock(int qty);     // outgoing (throws if not enough)
    bool isLow() const;            // true if below reorder level
    void display() const;
};
#endif
