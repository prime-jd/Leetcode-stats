#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Base class for a Menu Item
class MenuItem {
public:
    string name;
    double price;
    
    MenuItem(string name, double price) : name(name), price(price) {}
};

// Inventory Item with quantity management
class InventoryItem {
public:
    string name;
    int quantity;
    
    InventoryItem(string name, int quantity) : name(name), quantity(quantity) {}

    // Deducts the quantity based on the order
    bool useItem(int qty) {
        if (quantity >= qty) {
            quantity -= qty;
            return true;
        }
        return false;
    }
};

// Order class to manage an individual order
class Order {
public:
    int orderId;
    unordered_map<string, int> items;  // item name -> quantity
    double totalCost;
    string status;
    
    Order(int id) : orderId(id), totalCost(0.0), status("Processing") {}

    // Add item to order
    void addItem(string itemName, int quantity, double price) {
        items[itemName] += quantity;
        totalCost += price * quantity;
    }

    void displayOrder() {
        cout << "Order ID: " << orderId << ", Status: " << status << endl;
        cout << "Items:\n";
        for (const auto& item : items) {
            cout << " - " << item.first << ": " << item.second << endl;
        }
        cout << "Total Cost: $" << totalCost << endl;
    }

    void completeOrder() {
        status = "Completed";
    }
};

// User class to represent a customer or staff
class User {
public:
    string name;
    string role; // customer, cashier, manager

    User(string name, string role) : name(name), role(role) {}
};

// CoffeeShop class to manage orders, inventory, and menu
class CoffeeShop {
private:
    int nextOrderId;
    unordered_map<string, MenuItem> menu;
    unordered_map<string, InventoryItem> inventory;
    vector<Order> orders;

public:
    CoffeeShop() : nextOrderId(1) {}

    // Menu Management
    void addMenuItem(const string& name, double price) {
        menu[name] = MenuItem(name, price);
    }

    void displayMenu() {
        cout << "\nMenu:\n";
        for (const auto& item : menu) {
            cout << item.first << " - $" << item.second.price << endl;
        }
    }

    // Inventory Management
    void addInventoryItem(const string& name, int quantity) {
        inventory[name] = InventoryItem(name, quantity);
    }

    void displayInventory() {
        cout << "\nInventory:\n";
        for (const auto& item : inventory) {
            cout << item.first << " - Quantity: " << item.second.quantity << endl;
        }
    }

    // Order Management
    void placeOrder(User& user, unordered_map<string, int> items) {
        Order order(nextOrderId++);
        
        for (const auto& item : items) {
            if (menu.find(item.first) != menu.end() && inventory[item.first].useItem(item.second)) {
                order.addItem(item.first, item.second, menu[item.first].price);
            } else {
                cout << "Sorry, " << item.first << " is unavailable or out of stock.\n";
            }
        }
        
        orders.push_back(order);
        order.displayOrder();
    }

    void completeOrder(int orderId) {
        for (auto& order : orders) {
            if (order.orderId == orderId) {
                order.completeOrder();
                cout << "Order " << orderId << " completed.\n";
                return;
            }
        }
        cout << "Order not found.\n";
    }
};

int main() {
    CoffeeShop myCoffeeShop;

    // Setup Menu
    myCoffeeShop.addMenuItem("Espresso", 3.0);
    myCoffeeShop.addMenuItem("Latte", 4.5);
    myCoffeeShop.addMenuItem("Cappuccino", 4.0);

    // Setup Inventory
    myCoffeeShop.addInventoryItem("Espresso", 50);
    myCoffeeShop.addInventoryItem("Latte", 30);
    myCoffeeShop.addInventoryItem("Cappuccino", 20);

    // Display Menu and Inventory
    myCoffeeShop.displayMenu();
    myCoffeeShop.displayInventory();

    // Create a User
    User customer("Alice", "customer");

    // Place an Order
    unordered_map<string, int> items = { {"Espresso", 2}, {"Latte", 1} };
    myCoffeeShop.placeOrder(customer, items);

    // Complete an Order
    myCoffeeShop.completeOrder(1);

    return 0;
}
