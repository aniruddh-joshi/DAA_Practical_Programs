#include<bits/stdc++.h>

using namespace std;

const int MAX= 100;

int graph[MAX][MAX];
vector<bool> visited(MAX,false);
vector<bool> recStack(MAX,false);

bool isCyclicUtil(int vertex,int vertices){
    if(!visited[vertex]){
        visited[vertex] = true;
        recStack[vertex] = true;

        for(int i=0;i<vertices;i++){
            if(graph[vertex][i]){
                if(!visited[i] && isCyclicUtil(i,vertices)){
                    return true;
                }
                else  if(recStack[i]){
                    return true;
                }
            }
        }
    }
    recStack[vertex]= false;
    return false;
}

bool isCyclic(int vertices){
    for(int i=0;i<vertices;i++){
        visited[i]=false;
        recStack[i]=false;
    }

    for(int i=0;i<vertices;i++){
        if(isCyclicUtil(i,vertices)){
            return true;
        }
    }
    return false;
}

int main(){
    int vertices;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<"Enter the adjacency matrix: "<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cin>> graph[i][j];
        }
    }

    if(isCyclic(vertices)){
        cout<<"Cycle exists in the graph"<<endl;
    }
    else{
        cout<<"Cycle does not exist in the graph"<<endl;
    }
    return 0;
}