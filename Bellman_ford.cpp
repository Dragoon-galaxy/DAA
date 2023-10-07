#include <iostream>
#include <vector>
#include <climits> // Include for INT_MAX

struct Edge {
    int source, destination, weight;
};

class Graph {
public:
    int V, E;
    std::vector<Edge> edges;

    Graph(int v, int e) {
        V = v;
        E = e;
        edges.resize(e);
    }

    void addEdge(int source, int destination, int weight) {
        edges.push_back({source, destination, weight});
    }

    void bellmanFord(int source) {
        std::vector<int> dist(V, INT_MAX);
        dist[source] = 0;

        for (int i = 1; i < V; ++i) {
            for (const Edge &edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int w = edge.weight;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative-weight cycles
        for (const Edge &edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                std::cout << "Graph contains negative-weight cycle\n";
                return;
            }
        }

        // Print shortest distances
        for (int i = 0; i < V; ++i) {
            std::cout << "Vertex " << i << " Distance from Source: " << dist[i] << "\n";
        }
    }
};

int main() {
    int V = 5;
    int E = 8;
    Graph graph(V, E);

    graph.addEdge(0, 1, -1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 2, 5);
    graph.addEdge(3, 1, 1);
    graph.addEdge(4, 3, -3);

    int sourceVertex = 0;
    graph.bellmanFord(sourceVertex);

    return 0;
}
