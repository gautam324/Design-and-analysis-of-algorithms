/*II. Implement the previous problem using Kruskal's algorithm.
Input Format:
The first line of input takes number of vertices in the graph.
Input will be the graph in the form of adjacency matrix or adjacency list.
Output Format:
Output will be minimum spanning weight*/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int source;
    int destination;
    int weight;

  
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};


struct UnionFind {
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv)
            parent[pv] = pu;
    }
};


int kruskalMST(vector<Edge>& edges, int V) {

    sort(edges.begin(), edges.end());
    int minSpanningWeight = 0;

    UnionFind uf(V);
  
    for (const Edge& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

      
        if (uf.find(u) != uf.find(v)) {
            minSpanningWeight += weight;
            uf.merge(u, v);
        }
    }

    return minSpanningWeight;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;


    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix representing the cost of connecting vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }


    vector<Edge> edges;
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    int minSpanningWeight = kruskalMST(edges, V);

    cout << "Minimum spanning weight: " << minSpanningWeight << endl;

    return 0;
}
