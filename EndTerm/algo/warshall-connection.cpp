// Single File Programming Question
// Problem Statement



// Harish is given a network of nodes and connections represented by a matrix of size NxN, where N is the number of nodes in the network. Each cell connections[i][j] in the matrix contains a value of either 1 or 0.



// If connections[i][j] is 1, it means there is a direct connection between Node i and Node j.
// If connections[i][j] is 0, it means there is no direct connection between Node i and Node j.


// Your task is to help Harish write a program using Warshall's Algorithm that determines whether there exists a chain of connections that can be followed to travel from a source node to a target node in the network.

// Input format :
// The first line of input consists of an integer N, representing the number of nodes in the network.

// The following N lines consist of N space-separated integers (1 or 0), representing the connections in the matrix.

// The last line consists of two space-separated integers i and j, representing the source node and the target node.

// Output format :
// If there exists a chain of connections from the source node to the target node, print "Yes".

// Otherwise, print "No".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// Each element of the matrix is either 0 or 1.

// Sample test cases :
// Input 1 :
// 3
// 0 1 0
// 0 0 1
// 1 0 0
// 1 2
// Output 1 :
// Yes
// Input 2 :
// 4
// 0 1 0 0
// 0 0 0 1
// 0 0 0 1
// 0 0 0 0
// 2 1
// Output 2 :
// No

#include <iostream>
using namespace std;

#define MAX_NODES 100

// You are using GCC
bool hasChainOfConnections(int n, int arr[MAX_NODES][MAX_NODES], int source, int target) {
    //Type your code here
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=arr[i][j] || (arr[i][k] && arr[k][j]);
            }
        }
    }
    if(arr[source][target]==1){
        return true;
    }else{
        return false;
    }
}

int main() {
    int n; // Number of nodes
    cin >> n;

    int connections[MAX_NODES][MAX_NODES] = {0};

    // Taking input for direct connections
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> connections[i][j];
        }
    }

    int source, target;
    cin >> source >> target;

    if (hasChainOfConnections(n, connections, source, target)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}