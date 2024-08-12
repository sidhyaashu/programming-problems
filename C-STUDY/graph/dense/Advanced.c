/*
primMST() function implements Prim's algorithm to find the Minimum Spanning Tree (MST) of the graph.
printMST() function prints the edges and weights of the Minimum Spanning Tree.
isComplete() function now checks if the graph is complete, meaning it has all possible edges.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999999

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

int minKey(int key[], bool mstSet[], int numVertices) {
    int min = INF, min_index;
    for (int v = 0; v < numVertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < numVertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(struct Graph* graph) {
    int parent[MAX_VERTICES]; // Array to store constructed MST
    int key[MAX_VERTICES];    // Key values used to pick minimum weight edge in cut
    bool mstSet[MAX_VERTICES]; // To represent set of vertices included in MST

    for (int i = 0; i < graph->numVertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int u = minKey(key, mstSet, graph->numVertices);
        mstSet[u] = true;
        for (int v = 0; v < graph->numVertices; v++)
            if (graph->adjacencyMatrix[u][v] && mstSet[v] == false && graph->adjacencyMatrix[u][v] < key[v])
                parent[v] = u, key[v] = graph->adjacencyMatrix[u][v];
    }
    printMST(parent, graph->adjacencyMatrix, graph->numVertices);
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

    // Finding minimum spanning tree (MST) using Prim's algorithm
    printf("Minimum Spanning Tree (MST) using Prim's algorithm:\n");
    primMST(graph);

    free(graph);

    return 0;
}
