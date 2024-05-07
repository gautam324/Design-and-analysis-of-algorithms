#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>>& graph, int src, int dest, vector<bool>& visited) {
    visited[src] = true;
    if (src == dest)
        return true;
    for (int i = 0; i < graph[src].size(); ++i) {
        int adjVertex = graph[src][i];
        if (!visited[adjVertex]) {
            if (DFS(graph, adjVertex, dest, visited))
                return true;
        }
    }
    return false;
}

bool isPathExist(vector<vector<int>>& graph, int src, int dest, int V) {
    vector<bool> visited(V, false);
    return DFS(graph, src, dest, visited);
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int src, dest;
    cin >> src >> dest;
    if (isPathExist(graph, src, dest, V))
        cout << "Yes, Path Exists" << endl;
    else
        cout << "No Such Path Exists" << endl;
    return 0;
}
