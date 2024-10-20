// Single File Programming Question
// Problem Statement



// You are tasked with creating a program for an online shop to calculate the total number of items purchased for a single product. The program should take the product name and the number of items purchased by three persons and then calculate and display the total number of items for that product using member functions.

// Input format :
// The first line consists of a string representing the product name.

// The second line consists of three integers a, b, and c representing the number of items purchased by three different persons.

// Output format :
// The program prints the product name and the sum of the total number of items purchased for the product in separate lines.



// Refer to the sample output for the exact format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ a, b, c ≤ 1000

// Sample test cases :
// Input 1 :
// Phone
// 2 5 4
// Output 1 :
// Product Name: Phone
// Total items: 11
// Input 2 :
// Shirt
// 278 499 790
// Output 2 :
// Product Name: Shirt
// Total items: 1567

// You are using GCC
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shop{
    private:
        string name;
        vector <int> items;
    public:
        Shop(string n,const vector<int>&arr):name(n),items(arr) {}
        
        void total(){
            int sum=0;
            cout<<"Product Name: "<<name<<endl;
            for(int i=0;i<3;i++){
                sum+=items[i];
            }
            cout<<"Total items: "<<sum;
        }
};

int main(){
    string n;
    vector<int>arr(3);
    cin>>n;
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }

    Shop shop(n,arr);
    shop.total();
}