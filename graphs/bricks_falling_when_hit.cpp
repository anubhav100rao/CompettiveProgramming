#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    struct DSU {
        vector<int>parent, sz;
        
        DSU(int n) {
            parent = vector<int>(n, 0);
            iota(parent.begin(), parent.end(), 0);
            sz = vector<int>(n, 1);
        }
        int find_parent(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find_parent(parent[x]);
        }

        void union_sets(int a, int b) {
            a = find_parent(a), b = find_parent(b);
            if(a == b) return;
            if(sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }

        int component_size(int x) {
            return sz[find_parent(x)];
        }

        // this will give the size of connected component of zeroth row elements
        // all zeroth row element are hypothetically connected to n * m
        int top() {
            return component_size(sz.size() - 1) - 1;
        }
    };

    vector<int>dr = {1, -1, 0, 0}, dc = {0, 0, -1, 1};

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>arr = grid;
        for(auto &v: hits) {
            arr[v[0]][v[1]] = 0;
        }

        auto get_index = [&](const int i, const int j) {
            return i * m + j;
        };

        DSU dsu = DSU(n * m + 1);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(arr[i][j] == 1) {
                    int idx = get_index(i, j);
                    if(i == 0)
                        dsu.union_sets(idx, n * m);
                    if(i > 0 and arr[i-1][j])
                        dsu.union_sets(idx, get_index(i - 1, j));
                    if(j > 0 and arr[i][j-1])
                        dsu.union_sets(idx, get_index(i, j - 1));
                }
            }
        }

        int t = hits.size();
        vector<int>ans(t, 0);
        while(t--) {
            int r = hits[t][0], c = hits[t][1];
            int preRoof = dsu.top(); // this is size of connected component of zeroth row (they all connected)
            if(grid[r][c] == 0) {
                continue;
            }
            int idx = get_index(r, c);
            for(int i = 0; i<4; i++) {
                int x = r + dr[i];
                int y = c + dc[i];
                if(x >= 0 and x < n and y >= 0 and y < m) {
                    if(arr[x][y] == 1) {
                        dsu.union_sets(idx, get_index(x, y));
                    }
                }
            }
            if(r == 0) {
                dsu.union_sets(idx, n * m);
            }
            arr[r][c] = 1;
            ans[t] = max(0, dsu.top() - preRoof - 1);
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
    vector<vector<int>>grid = {{1},{1},{1},{1},{1}};

    vector<vector<int>>bricks = {{3,0},{4,0},{1,0},{2,0},{0,0}};
    Solution sol;
    for(int i: sol.hitBricks(grid, bricks)) cout << i << " ";
    return 0;
}