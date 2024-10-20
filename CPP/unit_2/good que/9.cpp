// Single File Programming Question
// Problem Statement



// Rina is managing the inventory for a library, where each row of a 2D matrix represents the number of different genres of books available on each shelf. To get a better overview, she wants to replace each number in a row with the sum of all numbers in that row. 



// Write a program to help Rina transform the matrix accordingly.

// Input format :
// The first line of input consists of an integer T, representing the number of test cases.

// For each test case:

// The first line contains two integers R and C, representing the number of rows and columns.
// The next R lines each contain C space-separated integers, representing the count of books of a specific genre on a shelf.
// Output format :
// For each test case, the output prints the transformed 2D matrix where each element in a row is replaced with the sum of the elements in that row.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ T ≤ 10

// 1 ≤ R, C ≤ 10

// 0 ≤ books count ≤ 100

// Sample test cases :
// Input 1 :
// 2 
// 3 4
// 8 2 4 9
// 4 5 6 1
// 7 8 9 3
// 2 5
// 1 2 3 5 7
// 3 4 8 9 6
// Output 1 :
// 23 23 23 23 
// 16 16 16 16 
// 27 27 27 27 
// 18 18 18 18 18 
// 30 30 30 30 30 
// Input 2 :
// 1
// 3 3 
// 48 65 83 
// 45 21 76 
// 71 32 98 
// Output 2 :
// 196 196 196 
// 142 142 142 
// 201 201 201 

// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

void transform(int r,int c,vector<vector<int>>&matrix){
    for(int i=0;i<r;i++){
        int rowsum=0;
        for(int j=0;j<c;j++){
            rowsum+=matrix[i][j];
        }
        for(int j=0;j<c;j++){
            matrix[i][j]=rowsum;
        }
    }
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases>0){
        int r,c;
        cin>>r>>c;
        vector<vector<int>> matrix(r,vector <int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>matrix[i][j];
            }
        }
        
        transform(r,c,matrix);
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
        testCases--;
    }
}