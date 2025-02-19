#include<bits/stdc++.h>
using namespace std;
int cnt;
int col, row;
bool check(int x, int y, vector<vector<char>> arr, vector<vector<int>>& visited){
    return ((x >= 0 && x < col) && (y >= 0 && y < row) && !visited[y][x] && arr[y][x] == '.');
}
void dfs(int x, int y, vector<vector<char>> arr, vector<vector<int>>& visited)
{
    cnt++;
    visited[y][x] = 1;
    int delrow[4] = {-1, 0, +1, 0};
    int delcol[4] = { 0, +1, 0, -1};
    for(int i = 0; i < 4; i++){
        int new_row = y + delrow[i];
        int new_col = x + delcol[i];
        if(check(new_col, new_row, arr, visited)){
            dfs(new_col, new_row, arr, visited);
        }
    }
}

int main()
{
    int t,k = 1;
    cin >> t;
    while(k <= t){
        cnt = 0;
        pair<int, int> start;
        cin >> col >> row;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<vector<char>> arr(row, vector<char>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                char c;
                cin >> c;
                arr[i][j] = c;
                if(arr[i][j] == '@'){
                    start.second = i;
                    start.first = j;
                }
            }
        }
        dfs(start.first, start.second, arr, visited);
        cout << "Case " << k << ": " << cnt << endl;
        k++;
    }
    return 0;
}
