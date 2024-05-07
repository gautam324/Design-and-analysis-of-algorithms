/*
After end term examination, Akshay wants to party with his friends. All his friends
are living as paying guest and it has been decided to first gather at Akshay’s house
and then move towards party location. The problem is that no one knows the exact
address of his house in the city. Akshay as a computer science wizard knows how to
apply his theory subjects in his real life and came up with an amazing idea to help
his friends. He draws a graph by looking in to location of his house and his friends’
location (as a node in the graph) on a map. He wishes to find out shortest distance
and path covering that distance from each of his friend’s location to his house and
then whatsapp them this path so that they can reach his house in minimum time.
Akshay has developed the program that implements Dijkstra’s algorithm but not
sure about correctness of results. Can you also implement the same algorithm and
verify the correctness of Akshay’s results? (Hint: Print shortest path and distance
from friends’ location to Akshay’s house)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX


struct Edge {
    int destination;
    int weight;
};


void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distances, vector<int>& prev) {
    int V = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distances.assign(V, INF);
    prev.assign(V, -1);

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distances[u])
            continue;

        for (const Edge& e : graph[u]) {
            int v = e.destination;
            int weight = e.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                prev[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
}

void printShortestPath(int start, const vector<int>& distances, const vector<int>& prev) {
    cout << "Shortest path and distance from Friend " << start << " to Akshay's house:\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Distance to node " << i << ": " << distances[i] << ", Path: ";
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

    vector<vector<Edge>> graph(V);
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w}); // for undirected graph
    }

   
    int akshay_house = 0;


    for (int i = 1; i < V; ++i) {
        vector<int> distances, prev;
        dijkstra(graph, i, distances, prev);
        printShortestPath(i, distances, prev);
    }

    return 0;
}
