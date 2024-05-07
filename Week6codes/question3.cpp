#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>>& graph, int u, vector<bool>& visited, vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;
    for (int v : graph[u]) {
        if (!visited[v] && DFS(graph, v, visited, recStack))
            return true;
        else if (recStack[v])
            return true;
    }
    recStack[u] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && DFS(graph, i, visited, recStack))
            return true;
    }
    return false;
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
    if (isCyclic(graph, V))
        cout << "Yes Cycle Exists" << endl;
    else
        cout << "No Cycle Exists" << endl;
    return 0;
}

