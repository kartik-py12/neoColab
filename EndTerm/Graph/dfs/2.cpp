// Single File Programming Question
// Problem Statement



// Lithish is working on a project that involves analyzing the connectivity of various data points represented as vertices in a graph. He needs to perform Depth First Traversal (DFS) on the given graph (connected undirected graph) to explore its vertices and understand the relationships between them.



// Write a program to help Lithish perform DFS on the given graph.

// Input format :
// The first line of input consists of the two integers V and E, separated by a space. V represents the number of vertices, and E represents the number of edges in the graph.

// The next E lines consist of two integers, v and w, separated by a space, indicating an edge between vertex v and vertex w.

// The last line of input consists of the startVertex, representing the starting vertex for DFS traversal.

// Output format :
// The output should print the Depth First Traversal of the graph starting from a specified vertex, following format:

// "Depth First Traversal starting from vertex [vertex]:

// [u1] [u2] [u3]... [un]".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ V ≤ 10

// 0 <= E <= V*(V-1)/2

// 0 <= v, w < V

// 0 ≤ startVertex < V

// Sample test cases :
// Input 1 :
// 4 3
// 0 1
// 1 2
// 2 3
// 0
// Output 1 :
// Depth First Traversal starting from vertex 0:
// 0 1 2 3 
// Input 2 :
// 4 6
// 0 1
// 0 2
// 1 2
// 2 0
// 2 3
// 3 0
// 1
// Output 2 :
// Depth First Traversal starting from vertex 1:
// 1 2 0 3 


// You are using GCC
#include <bits/stdc++.h>
using namespace std;

void dfs(int arr[10][10],bool visited[],int start,int v){
    cout<<start<<" ";
    visited[start]=true;
    for(int i=0;i<v;i++){
        if(arr[start][i]==1 &&!visited[i]){
            visited[i]=true;
            dfs(arr,visited,i,v);
        }
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    int arr[10][10];
    bool visited[V]={false};
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        arr[u][v]=1;
    }
    int start;
    cin>>start;
    cout<<"Depth First Traversal starting from vertex "<<start<<":"<<endl;
    
    dfs(arr,visited,start,V);
}