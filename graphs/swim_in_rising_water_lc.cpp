#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    struct compare {
        bool operator()(vector<int>&a, vector<int>&b) {
            return a[0] > b[0];
        }
    };
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, compare>q;
        q.push({0, 0, 0});
        const int inf = 1e9 + 7;
        int n = grid.size();

        vector<vector<bool>>visited(n, vector<bool>(n, false));
        vector<vector<int>>level(n, vector<int>(n, inf));

        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};

        auto good = [&](const int x, const int y) {
            if(x < 0 || x >= n || y < 0 || y >= n || visited[x][y]) return false;
            return true;
        };


        while(!q.empty()) {
            vector<int>top = q.top(); q.pop();
            int curr_level = top[0], x = top[1], y = top[2];
            if(visited[x][y])
                continue;
            visited[x][y] = true;

            for(int i = 0; i<4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(!good(new_x, new_y)) continue;
                if(grid[new_x][new_y] <= grid[x][y]) {
                    level[new_x][new_y] = level[x][y];
                    q.push({level[new_x][new_y], new_x, new_y});
                } else {
                    level[new_x][new_y] = grid[new_x][new_y];
                    q.push({level[new_x][new_y], new_x, new_y});
                }
            }
        }
        return level[n-1][n-1];
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