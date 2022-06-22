#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
class Solution {
public:

    int n, m;
    vector<int>dx = {-1, 1, 0, 0};
    vector<int>dy = {0, 0, -1, 1};
    vector<vector<int>>grid;
    vector<vector<int>>graph;
    vector<vector<bool>>visited;
    map<int, int>component_size;


    bool good(const int x, const int y) {
        if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) 
            return false;
        return grid[x][y];
    };

    void dfs(int x, int y, int &cnt, int color) {
        visited[x][y] = true;
        graph[x][y] = color;
        cnt++;
        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(good(nx, ny)) {
                dfs(nx, ny, cnt, color);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m =  grid[0].size();
        this->grid = grid;
        graph = vector<vector<int>>(n, vector<int>(m, 0));
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int color = 1;
        int cnt = 0;
        
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] and !visited[i][j]) {
                    cnt = 0;
                    dfs(i, j, cnt, color);
                    cout << cnt << "\n";
                    component_size[color] = cnt;
                    ans = max(ans, cnt);
                    color++;
                }
            }
        }

        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 0) {
                    set<int>done;
                    int curr = 1;
                    for(int k = 0; k<4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if(good(ni, nj)) {
                            if(!done.count(graph[ni][nj])) {
                                done.insert(graph[ni][nj]);
                                curr += component_size[graph[ni][nj]];
                            }
                        }
                    }

                    ans = max(ans, curr);
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