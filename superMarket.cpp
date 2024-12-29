#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

// Base Classes
class Item {
public:
    std::string name;
    std::string category;
    std::string subCategory;
    double pricePerUnit;
    double discount;

    Item(std::string name, std::string category, std::string subCategory, double price, double discount)
        : name(name), category(category), subCategory(subCategory), pricePerUnit(price), discount(discount) {}
};

class CartItem {
public:
    Item item;
    double quantity;

    CartItem(Item item, double quantity) : item(item), quantity(quantity) {}
};

class Customer {
public:
    std::string name;
    std::vector<CartItem> cart;

    Customer(std::string name) : name(name) {}

    void addItemToCart(CartItem cartItem) {
        cart.push_back(cartItem);
    }
};

// Discount Calculator
class DiscountCalculator {
public:
    static double calculateBestDiscount(const Item& item, double quantity, const std::unordered_map<std::string, double>& categoryDiscounts) {
        double itemTotal = item.pricePerUnit * quantity;
        double itemDiscount = itemTotal * (item.discount / 100);
        double subCategoryDiscount = itemTotal * (categoryDiscounts.at(item.subCategory) / 100);
        double categoryDiscount = itemTotal * (categoryDiscounts.at(item.category) / 100);

        return std::max({itemDiscount, subCategoryDiscount, categoryDiscount});
    }
};

// Invoice Generation
class Invoice {
public:
    static void generateInvoice(const Customer& customer, const std::unordered_map<std::string, double>& categoryDiscounts) {
        double totalAmount = 0.0;
        double totalSavings = 0.0;

        std::cout << "Customer: " << customer.name << "\n\n";
        std::cout << std::setw(20) << "Item"
                  << std::setw(10) << "Qty"
                  << std::setw(10) << "Amount\n";
        std::cout << "----------------------------------------\n";

        for (const auto& cartItem : customer.cart) {
            double itemTotal = cartItem.item.pricePerUnit * cartItem.quantity;
            double discount = DiscountCalculator::calculateBestDiscount(cartItem.item, cartItem.quantity, categoryDiscounts);
            double finalAmount = itemTotal - discount;

            std::cout << std::setw(20) << cartItem.item.name
                      << std::setw(10) << cartItem.quantity
                      << std::setw(10) << std::fixed << std::setprecision(2) << finalAmount << "\n";

            totalAmount += finalAmount;
            totalSavings += discount;
        }

        std::cout << "----------------------------------------\n";
        std::cout << "Total Amount: " << totalAmount << " Rs\n";
        std::cout << "You saved: " << totalSavings << " Rs\n";
    }
};

int main() {
    // Category Discounts
    std::unordered_map<std::string, double> categoryDiscounts = {
        {"Produce", 10.0}, {"Fruits", 18.0}, {"Veg", 5.0},
        {"Dairy", 15.0},   {"Milk", 20.0},   {"Cheese", 20.0}
    };

    // Items
    Item apple("Apple", "Produce", "Fruits", 50.0, 3.0);
    Item orange("Orange", "Produce", "Fruits", 80.0, 20.0);
    Item potato("Potato", "Produce", "Veg", 30.0, 0.0);
    Item tomato("Tomato", "Produce", "Veg", 70.0, 10.0);
    Item cowMilk("Cow Milk", "Dairy", "Milk", 50.0, 0.0);
    Item gouda("Gouda", "Dairy", "Cheese", 80.0, 10.0);

    // Customer and Cart
    Customer customer("Anish Kumar");
    customer.addItemToCart(CartItem(apple, 6));
    customer.addItemToCart(CartItem(orange, 2));
    customer.addItemToCart(CartItem(potato, 14));
    customer.addItemToCart(CartItem(tomato, 3));
    customer.addItemToCart(CartItem(cowMilk, 8));
    customer.addItemToCart(CartItem(gouda, 2));

    // Generate Invoice
    Invoice::generateInvoice(customer, categoryDiscounts);

    return 0;
}
