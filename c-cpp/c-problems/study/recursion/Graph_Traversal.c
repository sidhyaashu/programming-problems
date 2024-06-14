/*
Graph traversal involves visiting each vertex or edge in a graph exactly once.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph representation using adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

void dfs(int vertex, int vertices) {
    visited[vertex] = true;
    printf("%d ", vertex);
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i, vertices);
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    // Initialize graph and visited array
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
        for (int j = 0; j < MAX_VERTICES; j++)
            graph[i][j] = 0;
    }

    printf("Enter edge connections (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1; // Assuming undirected graph
    }

    int start_vertex;
    printf("Enter starting vertex for DFS traversal: ");
    scanf("%d", &start_vertex);

    printf("DFS Traversal: ");
    dfs(start_vertex, vertices);
    printf("\n");

    return 0;
}
