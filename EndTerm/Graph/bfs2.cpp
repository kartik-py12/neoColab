// Single File Programming Question
// Problem Statement



// In a bustling city, the transportation network is crucial for the smooth flow of traffic. The city's transportation infrastructure can be represented as a graph, where each intersection is a node and the roads between intersections are edges.



// Your task is to implement a program that uses Breadth-First Search (BFS) traversal to analyze and map the transportation network, focusing on traffic congestion and proposing alternative routes to reduce traffic.

// Input format :
// The first line of input consists of two integers, V and E, separated by a space, where V represents the number of intersections (nodes) and E represents the number of roads (edges) connecting these intersections.

// The next E lines, each consisting of two integers, u and v, separated by a space, indicating a road (edge) between intersection u and intersection v.

// Output format :
// The output prints the BFS traversal order of the transportation network, separated by spaces.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 <= V <= 10

// 0 <= E <= V*(V-1)/2

// 0 <= u, v < V

// Sample test cases :
// Input 1 :
// 7 9
// 0 1
// 0 2
// 1 3
// 1 4
// 2 3
// 2 4
// 3 5
// 4 5
// 5 6
// Output 1 :
// 0 1 2 3 4 5 6 


// You are using GCC
#include <bits/stdc++.h>
using namespace std;


void bfs(int arr[10][10],int v){
    queue<int>q;
    bool visited[v]={false};
    int start=0;
    q.push(start);
    visited[start]=true;
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout<<current<<" ";
        
        for(int i=0;i<v;i++){
            if(arr[current][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    int arr[10][10];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        arr[u][v]=1;
    }
    bfs(arr,V);
}