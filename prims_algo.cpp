#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> graph;

    Graph(int vertices) {
        V = vertices;
        graph.assign(V, vector<int>(V, 0));
    }

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight; // For an undirected graph
    }

    int prim_mst() {
        vector<int> parent(V, -1); // Stores the MST
        vector<int> key(V, INT_MAX); // Key values to pick minimum weight edge
        vector<bool> mst_set(V, false); // Set to keep track of vertices included in MST

        key[0] = 0; // Start with the first vertex
        int min_cost = 0;

        for (int count = 0; count < V; count++) {
            // Find the vertex with the minimum key value
            int u = min_key(key, mst_set);
            mst_set[u] = true;

            // Print the MST edge in the requested format
            if (parent[u] != -1) {
                cout << parent[u] << " - " << u << " : " << graph[u][parent[u]] << endl;
                min_cost += graph[u][parent[u]];
            }

            // Update key values and parent for adjacent vertices
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !mst_set[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        return min_cost;
    }

    int min_key(vector<int>& key, vector<bool>& mst_set) {
        int min_value = INT_MAX;
        int min_index = -1;

        for (int v = 0; v < V; v++) {
            if (!mst_set[v] && key[v] < min_value) {
                min_value = key[v];
                min_index = v;
            }
        }

        return min_index;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.add_edge(0, 1, 2);
    g.add_edge(0, 3, 6);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 3, 8);
    g.add_edge(1, 4, 5);
    g.add_edge(2, 4, 7);
    g.add_edge(3, 4, 9);

    cout << "Edges in the minimum spanning tree:" << endl;
    int min_cost = g.prim_mst();
    cout << "Minimum Cost: " << min_cost << endl;

    return 0;
}
