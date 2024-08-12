/**
 Degree of a Vertex: Function to find the degree of a given vertex.
Check if Graph is Connected: Function to check if the graph is connected, i.e., there is a path between every pair of vertices.
Depth-First Search (DFS): Function to perform a depth-first search traversal of the graph.
Breadth-First Search (BFS): Function to perform a breadth-first search traversal of the graph.
*/

#include <stdio.h>
#include <stdlib.h>

// Maximum number of vertices
#define MAX_VERTICES 100

// Structure to represent an undirected graph
struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a new undirected graph with given number of vertices
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

// Function to add an edge between two vertices
void addEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices) {
        graph->adjacencyMatrix[source][destination] = 1;
        graph->adjacencyMatrix[destination][source] = 1; // Undirected graph
    } else {
        printf("Invalid vertex index.\n");
    }
}

// Function to remove an edge between two vertices
void removeEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices) {
        graph->adjacencyMatrix[source][destination] = 0;
        graph->adjacencyMatrix[destination][source] = 0; // Undirected graph
    } else {
        printf("Invalid vertex index.\n");
    }
}

// Function to check if there is an edge between two vertices
int hasEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices) {
        return graph->adjacencyMatrix[source][destination];
    } else {
        printf("Invalid vertex index.\n");
        return -1;
    }
}

// Function to print the adjacency matrix of the graph
void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create an undirected graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Print the adjacency matrix of the graph
    printGraph(graph);

    // Remove an edge
    removeEdge(graph, 1, 3);

    // Check if an edge exists
    printf("Edge between vertices 1 and 3: %s\n", hasEdge(graph, 1, 3) ? "Yes" : "No");

    // Print the adjacency matrix again
    printGraph(graph);

    // Free memory allocated for the graph
    free(graph);

    return 0;
}
