package Graph;

/*
Graph class: Represents the graph structure.
V: Number of vertices in the graph.
adjList: An array of linked lists to store the adjacency list representation of the graph.
addEdge(int src, int dest): Method to add an edge between two vertices.
DFS(int start): Method to perform depth-first search starting from a given vertex.
DFSUtil(int vertex, boolean[] visited): Recursive utility method for DFS.
display(): Method to display the adjacency list representation of the graph.
main(String[] args): Entry point of the program. It creates a graph, adds edges, displays the graph, and performs DFS traversal.
 */
import java.util.*;

public class Graph {
    private int V;
    private LinkedList<Integer>[] adjList;

    public Graph(int vertices) {
        V = vertices;
        adjList = new LinkedList[V];
        for (int i = 0; i < V; i++) {
            adjList[i] = new LinkedList<>();
        }
    }

    public void addEdge(int src, int dest) {
        adjList[src].add(dest);
        // For undirected graph, add this line:
        // adjList[dest].add(src);
    }

    public void DFS(int start) {
        boolean[] visited = new boolean[V];
        DFSUtil(start, visited);
    }

    private void DFSUtil(int vertex, boolean[] visited) {
        visited[vertex] = true;
        System.out.print(vertex + " ");

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    public void display() {
        for (int i = 0; i < V; i++) {
            System.out.print("Vertex " + i + " is connected to: ");
            for (int v : adjList[i]) {
                System.out.print(v + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph(5);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 4);

        System.out.println("Graph:");
        graph.display();

        System.out.println("\nDFS traversal starting from vertex 0:");
        graph.DFS(0);
    }
}
