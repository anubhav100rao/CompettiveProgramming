#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int n = grid.size(), m = grid[0].size();

        vector<int>dx = {0, 0, -1, 1};
        vector<int>dy = {1, -1, 0, 0};  

        auto good = [&](const int x, const int y) {
            if(x < 0 || x >= n || y < 0 || y >= m) return false;
            return grid[x][y] == 1;
        };

        auto compute = [&](const int x, const int y) {
            int cnt = 0;
            for(int i = 0; i<4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                cnt += good(new_x, new_y);
            }

            return 4 - cnt;
            
        };

        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1) {
                    ans += compute(i, j);
                }
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