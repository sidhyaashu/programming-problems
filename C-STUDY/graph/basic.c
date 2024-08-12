#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a new graph with given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize adjacency matrix to 0 (no edges)
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices) {
        graph->adjacencyMatrix[source][destination] = 1;
        // For undirected graph, uncomment the line below
        // graph->adjacencyMatrix[destination][source] = 1;
    } else {
        printf("Invalid vertex index.\n");
    }
}

// Depth First Search (DFS) traversal
void DFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex);

    // Traverse adjacent vertices
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to initialize visited array and start DFS traversal
void DFSTraversal(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Initialize visited array to 0

    printf("DFS Traversal: ");
    DFS(graph, startVertex, visited);
    printf("\n");
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Print DFS traversal from vertex 0
    DFSTraversal(graph, 0);

    return 0;
}
