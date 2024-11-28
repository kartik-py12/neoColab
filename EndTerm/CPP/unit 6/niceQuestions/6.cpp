// Single File Programming Question
// Problem Statement



// Happy Paws, owned by Kaushik, is a pet onboarding system that prioritizes maintaining accurate and up-to-date records of all registered pets. The system utilizes a list called "petDataList" to store comprehensive details about each pet, including their unique ID.



// To empower pet owners with control over their pets' information, the system has implemented a custom function called "removeElement." This function allows pet owners to request the removal of their pet's record from the system by providing the pet's ID (target) as input.



// The "removeElement" function efficiently handles these requests, ensuring a well-organized and streamlined pet onboarding process for all pet owners. 



// Note: This kind of question will be helpful in clearing TCS recruitment.

// Input format :
// The first line of input consists of the number of pets of the "petDataList", N.

// The second line of input consists of the pet IDs separated by a space.

// The third line of input consists of the pet ID to be removed from the list, M.

// Output format :
// The program will display the updated "petDataList" after removing all occurrences of the specified pet ID.

// If it is not present in the list, the input will be printed as such.

// Code constraints :
// 1 <= M, N <= 105

// Sample test cases :
// Input 1 :
// 5
// 6 69 1 26 15
// 15
// Output 1 :
// 6 69 1 26 
// Input 2 :
// 5
// 6 69 1 26 15
// 158
// Output 2 :
// 6 69 1 26 15 

// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int rem;
    cin>>rem;
    
    for(int i:arr){
        if(i!=rem){
            cout<<i<<" ";
        }
    }
    
}