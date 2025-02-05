#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int vertices; // Number of vertices
    vector<list<int>> adjLists; // Adjacency lists

public:
    // Constructor
    Graph(int v) : vertices(v) {
        adjLists.resize(v);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest); // Add edge from src to dest
        adjLists[dest].push_back(src); // Add edge from dest to src (for undirected graph)
    }

    // Function to print the graph
    void printGraph() const {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ":";
            for (int neighbor : adjLists[i]) {
                cout << " -> " << neighbor;
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    if (vertices <= 0) {
        cout << "Number of vertices must be positive!" << endl;
        return 1;
    }

    Graph graph(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest;

        if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
            cout << "Invalid edge! Please enter vertices between 0 and " << vertices - 1 << "." << endl;
            i--; // Retry the current iteration
        } else {
            graph.addEdge(src, dest);
        }
    }

    graph.printGraph();

    return 0;
}
