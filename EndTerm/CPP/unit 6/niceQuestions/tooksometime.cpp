// Single File Programming Question
// Problem Statement



// In a data analysis system, you are provided with an array of integer elements representing the scores of students in a game. Your task is to process the scores and convert the array into its reduced form using vectors of pairs. Additionally, you need to implement two functions, convert() and printArr() to handle the conversion and display the reduced form, respectively.



// convert() Function:

// Implement the convert() function, which takes the input array of integer elements and returns the reduced form of the array using vectors of pairs. The function should assign a new value to each element of the array based on its position when the elements are sorted in ascending order.

// The smallest element in the array should be assigned the value 0.
// The second smallest element should be assigned the value 1.
// ...
// The largest element should be assigned the value n-1, where n is the number of elements in the array.


// printArr() Function:

// Implement the printArr() function to display the elements of the reduced form array.



// Please write the code for the two functions, convert() and printArr(), to accomplish the given scenario. The main function will handle the input of the array and call these functions to convert and display the reduced form of the array.



// Example



// Input:

// 5

// 48 12 8 96 42



// Output:

// Input Array: 48 12 8 96 42 

// Converted Array: 3 1 0 4 2 

// Input format :
// The first line consists of the array size and the second line consists of array elements separated by a space.

// Output format :
// The output displays the input array and converted array in separate lines.

// Code constraints :
// 0 < Array Size <= 15

// Sample test cases :
// Input 1 :
// 5
// 48 12 8 96 42
// Output 1 :
// Input Array: 48 12 8 96 42 
// Converted Array: 3 1 0 4 2 
// Input 2 :
// -8
// Output 2 :
// -1

// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<0){
        cout<<-1;
        return 0;
    }
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int temp[n]={0};
   vector<pair<int,int>> temp(n);
    cout<<"Input Array: ";
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    int temp2[n];
    for(int i=0;i<n;i++){
        temp2[i]=arr[i];;
    }
    sort(temp2,temp2+n);
    for(int i=0;i<n;i++){
        temp[i]={temp2[i],i};
        // temp[i]=arr[i];
    }
    
    cout<<"Converted Array: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]==temp[j].first){
                cout<<temp[j].second<<" ";
            }
        }
    }
    
    
}
