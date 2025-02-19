#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define V 5
void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << "   " << i << "\t\t";
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
void dijkstra(vector<pair<int, int>> adj[], int src) {
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int minDist = INF, u;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && dist[v] <= minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        sptSet[u] = true;
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!sptSet[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    printSolution(dist);
}

int main() {
    vector<pair<int, int>> adj[V];
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 5});
    adj[2].push_back({3, 1});
    adj[3].push_back({4, 3});
    adj[4].push_back({0, 7});

    dijkstra(adj, 0);
    return 0;
}
