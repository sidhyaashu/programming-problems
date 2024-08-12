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

bool isConnected(struct Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[0] = true;
    queue[rear++] = 0;

    while (front < rear) {
        int currentVertex = queue[front++];
        for (int i = 0; i < graph->numVertices; ++i) {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i])
            return false;
    }
    return true;
}

void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

int countConnectedComponents(struct Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    int count = 0;
    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i]) {
            DFSUtil(graph, i, visited);
            ++count;
        }
    }
    return count;
}

bool isStronglyConnected(struct Graph* graph) {
    // Directed graph is strongly connected if every pair of vertices has a path in both directions
    for (int i = 0; i < graph->numVertices; ++i) {
        bool visited[MAX_VERTICES] = {false};
        DFSUtil(graph, i, visited);
        for (int j = 0; j < graph->numVertices; ++j) {
            if (!visited[j])
                return false;
        }
    }
    return true;
}

int main() {
    struct Graph* graph = createGraph(5);

    // Adding edges to create a connected graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Printing the graph
    printGraph(graph);

    // Checking if the graph is connected
    if (isConnected(graph))
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");

    // Counting connected components
    printf("Number of connected components: %d\n", countConnectedComponents(graph));

    // Checking if the graph is strongly connected (applicable only for directed graphs)
    if (isStronglyConnected(graph))
        printf("The graph is strongly connected.\n");
    else
        printf("The graph is not strongly connected.\n");

    free(graph);

    return 0;
}
