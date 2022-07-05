#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

class Solution {
public:

    vector<int>visited;
    vector<unordered_set<int>>adj;

    bool dfs(int node) {
        visited[node] = 1;
        for(int child: adj[node]) {
            if(visited[child] == 2) continue;
            if(visited[child] == 1) return true;
            if(visited[child] == 0 and dfs(child))
                return true;
        }
        visited[node] = 2;
        return false;
    }


    bool isPrintable(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // max_color <= 60
        adj = vector<unordered_set<int>>(61);
        for(int color = 1; color < 61; color++) {
            int minx = n, miny = m, maxx = -1, maxy = -1;

            for(int i = 0; i<n; i++) {
                for(int j = 0; j<m; j++) {
                    if(grid[i][j] == color) {
                        minx = min(i, minx);
                        miny = min(j, miny);
                        maxx = max(i, maxx);
                        maxy = max(j, maxy);
                    }
                }
            }

            for(int i = minx; i <= maxx; i++) {
                for(int j = miny; j <= maxy; j++) {
                    if(grid[i][j] != color)
                        adj[color].insert(grid[i][j]);
                }
            }
        }


        visited = vector<int>(61, 0);

        for(int i = 1; i<61; i++) {
            if(visited[i] == 0) {
                if(dfs(i))
                    return false;
            }
        }
        return true;
    }
};


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
        
    return 0;
}