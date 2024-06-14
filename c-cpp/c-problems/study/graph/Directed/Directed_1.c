#include <stdio.h>
#include <stdlib.h>

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

void removeEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices) {
        graph->adjacencyMatrix[source][destination] = 0;
    } else {
        printf("Invalid vertex index.\n");
    }
}

int hasEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices) {
        return graph->adjacencyMatrix[source][destination];
    } else {
        printf("Invalid vertex index.\n");
        return -1;
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

void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    printf("DFS Traversal: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS Traversal: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; ++i) {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printGraph(graph);

    DFS(graph, 0);

    BFS(graph, 0);

    free(graph);

    return 0;
}
