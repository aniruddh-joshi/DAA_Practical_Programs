#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 100 

int graph[MAX][MAX]; 
int color[MAX]; 
bool isBipartite = true; 
 
void BFS(int start, int vertices) { 
    queue<int>q;
    q.push(start);
    color[start]=1;

    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int i=0;i<vertices;i++){
            if(graph[current][i] && color[i]==-1){
                color[i]=1-color[current];
                q.push(i);
            }
            else if(graph[current][i] && color[i]==color[current]){
                isBipartite = false;
                return;
            }
        }
    }
} 
 
int main() { 
    int vertices; 
    cout<<"Enter the number of vertices: "; 
    cin>>vertices;
    cout<<"Enter the adjacency matrix:\n"; 
    for (int i = 0; i < vertices; i++) { 
        for (int j = 0; j < vertices; j++) { 
            cin >> graph[i][j]; 
        } 
    } 
    for (int i = 0; i < vertices; i++) { 
        color[i] = -1; 
    }
    for (int i = 0; i < vertices; i++) { 
        if (color[i] == -1) { 
            BFS(i, vertices); 
        } 
    } 
    if (isBipartite) { 
        cout<<"Graph is Bipartite \n"; 
    } else { 
        cout<<"Graph is not Bipartite \n"; 
    } 
    return 0; 
}