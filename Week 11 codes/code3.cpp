#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool comp(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}

int findMaximumSpanningWeight(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), comp);

    vector<Subset> subsets(V);
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int maxSpanningWeight = 0;

    for (const Edge& edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        if (x != y) {
            maxSpanningWeight += edge.weight;
            Union(subsets, x, y);
        }
    }

    return maxSpanningWeight;
}

int main() {
    int V;
    cin >> V;

    vector<Edge> edges;
    int u, v, w;
    while (cin >> u >> v >> w) {
        edges.push_back({u, v, w});
    }

    int maxSpanningWeight = findMaximumSpanningWeight(edges, V);
    cout << maxSpanningWeight << endl;

    return 0;
}

