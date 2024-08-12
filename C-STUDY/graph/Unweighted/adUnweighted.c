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
        graph->adjacencyMatrix[destination][source] = 1; // For undirected graph
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

void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    printf("DFS Traversal: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

void BFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS Traversal: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; ++i) {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

bool hasCycleUtil(struct Graph* graph, int vertex, bool visited[], int parent) {
    visited[vertex] = true;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i]) {
            if (!visited[i]) {
                if (hasCycleUtil(graph, i, visited, vertex))
                    return true;
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(struct Graph* graph) {
    bool visited[MAX_VERTICES] = {false};

    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i] && hasCycleUtil(graph, i, visited, -1))
            return true;
    }
    return false;
}

void connectedComponentsUtil(struct Graph* graph, int vertex, bool visited[], int component[], int componentNumber) {
    visited[vertex] = true;
    component[vertex] = componentNumber;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
            connectedComponentsUtil(graph, i, visited, component, componentNumber);
        }
    }
}

int connectedComponents(struct Graph* graph, int components[]) {
    bool visited[MAX_VERTICES] = {false};
    int componentNumber = 0;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i]) {
            connectedComponentsUtil(graph, i, visited, components, componentNumber);
            componentNumber++;
        }
    }
    return componentNumber;
}

int main() {
    struct Graph* graph = createGraph(8);

    // Adding unweighted edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);

    // Printing the graph
    printGraph(graph);

    // Performing DFS and BFS
    DFS(graph, 0);
    BFS(graph, 0);

    // Checking for cycles
    if (hasCycle(graph))
        printf("Graph contains cycle.\n");
    else
        printf("Graph does not contain cycle.\n");

    // Finding connected components
    int components[MAX_VERTICES];
    int numComponents = connectedComponents(graph, components);
    printf("Number of connected components: %d\n", numComponents);
    printf("Vertices and their respective components:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("%d -> Component %d\n", i, components[i]);
    }

    free(graph);

    return 0;
}
