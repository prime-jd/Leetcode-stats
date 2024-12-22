#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Class to represent an Item with a name and price
class Item {
public:
    string itemName;
    int price;

    Item(string itemName, int price) {
        this->itemName = itemName;
        this->price = price;
    }
};

// Class to represent a Store with a name and items it sells
class Store {
public:
    string storeName;
    vector<Item> items;

    Store(string storeName) {
        this->storeName = storeName;
    }

    // Add an item to the store
    void addItem(string itemName, int price) {
        items.emplace_back(itemName, price);
    }
};

// Data structure to manage items across stores
class StoreManager {
private:
    unordered_map<string, vector<pair<string, int>>> itemToStores;

public:
    // Add a store's item to the manager
    void addStoreItem(const Store& store) {
        for (const auto& item : store.items) {
            itemToStores[item.itemName].emplace_back(store.storeName, item.price);
        }
    }

    // Get all stores selling a particular item and their prices
    void getStoresWithItem(const string& itemName) {
        if (itemToStores.find(itemName) == itemToStores.end()) {
            cout << "Item '" << itemName << "' is not available in any store.\n";
            return;
        }

        cout << "Stores selling '" << itemName << "':\n";
        for (const auto& store : itemToStores[itemName]) {
            cout << "Store: " << store.first << ", Price: " << store.second << endl;
        }
    }
};

int main() {
    // Create stores
    Store store1("Store1");
    store1.addItem("Apple", 100);
    store1.addItem("Banana", 50);

    Store store2("Store2");
    store2.addItem("Apple", 90);
    store2.addItem("Orange", 70);

    Store store3("Store3");
    store3.addItem("Banana", 55);
    store3.addItem("Apple", 95);

    // Create a StoreManager and add stores
    StoreManager manager;
    manager.addStoreItem(store1);
    manager.addStoreItem(store2);
    manager.addStoreItem(store3);

    // Query stores for an item
    manager.getStoresWithItem("Apple");
    manager.getStoresWithItem("Banana");
    manager.getStoresWithItem("Mango");

    return 0;
}
