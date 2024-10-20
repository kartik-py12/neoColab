/*
Single File Programming Question
Problem Statement



Imagine you are developing a program for a scientific research project. The project requires sorting a collection of experimental data represented by floating-point numbers. Your task is to implement a program that can sort the data using the Bubble Sort algorithm.



As the Bubble Sort algorithm progresses, the program should display intermediate results after each iteration, showing the partially sorted data and finally, the program should display the fully sorted array.

Input format :
The first line of input consists of an integer n, representing the number of floating-point numbers to be sorted. The The second line of input consists of n space-separated floating-point numbers, representing the collection of experimental data.

Output format :
The output displays "After iteration X:", where X is the iteration number, followed by the partially sorted array for each iteration.

The last line of output displays "Sorted array:" followed by the final sorted floating-point numbers.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ n ≤ 30

1.00 ≤ data ≤ 50.00

Sample test cases :
Input 1 :
4
16.37 21.51 12.90 18.80
Output 1 :
After iteration 1: 16.37 12.90 18.80 21.51 
After iteration 2: 12.90 16.37 18.80 21.51 
Sorted array: 12.90 16.37 18.80 21.51 
Input 2 :
3
39.48 32.39 22.1
Output 2 :
After iteration 1: 32.39 22.10 39.48 
After iteration 2: 22.10 32.39 39.48 
Sorted array: 22.10 32.39 39.48 
Input 3 :
7
5.0 1.0 4.0 2.0 8.0 12.0 3.0
Output 3 :
After iteration 1: 1.00 4.00 2.00 5.00 8.00 3.00 12.00 
After iteration 2: 1.00 2.00 4.00 5.00 3.00 8.00 12.00 
After iteration 3: 1.00 2.00 4.00 3.00 5.00 8.00 12.00 
After iteration 4: 1.00 2.00 3.00 4.00 5.00 8.00 12.00 
Sorted array: 1.00 2.00 3.00 

*/

// You are using GCC
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <float> arr;
    for(int i=0;i<n;i++){
        float element;
        cin>>element;
        arr.push_back(element);
    }
    for(int i=0;i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                float temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if(swapped){
        cout<<"After iteration "<<i+1<<": ";
        for(float elem:arr){
            cout<<fixed<<setprecision(2)<<elem<<" ";
        }
        cout<<endl;
        }
        
    }
    cout<<"Sorted array: ";
    for(float i:arr){
        cout<<i<<" ";
    }
}

