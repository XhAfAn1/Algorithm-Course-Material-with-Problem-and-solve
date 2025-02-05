#include <stdio.h>
#include <stdlib.h>

void createGraph(int vertices, int adjacencyMatrix[vertices][vertices]) {
    int i, j, edges;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: source destination):\n");
    for (i = 0; i < edges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);

        if (source >= vertices || destination >= vertices || source < 0 || destination < 0) {
            printf("Invalid edge! Please enter vertices between 0 and %d.\n", vertices - 1);
            i--; 
        } else {
            adjacencyMatrix[source][destination] = 1;
            adjacencyMatrix[destination][source] = 1; 
        }
    }
}

void printGraph(int vertices, int adjacencyMatrix[vertices][vertices]) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    if (vertices <= 0) {
        printf("Number of vertices must be positive!\n");
        return 1;
    }

    int adjacencyMatrix[vertices][vertices];

    createGraph(vertices, adjacencyMatrix);
    printGraph(vertices, adjacencyMatrix);

    return 0;
}