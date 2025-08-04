#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Adjacency matrix for the graph
int graph[MAX][MAX];

// Visited array to track the nodes
int visited[MAX];

// DFS Recursive Function
void dfs_recursive(int vertex, int n) {
    printf("%d ", vertex);  // Visit the node (print it)
    visited[vertex] = 1;     // Mark the node as visited

    // Visit all adjacent vertices that haven't been visited
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs_recursive(i, n);
        }
    }
}

// DFS Iterative Function
void dfs_iterative(int start, int n) {
    int stack[MAX];
    int top = -1;

    stack[++top] = start;  // Push the starting vertex to the stack
    visited[start] = 1;     // Mark the starting node as visited

    while (top >= 0) {
        int vertex = stack[top--];  // Pop from stack
        printf("%d ", vertex);      // Visit the node (print it)

        // Visit all adjacent vertices that haven't been visited
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                stack[++top] = i;  // Push unvisited adjacent vertex to stack
                visited[i] = 1;     // Mark it as visited
            }
        }
    }
}

int main() {
    int n = 5, edges = 4, u, v;

    // Static input: Predefined vertices and edges
    // Initialize the graph with all zeros (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Predefined edges (static)
    int predefined_edges[4][2] = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4}
    };

    // Adding predefined edges to the graph
    for (int i = 0; i < edges; i++) {
        u = predefined_edges[i][0];
        v = predefined_edges[i][1];
        graph[u][v] = 1;
        graph[v][u] = 1;  // For an undirected graph
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Output DFS Traversal using Recursive Method
    printf("DFS Traversal (Recursive): ");
    dfs_recursive(0, n);
    printf("\n");

    // Reset the visited array before using iterative DFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Output DFS Traversal using Iterative Method
    printf("DFS Traversal (Iterative): ");
    dfs_iterative(0, n);
    printf("\n");

    return 0;
}
