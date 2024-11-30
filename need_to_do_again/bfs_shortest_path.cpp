//took 20 mins to do was getting stuck at s.push(i) part in this printShortestDistance

// Single File Programming Question
// Problem Statement



// Shailu is developing a navigation application designed to assist users in locating the shortest route between two points within a city. The city's layout is represented as a graph, where each location serves as a vertex and the roads connecting them are represented as edges.



// Your objective is to create a program that employs the Breadth-First Search (BFS) algorithm to determine the shortest path between a specified source location and a destination location.									

// Input format :
// The first line consists of two integers v and e, representing the number of locations (vertices) in the city and the number of roads (edges) connecting the locations.

// The next e lines contain two space-separated integers src and dest, denoting a road (edge) between location src and location dest.

// The next line consists of an integer source, indicating the starting location.

// The last line consists of an integer destination, indicating the destination location.

// Output format :
// The output is displayed in the following format:



// The first line consists of "Shortest path length is: X", where X represents the shortest path length.

// The second line consists of "Path is: ", followed by the nodes in the shortest path, space-separated.



// Refer to the sample output for the exact format.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ v ≤ 10

// 0 ≤ e ≤ v * (v - 1) / 2

// 0 ≤ source, destination < v

// Sample test cases :
// Input 1 :
// 6 7
// 1 1
// 1 2
// 1 3
// 1 4
// 2 4
// 3 5
// 4 5
// 4 
// 5
// Output 1 :
// Shortest path length is: 1
// Path is: 4 5 


// You are using GCC
//84

#include <bits/stdc++.h>
using namespace std;
void add_edge(int adj[][100], int src, int dest)
{
    //Type your code   
    adj[src][dest]=1;
}

bool BFS(int adj[][100], int src, int dest, int v, int pred[], int dist[])
{
    //Type your code
    queue<int>q;
    fill(dist,dist+v,-1);
    fill(pred,pred+v,-1);
    bool visited[v]={false};
    q.push(src);
    visited[src]=1;
    dist[src]=0;
    
    while(!q.empty()){
        int current=q.front();
        q.pop();
        
        if(current==dest){
            break;
        }
        
        for(int i=0;i<v;i++){
            if(adj[current][i]==1 && !visited[i]){
                visited[i]=true;
                q.push(i);
                dist[i]=dist[current]+i;
                pred[i]=current;
            }
        }
    }
    
    if(dist[dest]==-1){
        return false;
    }
    else{
        return true;
    }
    
  
}

void printShortestDistance(int adj[][100], int ss, int dest, int v, int pred[], int dist[])
{
    //Type your code
    stack<int>s;
    int count=-1;
    
    for(int i=dest;i!=-1;i=pred[i]){
        s.push(i);
        count++;
    }
    cout<<"Shortest path length is: "<<count<<endl;
    cout<<"Path is: ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}


int main()
{
    int v, e;
    cin >> v;

    int adj[100][100] = {0};

    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        add_edge(adj, src, dest);
    }

    int source, dest;
    cin >> source >> dest;

    int pred[v], dist[v];

    if (BFS(adj, source, dest, v, pred, dist))
        printShortestDistance(adj, source, dest, v, pred, dist);
   
    return 0;
}