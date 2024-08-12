#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

    void printAllPathsUtil(int src, int dest, vector<bool>& visited, stack<int>& path) {
        visited[src] = true;
        path.push(src);
        if (src == dest) {
            stack<int> temp = path;
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        } else {
            for (int i : adj[src]) {
                if (!visited[i])
                    printAllPathsUtil(i, dest, visited, path);
            }
        }
        path.pop();
        visited[src] = false;
    }

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void printAllPaths(int src, int dest) {
        vector<bool> visited(V, false);
        stack<int> path;
        printAllPathsUtil(src, dest, visited, path);
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int src = 2, dest = 3;
    cout << "Paths from " << src << " to " << dest << " are:" << endl;
    g.printAllPaths(src, dest);
    return 0;
}
