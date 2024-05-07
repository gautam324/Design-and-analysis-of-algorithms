/*Design an algorithm and implement it using a program to solve previous question's
problem using Bellman- Ford's shortest path algorithm.
Input Format:
Input will be the graph in the form of adjacency matrix or
adjacency list. Source vertex number is also provided as an
input.
Output Format:
Output will contain V lines.
Each line will represent the whole path from destination vertex number to source
vertex number along with minimum path weigth.*/


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX


struct Edge {
    int source;
    int destination;
    int weight;
};


void bellmanFord(vector<Edge>& edges, int V, int source) {
    vector<int> distances(V, INF);
    vector<int> prev(V, -1);

    distances[source] = 0;

  
    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                prev[v] = u;
            }
        }
    }


    for (const Edge& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if (distances[u] != INF && distances[u] + weight < distances[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    
    cout << "Shortest paths from source vertex " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Distance to vertex " << i << ": " << distances[i] << ", Path: ";
        vector<int> path;
        for (int v = i; v != -1; v = prev[v])
            path.push_back(v);
        for (int j = path.size() - 1; j >= 0; --j)
            cout << path[j] << " ";
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i)
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(edges, V, source);

    return 0;
}
