#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size(), m = grid[0].size();
        vector<int>dx = {0, 0, -1, 1};
        vector<int>dy = {1, -1, 0, 0};  

        auto good = [&](const int x, const int y) {
            if(x < 0 || x >= n || y < 0 || y >= m) return false;
            return grid[x][y] == grid[row][col];
        };

        auto isBorder = [&](const int x, const int y) {
            int cnt = 0;
            for(int i = 0; i<4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                cnt += good(new_x, new_y);
            }

            return cnt < 4;
        };      


        queue<pair<int, int>>q;
        q.push({row, col});
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        visited[row][col] = true;
        
        vector<vector<int>>arr = grid;

        if(isBorder(row, col)) arr[row][col] = color;

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i<4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(!good(new_x, new_y)) continue;
                if(visited[new_x][new_y]) continue;
                visited[new_x][new_y] = true;
                if(isBorder(new_x, new_y)) {
                    arr[new_x][new_y] = color;
                }
                q.push({new_x, new_y});
            }
        }
        return arr;
    }
};


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
 
    return 0;
}