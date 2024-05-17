#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Compare {
    bool operator()(const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    }
};

int find(vector<int> &parent, int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(vector<int> &parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int maxSpanningWeight(int vertices, vector<Edge> &edges) {
    priority_queue<Edge, vector<Edge>, Compare> pq(edges.begin(), edges.end());
    int maxWeight = 0;
    vector<int> parent(vertices, -1);

    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();

        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);

        if (x != y) {
            maxWeight += edge.weight;
            unionSet(parent, x, y);
        }
    }

    return maxWeight;
}

int main() {
    int vertices;
    cin >> vertices;

    vector<Edge> edges;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                Edge edge = {i, j, weight};
                edges.push_back(edge);
            }
        }
    }

    int maxWeight = maxSpanningWeight(vertices, edges);
    cout << maxWeight << endl;

    return 0;
}
