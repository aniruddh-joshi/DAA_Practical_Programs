#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a city and its associated cost
struct City {
    int id;
    int cost;
};

// Function to compare cities based on their costs
struct CityComparator {
    bool operator()(const City& city1, const City& city2) {
        return city1.cost > city2.cost;
    }
};

// Function to calculate the minimum cost using Prim's algorithm
int calculateMinimumCost(vector<vector<int>>& graph) {
    int numCities = graph.size();
    vector<bool> visited(numCities, false); // Track visited cities
    priority_queue<City, vector<City>, CityComparator> pq; // Priority queue for selecting cities

    // Start with the first city
    pq.push({0, 0});

    int minimumCost = 0;

    while (!pq.empty()) {
        City currentCity = pq.top();
        pq.pop();

        int cityId = currentCity.id;
        int cityCost = currentCity.cost;

        // Skip the city if already visited
        if (visited[cityId])
            continue;

        // Mark the current city as visited
        visited[cityId] = true;

        // Add the cost to the minimum cost
        minimumCost += cityCost;

        // Visit the neighbors of the current city
        for (int i = 0; i < numCities; i++) {
            if (!visited[i] && graph[cityId][i] != 0) {
                // Add the neighboring city to the priority queue
                pq.push({i, graph[cityId][i]});
            }
        }
    }

    return minimumCost;
}

int main() {
    // Read the number of cities
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    // Create a graph to represent the cities and roads
    vector<vector<int>> graph(numCities, vector<int>(numCities, 0));

    // Read the costs of roads between cities
    cout << "Enter the costs of roads (0 if no road exists):\n";
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            cin >> graph[i][j];
        }
    }

    // Calculate the minimum cost
    int minimumCost = calculateMinimumCost(graph);

    cout << "Minimum cost required to connect the cities: " << minimumCost << endl;

    return 0;
}
