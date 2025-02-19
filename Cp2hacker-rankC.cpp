#include<bits/stdc++.h>
using namespace std;

int row, col;
bool check(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& visited){
    return ((x >= 0 && x < col) && (y >= 0 && y < row) && !visited[y][x] && grid[y][x] == '#');
}

void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& visited){
    visited[y][x] = 1;
    int delrow[8] = {-1, -1, -1, 0, 0, +1, +1, +1};
    int delcol[8] = {-1, 0, +1, -1, +1, -1, 0, +1};
    for(int i = 0; i < 8; i++){
        int new_row = y + delrow[i];
        int new_col = x + delcol[i];
        if(check(new_col, new_row, grid, visited)){
            dfs(new_col, new_row, grid, visited);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int cnt = 0;
        cin >> row >> col;
        vector<vector<char>> grid(row, vector<char>(col, 0));
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                char c;
                cin >> c;
                grid[i][j] = c;
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(check(j, i, grid, visited)){
                    dfs(j, i, grid, visited);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
