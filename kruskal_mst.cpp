#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V, E;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int vertices, int edgesCount) {
        V = vertices;
        E = edgesCount;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST() {
        int minCost = 0;
        vector<int> parent(V);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        sort(edges.begin(), edges.end());

        for (int i = 0; i < E; i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int w = edges[i].first;

            int setU = find(parent, u);
            int setV = find(parent, v);

            if (setU != setV) {
                cout << u << " - " << v << " : " << w << endl;
                minCost += w;
                unionSets(parent, setU, setV);
            }
        }

        return minCost;
    }

    int find(vector<int>& parent, int node) {
        if (parent[node] != node) {
            parent[node] = find(parent, parent[node]);
        }
        return parent[node];
    }

    void unionSets(vector<int>& parent, int u, int v) {
        int rootU = find(parent, u);
        int rootV = find(parent, v);
        parent[rootU] = rootV;
    }
};

int main() {
    int V = 9; // Number of vertices
    int E = 14; // Number of edges
    Graph graph(V, E);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(1, 2, 8);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 8, 6);
    graph.addEdge(6, 7, 1);
    graph.addEdge(7, 8, 7);
    
    cout << "Edges in the minimum spanning tree:" << endl;
    int minCost = graph.kruskalMST();
    cout << "Minimum Cost: " << minCost << endl;

    return 0;
}
