PROJECT: Warehouse Inventory Management System
Project Code: CPP25
Name: Krishnraj Jadeja
Enrollment No: IU2541230455
Class: CSE E
GitHub: https://github.com/krishnrajjadeja/IU2541230455_Warehouse

DESCRIPTION
A console-based C++ program to manage warehouse products, suppliers,
stock levels and orders. Data is saved to text files, so it is
available again when the program is reopened.

CLASSES
Item (base), Product, Supplier, Stock, Order (base),
IncomingOrder, OutgoingOrder, Warehouse, FileManager

OOP CONCEPTS USED
Classes and objects, encapsulation, default and parameterized
constructors, destructors, inheritance, runtime polymorphism,
dynamic memory (new[] / delete[]), file handling, validation,
exception handling, modular .h/.cpp files.

HOW TO COMPILE
g++ Source/*.cpp -o Executable/Project

HOW TO RUN
./Executable/Project        (Linux)
Project.exe                 (Windows)

MENU
1. Add Record        6. Place Order / View Orders
2. Display Records   7. Report
3. Search Record     8. Save / Load
4. Update Record     9. Exit (auto-saves)
5. Delete Record

FOLDERS
Source/       source code (.h and .cpp)
Data/         saved data files (.txt)
Diagrams/     Use Case, Class, 2 Sequence diagrams
Executable/   Project.exe
Screenshots/  program screenshots