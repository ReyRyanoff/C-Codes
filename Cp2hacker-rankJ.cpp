#include<bits/stdc++.h>
using namespace std;
int a, b, start, finish;

bool check(int x, int y, vector<vector<bool>>& visited){
    return ((x >= 0 && x < 8) && (y >= 0 && y < 8) && !visited[y][x]);
}

int minKnightmoves(int x1, int y1, int x2, int y2)
{
    int moves = 0;
    queue<pair<int, int>> q;
    q.push({x1, y1});
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    visited[y1][x1] = true;
    int delrow[8] = {-2, -2, -1, +1, +2, +2, -1, +1};
    int delcol[8] = {-1, +1, -2, -2, -1, +1, +2, +2};
    while(!q.empty())
    {
        for(int sz = q.size(); sz > 0; --sz){
            int x, y;
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(x == x2 && y == y2) return moves;
            for(int i = 0; i < 8; i++){
                int new_row = y + delrow[i];
                int new_col = x + delcol[i];
                if(check(new_col, new_row, visited)){
                    visited[new_row][new_col] = true;
                    q.push({new_col, new_row});
                }
            }
        }
        ++moves;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        char starting, ending;
        cin >> starting >> a >> ending >> b;
        a--;b--;
        start = starting - 'a';
        finish = ending - 'a';
        int minimum = minKnightmoves(start, a, finish, b);
        cout << minimum << endl;
    }
    return 0;
}
