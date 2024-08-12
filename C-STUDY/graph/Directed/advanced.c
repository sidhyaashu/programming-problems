/*
hasCycleUtil() and hasCycle() functions are used to detect cycles in the graph.
tarjanDFS() and findSCCs() functions implement Tarjan's algorithm to find all strongly connected components (SCCs) of the graph.
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

int hasCycleUtil(struct Graph* graph, int vertex, int visited[], int stack[]) {
    if (visited[vertex] == 1) {
        return 1; // Cycle detected
    }
    if (visited[vertex] == 2) {
        return 0; // Already processed
    }

    visited[vertex] = 1; // Mark as visited
    stack[vertex] = 1;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[vertex][i] && hasCycleUtil(graph, i, visited, stack)) {
            return 1; // Cycle detected
        }
    }

    visited[vertex] = 2; // Mark as processed
    return 0;
}

int hasCycle(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; ++i) {
        if (hasCycleUtil(graph, i, visited, stack)) {
            return 1; // Cycle detected
        }
    }

    return 0; // No cycle
}

void tarjanDFS(struct Graph* graph, int u, int* index, int disc[], int low[], int stackMember[], int stack[], int* count) {
    disc[u] = low[u] = ++(*index);
    stack[*count] = u;
    stackMember[u] = 1;

    for (int v = 0; v < graph->numVertices; ++v) {
        if (graph->adjacencyMatrix[u][v]) {
            if (disc[v] == -1) {
                tarjanDFS(graph, v, index, disc, low, stackMember, stack, count);
                low[u] = (low[u] < low[v]) ? low[u] : low[v];
            } else if (stackMember[v]) {
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }

    // If u is a root node, pop the stack and print SCC
    if (low[u] == disc[u]) {
        while (stack[*count] != u) {
            printf("%d ", stack[*count]);
            stackMember[stack[*count]] = 0;
            (*count)--;
        }
        printf("%d\n", stack[*count]);
        stackMember[stack[*count]] = 0;
        (*count)--;
    }
}

void findSCCs(struct Graph* graph) {
    int disc[MAX_VERTICES], low[MAX_VERTICES], stackMember[MAX_VERTICES], stack[MAX_VERTICES];
    int index = 0;
    int count = -1;

    for (int i = 0; i < graph->numVertices; ++i) {
        disc[i] = low[i] = -1;
        stackMember[i] = 0;
    }

    for (int i = 0; i < graph->numVertices; ++i) {
        if (disc[i] == -1) {
            tarjanDFS(graph, i, &index, disc, low, stackMember, stack, &count);
        }
    }
}

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 4, 0, 1);

    printGraph(graph);

    printf("Does the graph have a cycle? %s\n", hasCycle(graph) ? "Yes" : "No");

    printf("Strongly Connected Components:\n");
    findSCCs(graph);

    free(graph);

    return 0;
}
