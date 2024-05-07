#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph, int V) {
    vector<int> color(V, -1);
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (color[v] == color[u])
                        return false;
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    if (isBipartite(graph, V))
        cout << "Yes, Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;
    return 0;
}
