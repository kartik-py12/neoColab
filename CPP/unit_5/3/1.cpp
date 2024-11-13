// Single File Programming Question
// Problem Statement



// Meet Alice, a shop owner who wants to manage her inventory of products effectively. She has designed a system that allows customers to add products to their carts and calculate the total bill (total quantity x Price).



// To achieve this, Alice created an abstract class named Product, which holds basic product details like name, price, and quantity, and includes functions to add items to the cart and calculate the total bill. She also implemented a concrete class called Electronics, which inherits from Product and adds specific details such as warranty period.



// In this system, when a customer adds a product to their cart, the system should display the product details, including the total quantity and the total bill.

// Input format :
// The first line contains a string representing the name of the product.

// The second line contains a double representing the price of the product.

// The third line contains an integer representing the quantity of the product.

// The fourth line contains a string representing the warranty period of the product.

// The fifth line contains an integer representing the quantity of the product to add to the cart.

// Output format :
// The output should display the following sentences:

// "Product Name: [product name]" as a string.

// "Price per item: [price]" as a double, formatted by two decimal points.

// "Quantity: [total quantity after addition]" as an integer.

// "Warranty Period: [warranty period]" as a string.

// "Total Bill: [total bill]" as a double, formatted by two decimal points.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ quantity ≤ 100

// 1 ≤ quantityToAdd ≤ 100

// 1.0 ≤ Price ≤ 100000.0

// The [product name and warranty period will be a non-empty string

// Sample test cases :
// Input 1 :
// Laptop
// 1200.50
// 2
// 1 year
// 5
// Output 1 :
// Product Name: Laptop
// Price per item: 1200.50
// Quantity: 7
// Warranty Period: 1 year
// Total Bill: 8403.50
// Input 2 :
// Smartphone
// 799.99
// 3
// 2 years
// 2
// Output 2 :
// Product Name: Smartphone
// Price per item: 799.99
// Quantity: 5
// Warranty Period: 2 years
// Total Bill: 3999.95

// You are using GCC
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Product {
public:
    string name;
    double price;
    int quantity;

    Product(string name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

    void add_to_cart(int quantityToAdd) {
        this->quantity += quantityToAdd;
    }

    double calculate_bill() {
        return this->quantity * this->price;
    }
};

class Electronics : public Product {
public:
    string warranty_period;

    Electronics(string name, double price, int quantity, string warranty_period) : Product(name, price, quantity), warranty_period(warranty_period) {}
};

int main() {
    string product_name;
    double price;
    int quantity;
    string warranty_period;
    int quantityToAdd;

    getline(cin, product_name);
    cin >> price;
    cin >> quantity;
    getline(cin >> ws, warranty_period);
    cin >> quantityToAdd;

    Electronics product(product_name, price, quantity, warranty_period);
    product.add_to_cart(quantityToAdd);

    cout << "Product Name: " << product.name << endl;
    cout << "Price per item: " << fixed << setprecision(2) << product.price << endl;
    cout << "Quantity: " << product.quantity << endl;
    cout << "Warranty Period: " << product.warranty_period << endl;
    cout << "Total Bill: " << fixed << setprecision(2) << product.calculate_bill() << endl;

    return 0;
}