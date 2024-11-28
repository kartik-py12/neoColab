// Single File Programming Question
// Problem Statement



// Rohit is responsible for scheduling flights for an airline company. He has a list of N flights numbered from 0 to N-1. Some flights have specific constraints that require them to depart after other flights.



// Write a program to help Rohit determine if it's possible to create a flight schedule that adheres to these constraints using Warshall's algorithm.



// Example 1



// Input:

// 5

// 0 1

// 1 2

// 2 3

// 3 4

// 4 5



// Output:

// Yes



// Explanation:

// Flight 0 must depart after Flight 1.

// Flight 1 must depart after Flight 2.

// Flight 2 must depart after Flight 3.

// Flight 3 must depart after Flight 4.

// Flight 4 must depart after Flight 5.

// There are no circular dependencies or conflicts in the schedule, so it is possible to create a flight schedule that adheres to the constraints.



// Example 2



// Input:

// 6

// 0 1

// 1 2

// 2 3

// 3 4

// 4 5

// 5 0



// Output:

// No



// Explanation:

// Flight 0 must depart after Flight 1.

// Flight 1 must depart after Flight 2.

// Flight 2 must depart after Flight 3.

// Flight 3 must depart after Flight 4.

// Flight 4 must depart after Flight 5.

// Flight 5 must depart after Flight 0.

// There is a circular dependency in the flight constraints. Therefore, it is not possible to create a flight schedule that follows the constraints.

// Input format :
// The first line of input consists of an integer N, representing the number of flights.

// The following N lines consist of two space-separated integers each: the flight number and the flight number that must depart before it.

// Output format :
// If it is possible to create a flight schedule that adheres to the constraints, print "Yes".

// Otherwise, print "No".

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// Sample test cases :
// Input 1 :
// 5
// 0 1
// 1 2
// 2 3
// 3 4
// 4 5
// Output 1 :
// Yes
// Input 2 :
// 6
// 0 1
// 1 2
// 2 3
// 3 4
// 4 5
// 5 0
// Output 2 :
// No


// You are using GCC
#include <bits/stdc++.h>
using namespace std;

bool algo(int arr[10][10],int n){
    int mat[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=arr[i][j];
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=mat[i][j] ||(mat[i][k] && mat[k][j]);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(mat[i][i]==1){
            return false;
        }
    }
    return true;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

int main(){
    int n;
    cin>>n;
    int graph[10][10]={0};
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
    }
    if(algo(graph,n)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}