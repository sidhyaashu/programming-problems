/*
findBipartition() function finds one possible bipartition of the vertices and prints them.
Additional checks are made to ensure that the graph is bipartite before attempting to find the bipartition.
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    bool adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            graph->adjacencyMatrix[i][j] = false;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices) {
        graph->adjacencyMatrix[source][destination] = true;
        graph->adjacencyMatrix[destination][source] = true; // For undirected graph
    } else {
        printf("Invalid vertex index.\n");
    }
}

bool isBipartiteUtil(struct Graph* graph, int vertex, int color[]) {
    color[vertex] = 1; // Color the current vertex

    // Create a queue for BFS and enqueue the current vertex
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    queue[rear++] = vertex;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < graph->numVertices; ++v) {
            // An edge from u to v exists and v is not colored
            if (graph->adjacencyMatrix[u][v] && color[v] == -1) {
                color[v] = 1 - color[u]; // Assign opposite color to neighbor
                queue[rear++] = v;
            }
            // An edge from u to v exists and v is colored with the same color as u
            else if (graph->adjacencyMatrix[u][v] && color[v] == color[u]) {
                return false; // Not bipartite
            }
        }
    }
    return true; // Bipartite
}

bool isBipartite(struct Graph* graph) {
    int color[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; ++i) {
        color[i] = -1; // Initialize colors as unassigned
    }

    // Check for all connected components
    for (int i = 0; i < graph->numVertices; ++i) {
        if (color[i] == -1 && !isBipartiteUtil(graph, i, color)) {
            return false; // Not bipartite
        }
    }
    return true; // Bipartite
}

void findBipartition(struct Graph* graph) {
    int color[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; ++i) {
        color[i] = -1; // Initialize colors as unassigned
    }

    // Check for all connected components
    for (int i = 0; i < graph->numVertices; ++i) {
        if (color[i] == -1 && !isBipartiteUtil(graph, i, color)) {
            printf("Graph is not bipartite.\n");
            return;
        }
    }

    printf("Bipartition of the graph:\n");
    printf("Set 1: ");
    for (int i = 0; i < graph->numVertices; ++i) {
        if (color[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\nSet 2: ");
    for (int i = 0; i < graph->numVertices; ++i) {
        if (color[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(5);

    // Adding edges to create a bipartite graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Printing the graph
    printf("Graph structure:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            printf("%d ", graph->adjacencyMatrix[i][j] ? 1 : 0);
        }
        printf("\n");
    }

    // Checking if the graph is bipartite
    if (isBipartite(graph))
        printf("The graph is bipartite.\n");
    else
        printf("The graph is not bipartite.\n");

    // Finding one bipartition of the graph
    findBipartition(graph);

    free(graph);

    return 0;
}
