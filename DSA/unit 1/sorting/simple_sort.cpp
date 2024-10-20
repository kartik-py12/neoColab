/*
Single File Programming Question
Problem Statement



You have an array of integers that need to be sorted in ascending order. The array is sorted using an algorithm that repeatedly selects the smallest element from the unsorted portion of the array and swaps it with the first unsorted element. This process continues until the entire array is sorted.



Write a program to sort the array using the appropriate algorithm.

Input format :
The first line of the input consists of the size of the array N.

The second line of the input consists of array elements.

Output format :
The output displays the sorted array, separated by a space.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 50

1 ≤ array elements ≤ 1000

Sample test cases :
Input 1 :
5
26 14 33 27 54
Output 1 :
14 26 27 33 54 
Input 2 :
8
24 56 78 31 15 62 76 94
Output 2 :
15 24 31 56 62 76 78 94 
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
                int temp = arr[i];
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
