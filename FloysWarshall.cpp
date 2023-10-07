#include <iostream>
#include <vector>
#include <climits> // Include this header for INT_MAX
using namespace std;

const int INF = INT_MAX; // Represents infinity

void floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();

    // Initialize the distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Initialize the diagonal elements to 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Fill the distance matrix with the given edge weights
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between all pairs of vertices:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 7, 0},
        {0, 2, 0, 0, 2},
        {4, 0, 0, 5, 0}
    };

    floydWarshall(graph);

    return 0;
}
