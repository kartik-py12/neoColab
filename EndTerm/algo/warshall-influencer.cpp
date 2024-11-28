// Single File Programming Question
// Problem Statement



// Virat is given a group of individuals, and he wants to identify if there is an influential individual within the group. An influential individual is defined as someone who is followed by more people than they follow.



// He is provided with a list of follow-up relationships among the individuals in the form of a matrix. Your task is to help Virat determine if there is an influential individual and, if so, find their index within the group.



// Write a program to solve this problem using Warshall's Algorithm. 

// Input format :
// The first line of input consists of an integer N, representing the number of individuals in the group.

// The following N lines will contain N space-separated integers, representing the following relationship matrix for the individuals.

// Output format :
// If an influential individual is found, print "Influential Individual: X," where X is the index (0-based) of the influential individual.

// Otherwise, print "There is no influential individual in the group".



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
// Influential Individual: 2
// Input 2 :
// 5
// 0 1 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 0 0 0 0 1
// 0 0 0 0 0
// Output 2 :
// There is no influential individual in the group
// Input 3 :
// 3
// 0 1 1
// 0 0 0
// 0 1 0
// Output 3 :
// Influential Individual: 1

// You are using GCC
#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;

int findInfluentialIndividual(int arr[MAX_N][MAX_N], int n) {
    //Type your code here
    int mat[MAX_N][MAX_N];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=arr[i][j];
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=mat[i][j] || (mat[i][k] && mat[k][j]);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for(int i=0;i<n;i++){
        
        bool knownByAll=true;
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0 && i!=j){
                knownByAll=false;
                break;
            }
        }
        bool knowNoOne=true;
        for(int k=0;k<n;k++){
            if(arr[k][i]!=1 && i!=k){
                knowNoOne=false;
                break;
            }
        }
        
        if(knownByAll && knowNoOne){
            return i;
        }
    }
    
    return -1;
    
}

int main() {
    int n;
    scanf("%d", &n);
    
    int acquaintances[MAX_N][MAX_N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &acquaintances[i][j]);
        }
    }

    int influentialIndividualIndex = findInfluentialIndividual(acquaintances, n);

    if (influentialIndividualIndex != -1) {
        printf("Influential Individual: %d", influentialIndividualIndex);
    } else {
        printf("There is no influential individual in the group");
    }

    return 0;
}