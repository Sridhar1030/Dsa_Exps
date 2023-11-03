#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;
int vertices;

// Enqueue operation for the queue
void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full. Cannot enqueue more elements.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

// Dequeue operation for the queue
int dequeue() {
    int vertex;
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return vertex;
    }
}

// Breadth-First Search function
void bfs(int startVertex) {
    printf("Breadth-First Search starting from vertex %d:\n", startVertex);
    enqueue(startVertex);
    visited[startVertex] = true;

    while (front != -1) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

int main() {
    int edges;
    int start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the graph with all zeros (no edges)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        if (start >= 0 && start < vertices && end >= 0 && end < vertices) {
            graph[start][end] = 1; // Assuming it's an unweighted graph
            graph[end][start] = 1; // For an undirected graph, set both entries to 1.
        } else {
            printf("Invalid edge, vertices out of range.\n");
            i--;
        }
    }

    // Initialize the visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    bfs(0); // Start the BFS from vertex 0

    return 0;
}
