#include <iostream>
using namespace std;

#define INF 10000000
#define MAXN 100

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

void initialise(int V, int graph[MAXN][MAXN]) {
    //Type your code here
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i!=j && graph[i][j]!=INF){
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

void printPath(int n) {
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
    cin >> V;

    int graph[MAXN][MAXN];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    initialise(V, graph);
    floydWarshall(V);

    int u = 0; // Top-left corner
    int v = V - 1; // Bottom-right corner

    int path[MAXN];
    path[0] = u;
    int index = 1;
    while (u != v) {
        u = Next[u][v];
        path[index++] = u;
    }

    printPath(index);

    return 0;
}