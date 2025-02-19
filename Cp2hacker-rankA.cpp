#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& arr, vector<int> adj_list[], vector<int>& vis, int& sum, int& cnt) {
    vis[node] = 1;
    sum += arr[node];
    cnt++;
    for (auto neighbor : adj_list[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, arr, adj_list, vis, sum, cnt);
        }
    }
}

int main() {
    int t, k = 1;
    cin >> t;
    while (k <= t) {
        int n, m;
        cin >> n >> m;

        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        vector<int> adj_list[n + 1];
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        vector<int> vis(n + 1, 0);
        bool possible = true;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int sum = 0, cnt = 0;
                dfs(i, arr, adj_list, vis, sum, cnt);
                if (sum % cnt != 0) {
                    possible = false;
                    break;
                }
            }
        }

        cout << "Case " << k << ": " << (possible ? "Yes" : "No") << endl;
        k++;
    }
    return 0;
}
