// Single File Programming Question
// Problem Statement



// Preethi is working on a project related to network optimization. She needs a program that can calculate the maximum flow between two nodes in a given network. 



// Preethi decided to use the Floyd-Warshall algorithm to achieve this.



// Write a program that calculates the maximum flow between two specified nodes in a network. The network is represented by a directed graph, and the program will determine the maximum flow from a source node to a sink node.

// Input format :
// The first line of input contains an integer, n, representing the number of nodes in the network, and m, representing the number of directed edges in the network.

// The next m lines contain three integers each: u, v, and w, representing a directed edge from node u to node v with a capacity of w units.

// The last line of input consists of two integers, source and sink, representing the source node and the sink node, respectively.

// Output format :
// If the sink node is unreachable from the source node, the output should display "Nodes are unreachable. Maximum flow is 0."

// Otherwise, the output should display "Maximum flow from node [source] to [sink] is: [maximum_flow]."

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ n ≤ 100 (number of nodes in the network)

// 1 ≤ u, v ≤ n (nodes represented by integers)

// 0 ≤ m ≤ n*(n-1) (number of edges)

// 0 ≤ w ≤ 1e9 (edge capacity)

// Sample test cases :
// Input 1 :
// 3 3
// 0 1 1
// 1 2 2
// 0 2 5
// 2 1
// Output 1 :
// Nodes are unreachable. Maximum flow is 0.
// Input 2 :
// 4 5
// 0 1 2
// 1 2 3
// 2 3 4
// 0 2 5
// 1 3 6
// 0 3
// Output 2 :
// Maximum flow from node 0 to 3 is: 8
// Input 3 :
// 3 2
// 0 1 2
// 1 2 3
// 0 1
// Output 3 :
// Maximum flow from node 0 to 1 is: 2

#include <iostream>
#include <cstdio>

#define INF 1000000000
#define MAXN 100


#include <iostream>
using namespace std;


void initializeGraph(int graph[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
}

void readEdges(int graph[100][100], int m) {
    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        graph[a][b] = w;
    }
}

void floydWarshall(int graph[100][100], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF &&
                    graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void printResult(int graph[100][100], int source, int sink) {
    if (graph[source][sink] == INF) {
        cout << "Nodes are unreachable. Maximum flow is 0." << endl;
    } else {
        cout << "Maximum flow from node " << source << " to " << sink << " is: "
             << graph[source][sink] << endl;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    int graph[MAXN][MAXN];
    initializeGraph(graph, n);
    readEdges(graph, m);

    int source, sink;
    std::cin >> source >> sink;

    floydWarshall(graph, n);
    printResult(graph, source, sink);

    return 0;
}