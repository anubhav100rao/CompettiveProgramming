#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>>res(n, vector<int>(m, 0));      

        vector<int>dx = {0, 0, -1, 1};
        vector<int>dy = {-1, 1, 0, 0};

        vector<vector<bool>>visited(n, vector<bool>(m, false));

        auto good = [&](const int x, const int y) {
            if(x < 0 || x >= n || y < 0 || y >= m) return false;
            return true;
        };

        queue<pair<int, int>>q;

        for(int i = 0; i < n; i++) {
            q.push({i, 0});
            res[i][0] = 1;
            visited[i][0] = true;
        }

        for(int i = 0; i < m; i++) {
            q.push({0, i});
            res[0][i] = 1;
            visited[0][i] = true;
        }

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int n_x = x + dx[i];
                int n_y = y + dy[i];
                if(good(n_x, n_y) and heights[n_x][n_y] >= heights[x][y]) {
                    if(!visited[n_x][n_y]) {
                        res[n_x][n_y] |= 1;
                        q.push({n_x, n_y});
                        visited[n_x][n_y] = true;
                    }
                }
            }
        }

        visited = vector<vector<bool>>(n, vector<bool>(m, false));


        for(int i = 0; i < n; i++) {
            q.push({i, m - 1});
            res[i][m-1] |= 2;
            visited[i][m-1] = true;
        }

        for(int i = 0; i < m; i++) {
            q.push({n - 1, i});
            res[n - 1][i] |= 2;
            visited[n-1][i] = true;
        }

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int n_x = x + dx[i];
                int n_y = y + dy[i];
                if(good(n_x, n_y) and heights[n_x][n_y] >= heights[x][y]) {
                    if(!visited[n_x][n_y]) {
                        res[n_x][n_y] |= 2;
                        q.push({n_x, n_y});
                        visited[n_x][n_y] = true;
                    }
                }
            }
        }

        vector<vector<int>>ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(res[i][j] == 3)
                    ans.push_back({i, j});
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