/*
Single File Programming Question
Problem statement



Janani needs a program to sort bike registration numbers in ascending order using an insertion sort algorithm. Help her with a program that takes the number of bikes parked and their registration numbers as input, then outputs the sorted registration numbers.

Input format :
The first line of input consists of an integer N, representing the number of bikes.

The second line consists of N space-separated integers representing the registration numbers of N bikes.

Output format :
The output displays the registration numbers in ascending order, separated by a space.



﻿Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

2 ≤ N ≤ 20

1000 ≤ registration numbers ≤ 9999

Sample test cases :
Input 1 :
4
9899 7877 6766 1000
Output 1 :
1000 6766 7877 9899 
Input 2 :
7
2220 3264 6489 9080 4099 8719 8066
Output 2 :
2220 3264 4099 6489 8066 8719 9080
*/

// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                
            }
        }
    }
    
    for(int ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}