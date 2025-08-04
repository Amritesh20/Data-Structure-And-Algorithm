#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Adjacency matrix for the graph
int graph[MAX][MAX];

// Visited array to track the nodes
int visited[MAX];

// BFS Function using Queue
void bfs(int start, int n) {
    int queue[MAX], front = 0, rear = 0;

    // Initialize visited array for BFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Enqueue the start vertex
    queue[rear++] = start;
    visited[start] = 1;  // Mark the start vertex as visited

    printf("BFS Traversal: ");

    // Process the queue
    while (front < rear) {
        int vertex = queue[front++];  // Dequeue a vertex
        printf("%d ", vertex);        // Visit the node (print it)

        // Visit all adjacent vertices that haven't been visited
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;  // Enqueue unvisited adjacent vertex
                visited[i] = 1;      // Mark it as visited
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

    // Output BFS Traversal
    bfs(0, n);
    printf("\n");

    return 0;
}
