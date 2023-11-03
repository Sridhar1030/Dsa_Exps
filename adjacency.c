#include <stdio.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Initialize the adjacency matrix with all zeros
void intMatrix(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Add an edge to the adjacency matrix
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1; // For an undirected graph, you should set both entries to 1.
}

// Display the adjacency matrix
void displayMatrix(int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    int start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the adjacency matrix with zeros
    intMatrix(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        if (start >= 0 && start < vertices && end >= 0 && end < vertices) {
            addEdge(start, end);
        } else {
            printf("Invalid edge, vertices out of range.\n");
            i--;
        }
    }

    displayMatrix(vertices);

    return 0;
}
