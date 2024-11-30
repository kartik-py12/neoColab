#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>  // For sorting the neighbors
using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        // If the node is not visited, process it
        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
        }

        // Push all unvisited neighbors onto the stack, sorting the neighbors first
        // Sorting neighbors ensures the desired order of traversal
        vector<int> neighbors = adj[node];
        sort(neighbors.begin(), neighbors.end());  // Sort the neighbors
        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V); // Adjacency list for the graph

    // Read edges and populate the adjacency list
    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        adj[v].push_back(w);
        adj[w].push_back(v); // Since the graph is undirected
    }

    int startVertex;
    cin >> startVertex;

    vector<bool> visited(V, false);

    // Print the result
    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    dfs(startVertex, adj, visited);
    cout << endl;

    return 0;
}
