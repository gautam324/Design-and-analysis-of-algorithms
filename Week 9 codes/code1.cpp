/* Given a graph, Design an algorithm and implement it using a program to
implement Floyd- Warshall all pair shortest path algorithm.
Input Format:
The first line of input takes number of vertices in the graph.
Input will be the graph in the form of adjacency matrix or adjacency list. If a direct edge
is not present between any pair of vertex (u,v), then this entry is shown as AdjM[u,v] =
INF.
Output Format:
Output will be shortest distance matrix in the form of V X V matrix, where each entry
(u,v) represents shortest distance between vertex u and vertex v.*/

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floydWarshall(int vertices, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < vertices; ++k) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices;
    cin >> vertices;

    vector<vector<int>> graph(vertices, vector<int>(vertices));

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == -1)
                graph[i][j] = INF;
        }
    }

    floydWarshall(vertices, graph);

    return 0;
}

