#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int vertices;

// Stack data structure
int stack[MAX_VERTICES];
int top = -1;

// Push operation for the stack
void push(int value) {
    stack[++top] = value;
}

// Pop operation for the stack
int pop() {
    return stack[top--];
}

// Check if the stack is empty
bool isStackEmpty() {
    return top == -1;
}

// Depth-First Search using a stack
void dfs(int start) {
    push(start);
    visited[start] = true;

    while (!isStackEmpty()) {
        int current = pop();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                push(i);
                visited[i] = true;
            }
        }
    }
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

    printf("Depth-First Search starting from vertex 0:\n");
    // for (int i = 0; i < vertices; i++) {
    //     visited[i] = false;
    // }
    dfs(0); // Start the DFS from vertex 0

    return 0;
}
