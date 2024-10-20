// Single File Programming Question
// Problem Statement



// Janu enjoys learning puzzles from her childhood. She is given an rxc matrix and asked to sum the elements in each row. She needs to attain the sum of elements in a matrix. Create a class named MatrixSum to handle the same.

// Input format :
// The first line contains an integer r, representing the number of rows in the matrix.

// The second line contains an integer c, representing the number of columns in the matrix.

// Following these, there are r lines, each containing c integers. These integers represent the elements of the matrix, row by row.

// Output format :
// The output prints elements of each row along with the sum of each row.



// Refer to the output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ r, c ≤ 10

// 0 ≤ elements ≤ 1000

// Sample test cases :
// Input 1 :
// 2
// 3
// 27 38 59
// 73 88 99
// Output 1 :
// 27 38 59 SUM: 124
// 73 88 99 SUM: 260
// Input 2 :
// 3
// 4
// 1 2 3 4
// 5 6 7 8
// 9 3 2 4
// Output 2 :
// 1 2 3 4 SUM: 10
// 5 6 7 8 SUM: 26
// 9 3 2 4 SUM: 18


// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

class MatrixSum{
    private:
        int r;
        int c;
        vector<vector<int>> arr;
    public:
        MatrixSum(int row,int col,const vector<vector<int>> &matrix):r(row),c(col),arr(matrix) {}
        
        void sum(){
            for(int i=0;i<r;i++){
                int rowSum=0;
                for(int j=0;j<c;j++){
                    cout<<arr[i][j]<<" ";
                    rowSum+=arr[i][j];
                }
                cout<<"SUM: "<<rowSum<<endl;
            }
        }
};

int main(){
    int row;
    int col;
    cin>>row;
    cin>>col;
    vector <vector<int>> matrix(row,vector <int> (col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    
    MatrixSum ms(row,col,matrix);
    ms.sum();
    
}
