// Single File Programming Question
// Problem Statement



// Reema, a brilliant intergalactic explorer, is on a mission to map out the shortest paths between different planets in a distant galaxy. She has access to a galactic network that provides information about the distances between planets. 



// Reema needs your help to write a program that can calculate the shortest path from Earth (represented by index 0) to any other planet in the galaxy using the Floyd-Warshall algorithm.

// Input format :
// The first line of input consists of an integer V, representing the number of planets in the galaxy.

// The next V lines, each of which contains V space-separated integers. The value in graph[i][j] represents the distance between planet i and planet j. If two planets are not directly connected, the distance is set to INF (1e7).

// The last line of input consists of an integer dest, representing the index of the destination planet she wants to reach from Earth.

// Output format :
// The output should display the shortest path from Earth to the destination planet.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ V ≤ 10

// 0 ≤ graph[i][j] ≤ 107

// 0 ≤ dest < V

// If there is no direct connection between two planets, the distance is represented as 1e7 (10000000).

// Sample test cases :
// Input 1 :
// 3
// 0 1 2
// 1 0 3
// 2 3 0
// 1
// Output 1 :
// Shortest path from Earth to planet 1: 0 -> 1
// Input 2 :
// 4
// 0 5 10000000 10
// 10000000 0 3 10000000
// 10000000 10000000 0 1
// 10000000 10000000 10000000 0
// 0
// Output 2 :
// Shortest path from Earth to planet 0: 0


#include <iostream>
using namespace std;

#define INF 1e7
#define MAXN 100

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];


// You are using GCC
void initialise(int V, int graph[MAXN][MAXN]) {
    //Type your code here
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]!=INF && i!=j){
                dis[i][j]=graph[i][j];
                Next[i][j]=j;
            }else{
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
    cin >> V;

    int graph[MAXN][MAXN];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    initialise(V, graph);
    floydWarshall(V);

    int source = 0; 

    int dest;
    cin >> dest;

    int path[MAXN];
    path[0] = source;
    int index = 1;
    while (source != dest) {
        source = Next[source][dest];
        path[index++] = source;
    }

    cout << "Shortest path from Earth to planet " << dest << ": ";
    printPath(path, index);

    return 0;
}