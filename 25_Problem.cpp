#include <iostream>
#include <climits>

#define V 4 // Number of vertices in the graph

// Function to find the shortest path with exactly k edges from source to destination
int shortestPathWithKEdges(int graph[V][V], int src, int dest, int k) {
    int dp[V][V][k+1]; // 3D array to store the shortest distance between each pair of vertices with k edges on the path
  
    // Initialize the 3D array with infinity for all pairs of vertices with k edges
    for (int e = 0; e <= k; e++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dp[i][j][e] = INT_MAX;
            }
        }
    }
  
    // Initialize the 3D array with the weight of the direct edges between the vertices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0) {
                dp[i][j][1] = graph[i][j];
            }
        }
    }
  
    // Compute the shortest distance between each pair of vertices with exactly k edges on the path
    for (int e = 2; e <= k; e++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                for (int x = 0; x < V; x++) {
                    if (graph[i][x] != 0 && dp[x][j][e-1] != INT_MAX) {
                        dp[i][j][e] = std::min(dp[i][j][e], dp[i][x][1] + dp[x][j][e-1]);
                    }
                }
            }
        }
    }
  
    // Return the shortest distance between the source and destination vertices with exactly k edges on the path
    return dp[src][dest][k];
}

int main() {
    // The example graph from the assignment
    int graph[V][V] = { {0, 10, 3, 0},
                        {0, 0, 0, 7},
                        {0, 0, 0, 6},
                        {0, 0, 0, 0} };
  
    int src = 1; // Source vertex
    int dest = 4; // Destination vertex
    int k = 2; // Number of edges on the path
  
    int shortestPath = shortestPathWithKEdges(graph, src, dest, k); // Find the weight of the shortest path
  
    if (shortestPath == INT_MAX) {
        std::cout << "There is no path with exactly " << k << " edges from vertex " << src << " to vertex " << dest << std::endl;
    } else {
        std::cout << "The weight of the shortest path with exactly " << k << " edges from vertex " << src << " to vertex " << dest << " is " << shortestPath << std::endl;
    }
  
    return 0;
}