#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& adj_list){
    color[node] = col;
    bool f;
    for(auto it : adj_list[node]){
        if(color[it] == -1){
            if (!dfs(it, 1 - col, color, adj_list)) {
                return false;
            }
        }
        else if(color[it] == color[node]) return false;
    }
    return true;
}

int main()
{
    while(1)
    {
        int n, e;
        cin >> n;
        if(n == 0) break;
        cin >> e;
        vector<vector<int>> adj_list(n);
        for(int i = 0; i < e; i++){
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        vector<int> color(n, -1);
        bool bipartite = true;
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if (!dfs(i, 0, color, adj_list)) {
                    bipartite = false;
                    break;
                }
            }
        }
        if(bipartite) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
