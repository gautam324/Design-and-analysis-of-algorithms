/*I. Assume that a project of road construction to connect some cities is given to your
friend. Map of these cities and roads which will connect them (after construction) is
provided to him in the form of a graph. Certain amount of rupees is associated with
construction of each road. Your friend has to calculate the minimum budget
required for this project. The budget should be designed in such a way that the cost
of connecting the cities should be minimum and number of roads required to
connect all the cities should be minimum (if there are N cities then only N-1 roads
need to be constructed). He asks you for help. Now, you have to help your friend by
designing an algorithm which will find minimum cost required to connect these
cities. (use Prim's algorithm)*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX


struct Edge {
    int source;
    int destination;
    int weight;
};


int primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<bool> inMST(V, false);
    vector<int> key(V, INF);
    int minCost = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

   
    pq.push({0, 0}); 
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        
        if (inMST[u])
            continue;

        inMST[u] = true;

        
        minCost += key[u];

      
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != INF && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
            }
        }
    }

    return minCost;
}

int main() {
    int V;
    cout << "Enter the number of cities: ";
    cin >> V;

    
    vector<vector<int>> graph(V, vector<int>(V, INF));

    cout << "Enter the adjacency matrix representing the cost of connecting cities (INF for no connection):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    int minCost = primMST(graph);

    cout << "Minimum cost required to connect all cities: " << minCost << endl;

    return 0;
}
