#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge between two cities
struct Edge {
    int src;
    int dest;
    int weight;
};

// Function to compare edges based on their weights
struct EdgeComparator {
    bool operator()(const Edge& edge1, const Edge& edge2) {
        return edge1.weight < edge2.weight;
    }
};

// Find operation for disjoint set
int find(vector<int>& parent, int city) {
    if (parent[city] == -1)
        return city;
    return find(parent, parent[city]);
}

// Union operation for disjoint set
void unionSet(vector<int>& parent, int city1, int city2) {
    parent[city1] = city2;
}

// Function to calculate the minimum cost using Kruskal's algorithm
int calculateMinimumCost(vector<Edge>& edges, int numCities) {
    vector<int> parent(numCities, -1);
    int minimumCost = 0;
    int numEdges = 0;

    // Sort the edges based on their weights
    sort(edges.begin(), edges.end(), EdgeComparator());

    // Select edges one by one and add them to the minimum spanning tree
    for (int i = 0; i < edges.size(); i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        int srcParent = find(parent, src);
        int destParent = find(parent, dest);

        // Check if adding the current edge creates a cycle
        if (srcParent != destParent) {
            minimumCost += weight;
            unionSet(parent, srcParent, destParent);
            numEdges++;
        }

        // Stop when we have N-1 edges in the minimum spanning tree
        if (numEdges == numCities - 1)
            break;
    }

    return minimumCost;
}

int main() {
    // Read the number of cities
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    // Create a vector of edges to represent the cities and roads
    vector<Edge> edges;

    // Read the adjacency matrix or adjacency list
    cout << "Enter the graph in the form of adjacency matrix or adjacency list:\n";
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            int weight;
            cin >> weight;

            // Add non-zero edges to the vector
            if (weight != 0 && j > i)
                edges.push_back({i, j, weight});
        }
    }

    // Calculate the minimum cost
    int minimumCost = calculateMinimumCost(edges, numCities);

    cout << "Minimum cost required to connect the cities: " << minimumCost << endl;

    return 0;
}
