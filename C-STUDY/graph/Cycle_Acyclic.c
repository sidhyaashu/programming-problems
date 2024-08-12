#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices) {
        graph->adjacencyMatrix[source][destination] = 1;
    } else {
        printf("Invalid vertex index.\n");
    }
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

bool hasCycleUtil(struct Graph* graph, int vertex, bool visited[], bool recStack[]) {
    if (!visited[vertex]) {
        visited[vertex] = true;
        recStack[vertex] = true;

        for (int i = 0; i < graph->numVertices; ++i) {
            if (graph->adjacencyMatrix[vertex][i]) {
                if (!visited[i] && hasCycleUtil(graph, i, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    recStack[vertex] = false;
    return false;
}

bool hasCycle(struct Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    bool recStack[MAX_VERTICES] = {false};

    for (int i = 0; i < graph->numVertices; ++i) {
        if (hasCycleUtil(graph, i, visited, recStack))
            return true;
    }

    return false;
}

bool isAcyclic(struct Graph* graph) {
    return !hasCycle(graph);
}

int main() {
    struct Graph* graph = createGraph(5);

    // Adding edges to create a cyclic graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0); // Creating a cycle

    // Printing the graph
    printGraph(graph);

    // Checking if the graph is cyclic
    if (hasCycle(graph))
        printf("The graph contains at least one cycle.\n");
    else
        printf("The graph is acyclic.\n");

    // Checking if the graph is acyclic
    if (isAcyclic(graph))
        printf("The graph is acyclic.\n");
    else
        printf("The graph contains at least one cycle.\n");

    free(graph);

    return 0;
}
