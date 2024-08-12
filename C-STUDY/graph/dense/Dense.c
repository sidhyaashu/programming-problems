#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            printf("%d ", graph->adjacencyMatrix[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

int countEdges(struct Graph* graph) {
    int numEdges = 0;
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = i + 1; j < graph->numVertices; ++j) {
            if (graph->adjacencyMatrix[i][j])
                numEdges++;
        }
    }
    return numEdges;
}

bool isComplete(struct Graph* graph) {
    int totalEdges = (graph->numVertices * (graph->numVertices - 1)) / 2;
    return countEdges(graph) == totalEdges;
}

int main() {
    struct Graph* graph = createGraph(5);

    // Adding edges to create a dense graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    // Printing the graph
    printGraph(graph);

    // Counting edges
    printf("Number of edges in the graph: %d\n", countEdges(graph));

    // Checking if the graph is complete
    if (isComplete(graph))
        printf("The graph is complete.\n");
    else
        printf("The graph is not complete.\n");

    free(graph);

    return 0;
}
