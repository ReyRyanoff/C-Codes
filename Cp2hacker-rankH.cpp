#include <bits/stdc++.h>
using namespace std;

int cnt;
void dfs(int node, vector<vector<int>>& adj_list, vector<int>& visited) {
    visited[node] = 1;
    cnt++;
    for (int it : adj_list[node]) {
        if (!visited[it]) {
            dfs(it, adj_list, visited);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;

        vector<vector<int>> adj_list(n + 1);
        vector<int> visited(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
        }

        cnt = 0;
        while (l--) {
            int start;
            cin >> start;
            if (!visited[start]) {
                dfs(start, adj_list, visited);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
