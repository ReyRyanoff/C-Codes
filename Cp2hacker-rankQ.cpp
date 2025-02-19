#include<bits/stdc++.h>
using namespace std;
int cnt, finish;

void dfs(int node, vector<vector<pair<int, int>>> adj_list, vector<int>& visited){
    visited[node] = 1;
    if(node == finish) return;
    for(auto it : adj_list[node]){
        int next = it.first;
        int distance = it.second;
        if(!visited[next]){
            cnt += distance;
            dfs(next, adj_list, visited);
        }
    }
}

int main()
{
    int t, k = 1;
    cin >> t;
    while(k <= t)
    {
        cnt = 0;
        int n, m;
        cin >> n >> m;
        finish = n;
        vector<vector<pair<int, int>>> adj_list(n+1);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj_list[u].push_back({v, w});
        }

        vector<int> visited(n+1, 0);
        dfs(1, adj_list, visited);
        if(visited[finish]) cout << "Case " << k << ": " << cnt << endl;
        else cout << "Case " << k << ": Impossible" << endl;
        k++;
    }
    return 0;
}
