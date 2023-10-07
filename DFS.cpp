#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define a graph using an adjacency list
class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) : V(V), adj(V) {}

    // Add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Depth-First Search function using recursion
    void dfsRecursive(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

    // Depth-First Search function using an explicit stack (iterative)
    void dfsIterative(int start) {
        vector<bool> visited(V, false);
        stack<int> stack;

        stack.push(start);

        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (!visited[v]) {
                visited[v] = true;
                cout << v << " ";

                for (int neighbor : adj[v]) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }

    // Wrapper function for DFS starting from a specific vertex
    void dfs(int start) {
        vector<bool> visited(V, false);
        // dfsRecursive(start, visited); // Uncomment this line for recursive DFS
        dfsIterative(start); // Uncomment this line for iterative DFS
    }
};

int main() {
    Graph g(7); // Create a graph with 7 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "Depth-First Search starting from vertex 0: ";
    g.dfs(0);

    return 0;
}
