// Single File Programming Question
// Problem Statement



// Stefan is working on a project that involves finding the shortest paths between locations on a network. He needs a program to help him calculate the shortest paths efficiently. 



// He heard about the Floyd-Warshall algorithm and decided to implement it.



// Write a program that takes a directed graph as input, applies the Floyd-Warshall algorithm to compute the shortest paths between all pairs of vertices, and then finds and prints the shortest path between two given vertices.

// Input format :
// The first line of input contains a single integer, V, the number of vertices in the graph.

// The next V lines each contain V integers, representing the adjacency matrix of the directed graph. The value of graph [i][j] represents the weight of the edge from vertex i to vertex j. If there is no direct edge from vertex i to vertex j, graph [i][j] will be 0. If the vertices are not connected, use a large positive integer (e.g., 1e7) to represent infinity (no direct edge).

// The last two lines of input consist of two integers, u and v, representing the two vertices needed to find the shortest path.

// Output format :
// The output displays the shortest path from vertex u to vertex v in the format: "Shortest path from [u] to [v]: [path]" where [path] is a sequence of vertices separated by "->".

// Code constraints :
// 1 ≤ V ≤ 100

// Sample test cases :
// Input 1 :
// 4
// 0 3 10000000 7
// 8 0 2 10000000
// 5 10000000 0 1
// 2 10000000 10000000 0
// 0
// 2
// Output 1 :
// Shortest path from 0 to 2: 0 -> 1 -> 2
// Input 2 :
// 4
// 0 3 10 7
// 8 0 2 1
// 5 9 0 1
// 2 4 8 0
// 0
// 2
// Output 2 :
// Shortest path from 0 to 2: 0 -> 1 -> 2
// Input 3 :
// 5
// 0 3 10 7 8
// 8 0 2 1 4
// 5 9 0 1 2
// 2 4 8 0 1
// 4 2 1 2 0
// 0
// 3
// Output 3 :
// Shortest path from 0 to 3: 0 -> 1 -> 3



#include <stdio.h>

#define MAXN 100
#define INF 10000000

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

// You are using GCC
using namespace std;
#include <bits/stdc++.h>

void initialise(int V, int graph[MAXN][MAXN]) {
    //Type your code here
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]!=INF && i!=j){
                dis[i][j]=graph[i][j];
                Next[i][j]=j;
            }
            else{
                dis[i][j]=(i==j)?0:INF;
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

//fotter

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