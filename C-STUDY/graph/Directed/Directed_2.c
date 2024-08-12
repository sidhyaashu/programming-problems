/*
inDegree() and outDegree() functions calculate the in-degree and out-degree of a given vertex, respectively.
transposeGraph() function transposes the directed graph.
isStronglyConnected() function checks if the graph has strongly connected components using Kosaraju's algorithm.
topologicalSort() function performs topological sorting of the graph.
BellmanFord() function implements the Bellman-Ford algorithm to find the shortest path from a source vertex to all other vertices.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

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

void addEdge(struct Graph* graph, int source, int destination, int weight) {
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices) {
        graph->adjacencyMatrix[source][destination] = weight;
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

int inDegree(struct Graph* graph, int vertex) {
    int degree = 0;
    if (vertex >= 0 && vertex < graph->numVertices) {
        for (int i = 0; i < graph->numVertices; ++i) {
            degree += graph->adjacencyMatrix[i][vertex];
        }
    } else {
        printf("Invalid vertex index.\n");
    }
    return degree;
}

int outDegree(struct Graph* graph, int vertex) {
    int degree = 0;
    if (vertex >= 0 && vertex < graph->numVertices) {
        for (int i = 0; i < graph->numVertices; ++i) {
            degree += graph->adjacencyMatrix[vertex][i];
        }
    } else {
        printf("Invalid vertex index.\n");
    }
    return degree;
}

void transposeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = i + 1; j < graph->numVertices; ++j) {
            int temp = graph->adjacencyMatrix[i][j];
            graph->adjacencyMatrix[i][j] = graph->adjacencyMatrix[j][i];
            graph->adjacencyMatrix[j][i] = temp;
        }
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

void DFSReverse(struct Graph* graph, int startVertex, int visited[]) {
    visited[startVertex] = 1;
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[i][startVertex] && !visited[i]) {
            DFSReverse(graph, i, visited);
        }
    }
}

void KosarajuDFS(struct Graph* graph, int startVertex, int visited[], int* count) {
    visited[startVertex] = 1;
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[startVertex][i] && !visited[i]) {
            KosarajuDFS(graph, i, visited, count);
        }
    }
    (*count)++;
}

int isStronglyConnected(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int count1 = 0, count2 = 0;

    // Check if all vertices are reachable from vertex 0
    DFSReverse(graph, 0, visited);
    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i]) {
            return 0; // Not strongly connected
        }
    }

    // Reset visited array
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    // Check if vertex 0 is reachable from all vertices
    KosarajuDFS(graph, 0, visited, &count1);
    for (int i = 1; i < graph->numVertices; ++i) {
        if (!visited[i]) {
            return 0; // Not strongly connected
        }
    }

    // Reset visited array
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    // Check if all vertices are reachable from all vertices
    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i]) {
            KosarajuDFS(graph, i, visited, &count2);
            if (count2 != count1) {
                return 0; // Not strongly connected
            }
            count2 = 0;
        }
    }

    return 1; // Strongly connected
}

void topologicalSortUtil(struct Graph* graph, int vertex, int visited[], int stack[], int* stackIndex) {
    visited[vertex] = 1;
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, stackIndex);
        }
    }
    stack[(*stackIndex)++] = vertex;
}

void topologicalSort(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int stackIndex = 0;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
        }
    }

    printf("Topological Sorting: ");
    while (stackIndex > 0) {
        printf("%d ", stack[--stackIndex]);
    }
    printf("\n");
}

void relax(int u, int v, int weight, int dist[], int parent[]) {
    if (dist[u] != INF && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        parent[v] = u;
    }
}

int BellmanFord(struct Graph* graph, int source) {
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; ++i) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < graph->numVertices - 1; ++i) {
        for (int u = 0; u < graph->numVertices; ++u) {
            for (int v = 0; v < graph->numVertices; ++v) {
                if (graph->adjacencyMatrix[u][v]) {
                    relax(u, v, graph->adjacencyMatrix[u][v], dist, parent);
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < graph->numVertices; ++u) {
        for (int v = 0; v < graph->numVertices; ++v) {
            if (graph->adjacencyMatrix[u][v] && dist[u] != INF && dist[u] + graph->adjacencyMatrix[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle\n");
                return 0; // Negative cycle exists
            }
        }
    }

    // Print shortest paths
    printf("Shortest paths from source vertex %d:\n", source);
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("Vertex %d -> Distance: %d, Parent: %d\n", i, dist[i], parent[i]);
    }
    return 1; // No negative cycle
}

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 4, 1);

    printGraph(graph);

    printf("In-degree of vertex 4: %d\n", inDegree(graph, 4));
    printf("Out-degree of vertex 2: %d\n", outDegree(graph, 2));

    transposeGraph(graph);
    printf("Transposed Graph:\n");
    printGraph(graph);

    printf("Is the graph strongly connected? %s\n", isStronglyConnected(graph) ? "Yes" : "No");

    topologicalSort(graph);

    BellmanFord(graph, 0);

    free(graph);

    return 0;
}
