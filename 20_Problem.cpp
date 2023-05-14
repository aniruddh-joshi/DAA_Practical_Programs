#include<iostream>
#define MAX 100
using namespace std;

int graph[MAX][MAX];
int visited[MAX];
int pathExists = 0;

void DFS(int current, int destination) {
    visited[current] = 1;
    if (current == destination) {
        pathExists = 1;
        return;
    }
    for (int i = 1; i <= MAX; i++) {
        if (graph[current][i] && !visited[i]) {
            DFS(i, destination);
        }
    }
}

int main() {
    int vertices, source, destination;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<"Enter the adjacency matrix:\n";
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            cin>>graph[i][j];
        }
    }
    cout<<"Enter source and destination vertex numbers: ";
    cin>>source>>destination;
    DFS(source, destination);
    if (pathExists) {
        cout<<"Yes Path Exists\n";
    } else {
        cout<<"No Such Path Exists\n";
    }
    return 0;
}