#include <bits/stdc++.h>
using namespace std;

const int V = 6; // number of vertices

vector<int> bellmanFord(int graph[V][V], int src) {
    vector<int>dist(V,INT_MAX);

    dist[src] = 0;

    for (int i = 0; i < V-1 ; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Check for negative-weight cycles. If we get a shorter path, then there is a cycle
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                cout << "Graph contains negative-weight cycle\n";
                return dist;
            }
        }
    }
    return dist;
}

int main() {
    int graph[V][V] = {
        {0, 6, 0, 0, 7, 0},
        {0, 0, 5, -4, 8, -2},
        {0, -2, 0, 0, 0, 0},
        {2, 0, 7, 0, 0, 0},
        {0, -3, 9, 2, 0, 0},
        {0, 0, 0, 0, -5, 0}
    };
    vector<int> dist = bellmanFord(graph, 0);
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
    {
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
        return 0;
}