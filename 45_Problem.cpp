#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to perform Depth-First Search (DFS).
    int dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        int count = 0;
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                count += dfs(nbr, adj, vis);
            }
        }
        return count + 1;
    }

    // Function to find the mother vertex in the graph.
    int findMotherVertex(int V, vector<int> adj[]) {
        for (int i = 0; i < V; i++) {
            vector<int> vis(V, 0);
            if (!vis[i]) {
                if (dfs(i, adj, vis) == V) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Creating an adjacency list to represent the graph.
    vector<int> adj[V];
    cout << "Enter the edges (source and destination):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
    }

    Solution obj;
    int motherVertex = obj.findMotherVertex(V, adj);

    if (motherVertex != -1) {
        cout << "Mother vertex found: " << motherVertex << endl;
    } else {
        cout << "No mother vertex found in the graph." << endl;
    }

    return 0;
}