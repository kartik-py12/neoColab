// Single File Programming Question
// Problem Statement



// Sophie runs a small retail business that sells both wooden furniture and electronics. To streamline her billing process, she needs a system that calculates the total amount based on the type of item purchased. She defines a base class ItemType with a pure virtual function calculateAmount(), which must be implemented by derived classes.



// The Wooden class allows Sophie to input the number of items and their cost, calculating the total amount by multiplying these values. The Electronics class requires only the cost and applies a 20% discount to provide the final amount (Final Amount = cost - discount, where discount = 0.20 x cost).

// Input format :
// The first line contains an integer choice:

// for Wooden items
// for Electronics items.
// If the choice is 1, the next line contains two space-separated values: the number of wooden items and their cost.

// If the choice is 2, the next line contains double values representing the cost of the electronic item.

// Output format :
// The output displays a double representing the final amount formatted to two decimal places.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ noOfWoodenItems ≤ 100

// 0.0 < cost ≤ 10,000.0

// Sample test cases :
// Input 1 :
// 1
// 5 840.0
// Output 1 :
// 4200.00
// Input 2 :
// 2
// 1800.0
// Output 2 :
// 1440.00

#include <iostream>
using namespace std;

class ItemType {
public:
    virtual double calculateAmount() = 0;
};

class Wooden : public ItemType {
private:
    int noOfWoodenItems;
    double cost;
public:
    Wooden(int noOfWoodenItems, double cost) : noOfWoodenItems(noOfWoodenItems), cost(cost) {}
    
    double calculateAmount() override {
        return noOfWoodenItems * cost;
    }
};

class Electronics : public ItemType {
private:
    double cost;
public:
    Electronics(double cost) : cost(cost) {}
    
    double calculateAmount() override {
        double discount = 0.20 * cost;
        return cost - discount;
    }
};

int main() {
    int choice;
    cin >> choice;
    
    ItemType *itemType;
    if (choice == 1) {
        int noOfWoodenItems;
        double cost;
        cin >> noOfWoodenItems >> cost;
        itemType = new Wooden(noOfWoodenItems, cost);
    } else if (choice == 2) {
        double cost;
        cin >> cost;
        itemType = new Electronics(cost);
    }
    
    cout.precision(2);
    cout << fixed;
    cout << itemType->calculateAmount() << endl;
    
    return 0;
}
