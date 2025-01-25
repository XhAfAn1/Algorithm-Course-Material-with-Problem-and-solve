#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int numVertices, numEdges;
int visited[MAX];
int parent[MAX];
int discovery[MAX];
int finish[MAX];
int timeCounter;

void dfs(int u) {
    visited[u] = 1;
    discovery[u] = ++timeCounter;

    for(int v = 0; v < numVertices; v++) {
        if(graph[u][v]) {
            if(!visited[v]) {
                parent[v] = u;
                cout << u << "->" << v << ": tree edge" << endl;
                dfs(v);
            } else if(visited[v] == 1) {
                if(v != parent[u]) {
                    cout << u << "->" << v << ": back edge" << endl;
                }
            } else if(visited[v] == 2) {
                if(discovery[u] < discovery[v]) {
                    cout << u << "->" << v << ": forward edge" << endl;
                } else {
                    cout << u << "->" << v << ": cross edge" << endl;
                }
            }
        }
    }

    visited[u] = 2;
    finish[u] = ++timeCounter;
}

int main() {
    cin >> numVertices >> numEdges;

    for(int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    timeCounter = 0;
    for(int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    for(int i = 0; i < numVertices; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    return 0;
}

