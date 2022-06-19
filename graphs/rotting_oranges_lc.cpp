#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>time(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) {
            if(grid[i][j] == 2)
                q.push({i, j});
        }
        vector<int>dx = {0, 0, -1, 1};
        vector<int>dy = {1, -1, 0, 0};

        auto good = [&](const int x, const int y) {
            if(x < 0 || x>= n || y < 0 || y >= m) return false;
            return true;
        };

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i<4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(!good(new_x, new_y)) continue;
                if(grid[new_x][new_y] == 1) {
                    q.push({new_x, new_y});
                    grid[new_x][new_y] = 2;
                    time[new_x][new_y] = time[x][y] + 1;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1) return -1;
                ans = max(ans, time[i][j]);
            }
        }

        return ans;
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