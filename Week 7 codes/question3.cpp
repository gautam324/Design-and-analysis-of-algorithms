/*. Given a directed graph with two vertices ( source and destination). Design an
algorithm and implement it using a program to find the weight of the shortest path
from source to destination with exactly k edges on the path.
Input Format:
First input line will obtain number of vertices V present in the graph.
Graph in the form of adjacency matrix or adjacency list is taken as an input in next V
lines*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

int shortestPathWithKEdges(vector<vector<int>>& graph, int source, int destination, int K) {
    int V = graph.size();
    vector<vector<vector<int>>> dp(V, vector<vector<int>>(V, vector<int>(K + 1, INF)));

    for (int v = 0; v < V; ++v)
        dp[v][0][0] = (v == source) ? 0 : INF;

]
    for (int k = 1; k <= K; ++k) {
        for (int e = 1; e < V; ++e) {
            for (int u = 0; u < V; ++u) {
                for (int v = 0; v < V; ++v) {
                    if (graph[u][v] != INF) {
                        dp[v][e][k] = min(dp[v][e][k], dp[u][e - 1][k - 1] + graph[u][v]);
                    }
                }
            }
        }
    }

    return dp[destination][K][K];
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

 
    vector<vector<int>> graph(V, vector<int>(V, INF));

    cout << "Enter the adjacency matrix (INF for no edge):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    int source, destination, K;
    cout << "Enter the source vertex, destination vertex, and K: ";
    cin >> source >> destination >> K;

    int shortestWeight = shortestPathWithKEdges(graph, source, destination, K);

    if (shortestWeight == INF)
        cout << "No path with exactly " << K << " edges exists from source to destination.\n";
    else
        cout << "Weight of the shortest path from source to destination with exactly " << K << " edges: " << shortestWeight << endl;

    return 0;
}
