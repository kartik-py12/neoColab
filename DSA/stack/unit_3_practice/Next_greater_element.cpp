// Single File Programming Question
// Problem Statement



// John is analyzing the stock market and wants to know the next greater element (NGE) for each stock price in an array. Write a program to help him find the NGE for each element. Implement a stack using an array for this.



// Company Tags: Capgemini

// Input format :
// The first line of input contains an integer n, representing the number of stock prices.

// The second line contains n space-separated integers, representing the stock prices.

// Output format :
// The output prints each stock price followed by its next greater element (or -1 if there is none).



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 20

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 4
// 11 13 21 3
// Output 1 :
// 11 13
// 13 21
// 21 -1
// 3 -1
// Input 2 :
// 4
// 4 5 2 25
// Output 2 :
// 4 5
// 5 25
// 2 25
// 25 -1
// Input 3 :
// 5
// 5 4 3 2 1
// Output 3 :
// 5 -1
// 4 -1
// 3 -1
// 2 -1
// 1 -1

// // You are using GCC
// #include <iostream>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         int ele;
//         cin>>ele;
//         arr[i]=ele;
//     }
//     int brr[n]={0};
    
//     for (int i = 0; i < n; i++) {
//     brr[i] = arr[i];
// }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<i;j++){
//             if(brr[i]<brr[j]){
//                 int temp =brr[i];
//                 brr[i]=brr[j];
//                 brr[j]=temp;
//             }
//         }
//     }
    
//     for(int i=0;i<n;i++){
//         if(i==n-1){
//             cout<<brr[i]<<" "<<-1<<endl;
//         }else{
            
//         cout<<brr[i]<<endl;
//         }
//     }
// }


#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;  // Input number of elements
    
    int arr[n];
    
    // Input array elements

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }



    // Array to store next greater elements, initialized to -1
    int nge[n];
    
    stack<int> s;  // Stack to store indexes
    
    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Maintain the decreasing order in the stack
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        
        // If stack is not empty, the top element is the next greater
        if (!s.empty()) {
            nge[i] = arr[s.top()];
        } else {
            nge[i] = -1;  // No greater element found
        }
        
        // Push current element index onto the stack
        s.push(i);
    }
    
    // Output the array elements with their next greater element
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " << nge[i] << endl;
    }

    return 0;
}