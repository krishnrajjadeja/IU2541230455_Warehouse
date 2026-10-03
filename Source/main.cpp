#include <iostream>
#include "FileManager.h"
#include "Product.h"
using namespace std;

int main() {
    try {
        FileManager fm;
        Product p1(1, "Laptop", "Electronics", 55000);
        Product p2(2, "Pen", "Stationery", 10);

        vector<string> lines;
        lines.push_back(p1.toFileString());
        lines.push_back(p2.toFileString());
        fm.saveLines("Data/test.txt", lines);
        cout << "Saved." << endl;

        vector<string> loaded = fm.loadLines("Data/test.txt");
        for (const string &l : loaded) {
            vector<string> parts = fm.split(l, '|');
            Product p(stoi(parts[0]), parts[1], parts[2], stod(parts[3]));
            p.display();
        }
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
