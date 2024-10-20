// Single File Programming Question
// Problem Statement



// Preethi is working at a bookstore and needs to manage the inventory. Her bookstore receives shipments from two different suppliers, and she wants to find the books that are common between the two shipments.



// Preethi wants your help to solve her problem. Help her write a program to find the intersection of the two shipment lists based on the book id numbers and help her update the inventory accordingly using pointer arithmetic.

// Input format :
// The first line contains an integer size1, representing the number of products sold in the first period.

// The second line contains size1 integers, representing the product IDs of the sold products in the first period.

// The third line contains an integer size2, representing the number of products sold in the second period.

// The fourth line contains size2 integers, representing the product IDs of the sold products in the second period.

// Output format :
// If there are common product IDs, they are printed in a single line separated by spaces.

// If there are no common product IDs, the output is "No common IDs found".



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ size1, size2 ≤ 10

// 1 ≤ product ID ≤ 1000

// Sample test cases :
// Input 1 :
// 4
// 101 110 122 157
// 3
// 97 122 157
// Output 1 :
// 122 157 
// Input 2 :
// 3
// 24 8 9
// 4 
// 24 9 10 15
// Output 2 :
// 24 9 
// Input 3 :
// 4
// 101 102 103 104
// 3
// 201 202 203
// Output 3 :
// No common IDs found

// You are using GCC
#include <iostream>
using namespace std;

int main(){
    int size1;
    int size2;
    cin>>size1;
    int* ptr = new int[size1];
    
    for(int i=0;i<size1;i++){
        cin>>ptr[i];
    }

    cin>>size2;    
    int* ptr1 = new int[size2];
    
    for(int i=0;i<size2;i++){
        cin>>ptr1[i];
    }
    
    bool common=false;
    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if(ptr[i]==ptr1[j]){
                cout<<ptr[i]<<" ";
                common=true;
            }
        }
    }
    if(!common){
        cout<<"No common IDs found";
    }
}