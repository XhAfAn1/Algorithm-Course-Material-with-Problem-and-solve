#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int numVertices, numEdges;
bool visited[MAX];
int result[MAX];
int resultIndex;

void dfs(int u) {
    visited[u] = true;

    for (int v = 0; v < numVertices; v++) {
        if (graph[u][v] && !visited[v]) {
            dfs(v);
        }
    }

    result[resultIndex--] = u;
}

void topologicalSort() {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    resultIndex = numVertices - 1;

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> numVertices >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }

    topologicalSort();

    for (int i = 0; i < numVertices; i++) {
        cout << result[i];
        if (i != numVertices - 1) {
            cout << ", ";
        }
    }

    return 0;
}
