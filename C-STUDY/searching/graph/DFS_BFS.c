#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a graph node
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_NODES];
    int visited[MAX_NODES];
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = n;
    for (int i = 0; i < n; ++i) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth-First Search
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->data;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Breadth-First Search
void BFS(struct Graph* graph, int startVertex) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = startVertex;
    graph->visited[startVertex] = 1;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("Visited %d \n", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (graph->visited[adjVertex] == 0) {
                queue[rear++] = adjVertex;
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("Depth-First Search:\n");
    DFS(graph, 0);

    // Reset visited array for BFS
    for (int i = 0; i < graph->numVertices; ++i) {
        graph->visited[i] = 0;
    }

    printf("\nBreadth-First Search:\n");
    BFS(graph, 0);

    return 0;
}
