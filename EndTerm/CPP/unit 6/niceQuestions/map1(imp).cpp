// Single File Programming Question
// Problem Statement



// Isha is a store manager at a local supermarket. She needs a program to manage the inventory at the supermarket. The inventory management system should allow her to perform various tasks like adding products to the inventory, updating the quantity of existing products, and displaying the inventory details.



// Isha's Requirements:



// The program should use algorithms and iterators to efficiently search for products and update their quantities.

// The inventory system should support a maximum of 100 different products.

// The user should be able to choose from the following options:

// 1: Add a new product to the inventory.

// 2: Update the quantity of an existing product in the inventory.

// 3: Display the details of all the products in the inventory.

// 4: Exit the program.

// Input format :
// The input consists of an integer representing their choice from the available options (1, 2, 3, or 4).



// For option 1 (Add Product), the user will enter the product name (a string with no spaces), the product quantity (an integer), and the product price (a double value).

// For option 2 (Update Quantity), the user will enter the product name (a string with no spaces) and the new quantity (an integer).

// For option 3 (Display Inventory), there is no additional input required.

// Output format :
// The output displays the following format:



// For choices 1, 2, and 4, there should be no specific output other than appropriate status messages for adding products, updating quantities, and exiting the loop.



// For choice 3 (Display Inventory), the program should display the current inventory details in the following format:

// Inventory Details:

// Name: <product_name>, Quantity: <quantity>, Price: $<price>

// The details of each product should be displayed on separate lines.



// If Isha chooses option 2 (Update Quantity) for a product that is not present in the inventory, the program should display the following message:

// Product not found in inventory.



// If Isha chooses option 4 (exit program), The program should display the Invalid choice.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The product name is a string without spaces and contains at most 100 characters.

// The quantity of a product is a positive integer not exceeding 1000.

// The price of a product is a floating-point number not exceeding 10000.00.

// Sample test cases :
// Input 1 :
// 1
// Laptop
// 10
// 90000.1
// 2
// Laptop
// 11
// 3
// 7
// 4
// Output 1 :
// Inventory Details:
// Name: Laptop, Quantity: 11, Price: $90000.1
// Invalid choice
// Input 2 :
// 1
// Laptop
// 10
// 800.50
// 2
// Mouse
// 8
// 3
// 4
// Output 2 :
// Product not found in inventory.
// Inventory Details:
// Name: Laptop, Quantity: 10, Price: $800.5

// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main(){
    int choice;
    int n;
    map<string,pair<int,double>> arr;
    while(true){
        cin>>choice;
        if(choice==1){
            string name;
            cin>>name;
            int quantity;
            cin>>quantity;
            double price;
            cin>>price;
            arr[name].first=quantity;
            arr[name].second=price;
            n++;
        }
        else if(choice == 2){
            string name;
            cin>>name;
            int quantity;
            cin>>quantity;
            if(arr.find(name)!=arr.end()){
                arr[name].first=quantity;
                
            }else{
                cout<<"Product not found in inventory."<<endl;
            }
        }
        else if(choice == 3){
            cout<<"Inventory Details:"<<endl;
            for(auto &pair:arr){
                cout<<"Name: "<<pair.first<<", Quantity: "<<pair.second.first<<", Price: $"<<fixed<<setprecision(1)<<pair.second.second<<endl;
            }
        }
        else if(choice == 4){
            break;
        }
        
        else{
            cout<<"Invalid choice"<<endl;;
        }
    }
}