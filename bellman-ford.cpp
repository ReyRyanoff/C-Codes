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
void bellmanFord(vector<pair<int, int>> adj[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    for (int u = 0; u < V; u++) {
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                cout << "Graph contains a negative weight cycle" << endl;
                return;
            }
        }
    }
    printSolution(dist);
}

int main() {
    vector<pair<int, int>> adj[V];
    adj[0].push_back({1, -1});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 2});
    adj[1].push_back({4, 2});
    adj[3].push_back({2, 5});
    adj[3].push_back({1, 1});
    adj[4].push_back({3, -3});

    bellmanFord(adj, 0);
    return 0;
}
