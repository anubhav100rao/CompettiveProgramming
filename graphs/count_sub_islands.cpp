#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int n = grid2.size(), m = grid2[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));      

        vector<int>dx = {0, 0, -1, 1};
        vector<int>dy = {-1, 1, 0, 0};

        auto good = [&](const int x, const int y) {
            if(x < 0 || x >= n || y < 0 || y >= m) return false;
            return true;
        };

        auto bfs = [&](const int x, const int y) {
            visited[x][y] = true;

            queue<pair<int, int>>q;
            q.push({x, y});

            bool flag = true;

            while(!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for(int i = 0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(good(nx, ny) and !visited[nx][ny] and grid2[nx][ny] == 1) {
                        if(grid1[nx][ny] == 0)
                            flag = false;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            return flag;

        };

        int cnt = 0;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid2[i][j] and grid1[i][j] and !visited[i][j]) {
                    cnt += bfs(i, j);
                }
            }
        }

        return cnt;

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