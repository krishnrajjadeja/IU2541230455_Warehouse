#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

// Base class: common data for Product and Supplier
class Item {
protected:                 // protected = child classes can use it
    int id;
    string name;
public:
    Item() : id(0), name("") {}                    // default constructor
    Item(int i, string n) : id(i), name(n) {}      // parameterized constructor
    virtual ~Item() {}                             // virtual destructor

    int getId() const { return id; }               // getters
    string getName() const { return name; }
    void setName(string n) { name = n; }           // setter

    // "= 0" means children MUST write their own version (polymorphism)
    virtual void display() const = 0;
    virtual string toFileString() const = 0;
};
#endif