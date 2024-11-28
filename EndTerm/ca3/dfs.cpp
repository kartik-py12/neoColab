// Single File Programming Question
// Problem Statement



// Virat is given a group of individuals, and he wants to identify if there is a most trusted individual within the group. A most trusted individual is defined as someone who is trusted by everyone else but trusts no one in return. In other words, the most trusted individual is followed by all other individuals (except themselves) but does not follow anyone else.



// To solve this problem, Virat uses a relationship matrix that represents the acquaintanceship between individuals. Your task is to help Virat determine if there is a most trusted individual in the group and, if so, find their index.



// Write a program that implements this logic using Warshall's Algorithm to check for the most trusted individual in the group based on the trust relationships represented in the matrix.

// Input format :
// The first line consists of an integer N representing the number of individuals in the group.

// The next N lines contain N space-separated integers, where the element at position [i][j] represents whether individual i trusts individual j (1 for trust, 0 for no trust).

// Output format :
// If a most trusted individual is found, print: "Most Trusted Individual: X", where X is the index (0-based) of the most trusted individual.

// Otherwise, print: "There is no most trusted individual in the group".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// Each element of the relationship matrix is either 0 or 1.

// Sample test cases :
// Input 1 :
// 4
// 0 1 1 0
// 0 0 1 0
// 0 0 0 0
// 0 0 1 0
// Output 1 :
// Most Trusted Individual: 2
// Input 2 :
// 5
// 0 1 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 0 0 0 0 1
// 0 0 0 0 0
// Output 2 :
// There is no most trusted individual in the group
// Input 3 :
// 3
// 0 1 1
// 0 0 0
// 0 1 0
// Output 3 :
// Most Trusted Individual: 1

//57
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100

int ftv(int arr[MAX_N][MAX_N],int n){
    int mat[MAX_N][MAX_N];
    //filling mat
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=arr[i][j];
        }
    }

    //warshall algo
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=mat[i][j] || (mat[i][k] && mat[k][j]);
            }
        }
    }
    
    //13
    //influncer

    for(int i=0;i<n;i++){
        bool knownByAll=true;
        bool knowNoONe=true;
        for(int j=0;j<n;j++){
            if(mat[i][j]!=0 && i!=j){
                knownByAll=false;
                break;
            }
        }

        for(int k=0;k<n;k++){
            if(mat[k][i]!=1 && i!=k){
                knowNoONe=false;
                break;
            }
        }

        if(knownByAll && knowNoONe){
            return i;
        }
    } 
    return -1;
}

int main() {
    int n;
    cin >> n; 
    
    int acquaintances[MAX_N][MAX_N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> acquaintances[i][j];
        }
    }

    int trustedIndividualIndex = ftv(acquaintances, n);

    if (trustedIndividualIndex != -1) {
        cout << "Most Trusted Individual: " << trustedIndividualIndex;
    } else {
        cout << "There is no most trusted individual in the group";
    }

    return 0;
}