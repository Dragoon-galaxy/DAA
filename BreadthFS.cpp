#include <iostream>
#include <list>
#include <queue>

class Graph {
private:
    int V; // Number of vertices
    std::list<int> *adj; // Adjacency list

public:
    Graph(int v) : V(v) {
        adj = new std::list<int>[V];
    }

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // For an undirected graph
    }

    void BFS(int start) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        std::queue<int> queue;
        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int vertex = queue.front();
            std::cout << vertex << " ";
            queue.pop();

            for (auto it = adj[vertex].begin(); it != adj[vertex].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    queue.push(*it);
                }
            }
        }

        delete[] visited;
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    std::cout << "Breadth-First Traversal (starting from vertex 0): ";
    g.BFS(0);

    return 0;
}
