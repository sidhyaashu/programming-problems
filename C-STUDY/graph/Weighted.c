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
        graph->adjacencyMatrix[destination][source] = weight; // For undirected graph
    } else {
        printf("Invalid vertex index.\n");
    }
}

void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            if (graph->adjacencyMatrix[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i] != 0 && !visited[i]) {
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
            if (graph->adjacencyMatrix[currentVertex][i] != 0 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void dijkstra(struct Graph* graph, int source) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; ++i) {
        dist[i] = INF;
    }

    dist[source] = 0;

    for (int count = 0; count < graph->numVertices - 1; ++count) {
        int minDist = INF, minIndex;
        for (int v = 0; v < graph->numVertices; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        for (int v = 0; v < graph->numVertices; ++v) {
            if (!visited[v] && graph->adjacencyMatrix[minIndex][v] &&
                dist[minIndex] != INF && dist[minIndex] + graph->adjacencyMatrix[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph->adjacencyMatrix[minIndex][v];
            }
        }
    }

    printf("Shortest distances from source vertex %d:\n", source);
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("Vertex %d -> Distance: %d\n", i, dist[i]);
    }
}

void primMST(struct Graph* graph) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < graph->numVertices; ++i) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->numVertices - 1; ++count) {
        int u, minKey = INF;
        for (int v = 0; v < graph->numVertices; ++v) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = 1;

        for (int v = 0; v < graph->numVertices; ++v) {
            if (graph->adjacencyMatrix[u][v] && !mstSet[v] && graph->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    printf("Minimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < graph->numVertices; ++i) {
        printf("%d - %d   weight: %d\n", parent[i], i, graph->adjacencyMatrix[i][parent[i]]);
    }
}

void bellmanFord(struct Graph* graph, int source) {
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];

    for (int i = 0; i < graph->numVertices; ++i) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < graph->numVertices - 1; ++count) {
        for (int u = 0; u < graph->numVertices; ++u) {
            for (int v = 0; v < graph->numVertices; ++v) {
                if (graph->adjacencyMatrix[u][v] && dist[u] != INF && dist[u] + graph->adjacencyMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph->adjacencyMatrix[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < graph->numVertices; ++u) {
        for (int v = 0; v < graph->numVertices; ++v) {
            if (graph->adjacencyMatrix[u][v] && dist[u] != INF && dist[u] + graph->adjacencyMatrix[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    printf("Shortest paths from source vertex %d:\n", source);
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("Vertex %d -> Distance: %d, Parent: %d\n", i, dist[i], parent[i]);
    }
}

void floydWarshall(struct Graph* graph) {
    int dist[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            dist[i][j] = graph->adjacencyMatrix[i][j];
        }
    }

    for (int k = 0; k < graph->numVertices; ++k) {
        for (int i = 0; i < graph->numVertices; ++i) {
            for (int j = 0; j < graph->numVertices; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("All-pairs shortest paths (Floyd-Warshall Algorithm):\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph(5);

    // Adding weighted edges
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 20);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 1, 3, 30);
    addEdge(graph, 2, 3, 15);
    addEdge(graph, 2, 4, 25);
    addEdge(graph, 3, 4, 6);

    // Printing the graph
    printGraph(graph);

    // Performing DFS and BFS
    DFS(graph, 0);
    BFS(graph, 0);

    // Finding single source shortest paths using Dijkstra's algorithm
    dijkstra(graph, 0);

    // Finding minimum spanning tree using Prim's algorithm
    primMST(graph);

    // Finding shortest paths from a source vertex using Bellman-Ford algorithm
    bellmanFord(graph, 0);

    // Finding all-pairs shortest paths using Floyd-Warshall algorithm
    floydWarshall(graph);

    free(graph);

    return 0;
}
