// Single File Programming Question
// Problem Statement



// Indira is a computer science student who is currently learning about graph algorithms. She is particularly interested in finding the shortest path between two vertices in a directed graph.



// To help her practice, you are tasked with writing a program that can compute and display the shortest path between two vertices in a directed graph using the Floyd-Warshall algorithm.

// Input format :
// The first line of input contains a single integer, V, representing the number of vertices in the directed graph.

// The next V lines each contain V integers, representing the adjacency matrix of the directed graph. A value of 0 indicates no direct edge between vertices, and a positive integer represents the weight of the edge. If there is no direct edge, you can consider it an infinite distance.

// The last two lines of input consist of two integers u and v, representing the source and destination vertices, to find the shortest path, separated by a line.

// Output format :
// The output displays the shortest path from vertex u to vertex v in the format: "Shortest path from [u] to [v]: [path]" where [path] is a sequence of vertices separated by "->".

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ V ≤ 100

// 0 ≤ edge weights ≤ 1e7

// Sample test cases :
// Input 1 :
// 4
// 0 3 10000000 7
// 8 0 2 10000000
// 5 10000000 0 1
// 2 10000000 10000000 0
// 3
// 2
// Output 1 :
// Shortest path from 3 to 2: 3 -> 0 -> 1 -> 2
// Input 2 :
// 4
// 0 3 10000000 7
// 8 0 2 10000000
// 5 10000000 0 1
// 2 10000000 10000000 0
// 1
// 3
// Output 2 :
// Shortest path from 1 to 3: 1 -> 2 -> 3
// Input 3 :
// 4
// 0 3 10000000 7
// 8 0 2 10000000
// 5 10000000 0 1
// 2 10000000 10000000 0
// 0
// 2
// Output 3 :
// Shortest path from 0 to 2: 0 -> 1 -> 2

#include <stdio.h>

#define MAXN 100
#define INF 10000000

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

// You are using GCC
#include <bits/stdc++.h>
using namespace std;
void initialise(int V, int graph[MAXN][MAXN]) {
    //Type your code here
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]!=INF && i!=j){
                dis[i][j]=graph[i][j];
                Next[i][j]=j;
            }
            else{
                dis[i][j]=(i==j)? 0:INF;
                Next[i][j]=-1;
            }
        }
    }
}

void floydWarshall(int V) {
    //Type your code here
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    Next[i][j]=Next[i][k];
                }
            }
        }
    }
}

void printPath(int path[], int n) {
    //Type your code here
    
    for(int i=0;i<n;i++){
        cout<<path[i];
        if(i<n-1){
            cout<<" -> ";
        }
    }
}


int main() {
    int V;
    scanf("%d", &V);

    int graph[MAXN][MAXN];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    initialise(V, graph);
    floydWarshall(V);

    int u, v;
    scanf("%d %d", &u, &v);

    int path[MAXN];
    path[0] = u;
    int index = 1;
    while (u != v) {
        u = Next[u][v];
        path[index++] = u;
    }

    printf("Shortest path from %d to %d: ", path[0], path[index - 1]);
    printPath(path, index);

    return 0;
}