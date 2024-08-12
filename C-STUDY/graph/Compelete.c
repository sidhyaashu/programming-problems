/*
createCompleteGraph() function to create a complete graph with the specified number of vertices.
printGraph() function to print the adjacency matrix of the graph.
isCompleteGraph() function to check if the graph is complete or not.
Additional functionalities such as graph traversal algorithms (DFS, BFS), finding cycles, or calculating shortest paths are not applicable to complete graphs because they are already fully connected. However, you can still implement various graph algorithms on complete graphs for educational purposes.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createCompleteGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (i != j)
                graph->adjacencyMatrix[i][j] = 1;
            else
                graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void isCompleteGraph(struct Graph* graph) {
    int totalEdges = (graph->numVertices * (graph->numVertices - 1)) / 2;
    int presentEdges = 0;

    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = i + 1; j < graph->numVertices; ++j) {
            if (graph->adjacencyMatrix[i][j] == 1)
                presentEdges++;
        }
    }

    if (presentEdges == totalEdges)
        printf("The graph is a complete graph.\n");
    else
        printf("The graph is not a complete graph.\n");
}

int main() {
    struct Graph* completeGraph = createCompleteGraph(5);

    // Printing the complete graph
    printGraph(completeGraph);

    // Checking if it's a complete graph
    isCompleteGraph(completeGraph);

    free(completeGraph);

    return 0;
}
