#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    vector<int>parent;
    vector<int>sz;

    int find_parent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = find_parent(parent[node]);
    }

    void union_sets(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);
        if(a == b) return;

        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int N = n * m;
        parent = vector<int>(N, 0);
        iota(parent.begin(), parent.end(), 0);
        sz = vector<int>(N, 0);

        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) if(grid[i][j] == 1) sz[m * i + j] = 1;

        vector<int>dx = {0, 0, -1, 1};
        vector<int>dy = {1, -1, 0, 0};

        auto good = [&](const int x, const int y) {
            if(x < 0 || x >= n || y < 0 || y >= m) return false;
            return grid[x][y] == 1;
        };
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k<4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if(good(x, y)) {
                            union_sets(m * i + j, m * x + y);
                        }
                    }
                }
            }
        }
        return *max_element(sz.begin(), sz.end());
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