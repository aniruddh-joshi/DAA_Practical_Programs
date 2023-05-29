#include <bits/stdc++.h>
using namespace std;

const int V = 6; // number of vertices

vector<int> dijkstra(int source, int graph[V][V]) {
    // initialize distance array with infinite values
    vector<int> dist(V, INT_MAX);
    // create set on basis (distance, node)
    set<pair<int, int>> st;
    // initialize distance and set with source
    dist[source] = 0;
    st.insert(make_pair(0, source));
    while (!st.empty()) {
        // fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        // remove top record now
        st.erase(st.begin());
        // traverse on neighbors
        for (int i = 0; i < V; i++) {
            if (graph[topNode][i] != 0) { // if there is an edge between topNode and i
                int neighborNode = i;
                int neighborWeight = graph[topNode][i];
                if (nodeDistance + neighborWeight < dist[neighborNode]) {
                    auto record = st.find(make_pair(dist[neighborNode], neighborNode));
                    // if record found, then erase it
                    if (record != st.end()) {
                        st.erase(record);
                    }
                    // distance update
                    dist[neighborNode] = nodeDistance + neighborWeight;
                    // record push in set
                    st.insert(make_pair(dist[neighborNode], neighborNode));
                }
            }
        }
    }
    return dist;
}

int main() {
    int graph[V][V] = {
        {0, 7, 9, 0, 0, 14}, 
        {7, 0, 10, 15, 0, 0}, 
        {9, 10, 0, 11, 0, 2}, 
        {0, 15, 11, 0, 6, 0}, 
        {0, 0, 0, 6, 0, 9}, 
        {14, 0, 2, 0, 9, 0}
    };
    vector<int> dist = dijkstra(0, graph);
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
    {
        printf("%d \t\t %d\n", i, dist[i]); 
    }
        return 0;
    }