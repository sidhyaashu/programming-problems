/*
DFSUtil() and DFS() functions are used to find connected components of the graph.
isConnected() function checks if the graph is connected and prints its connected components.
isTree() function determines whether the graph is a tree or not.
primMST() function finds and prints the minimum spanning tree of the graph using Prim's algorithm.
*/



#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 9999

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
        graph->adjacencyMatrix[destination][source] = weight; // Undirected graph
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
    printf("Connected Component: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

void isConnected(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int components = 0;
    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i]) {
            components++;
            printf("Component %d: ", components);
            DFSUtil(graph, i, visited);
            printf("\n");
        }
    }
    if (components == 1) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }
}

int isTree(struct Graph* graph) {
    // Check for connectivity
    isConnected(graph);

    // Check for cycle
    int visited[MAX_VERTICES] = {0};
    if (hasCycle(graph, 0, -1, visited)) {
        printf("The graph contains a cycle. It is not a tree.\n");
        return 0;
    }

    // Check for the number of edges
    int edges = 0;
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = i + 1; j < graph->numVertices; ++j) {
            if (graph->adjacencyMatrix[i][j] != 0)
                edges++;
        }
    }
    if (edges != graph->numVertices - 1) {
        printf("The graph does not have exactly one fewer edge than vertices. It is not a tree.\n");
        return 0;
    }

    printf("The graph is a tree.\n");
    return 1;
}

int hasCycle(struct Graph* graph, int vertex, int parent, int visited[]) {
    visited[vertex] = 1;
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i]) {
            if (!visited[i]) {
                if (hasCycle(graph, i, vertex, visited))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

void primMST(struct Graph* graph) {
    int parent[MAX_VERTICES]; // Array to store the constructed MST
    int key[MAX_VERTICES];    // Key values used to pick minimum weight edge in cut
    int mstSet[MAX_VERTICES]; // Array to represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as 0
    for (int i = 0; i < graph->numVertices; ++i) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    // Always include first  vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < graph->numVertices - 1; ++count) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(graph, key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < graph->numVertices; ++v) {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph->adjacencyMatrix[u][v] && !mstSet[v] && graph->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    // Print the constructed MST
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < graph->numVertices; ++i) {
        printf("%d - %d   weight: %d\n", parent[i], i, graph->adjacencyMatrix[i][parent[i]]);
    }
}

int minKey(struct Graph* graph, int key[], int mstSet[]) {
    int min = INF, min_index;

    for (int v = 0; v < graph->numVertices; ++v) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 4, 1);

    printGraph(graph);

    isConnected(graph);

    isTree(graph);

    primMST(graph);

    free(graph);

    return 0;
}
