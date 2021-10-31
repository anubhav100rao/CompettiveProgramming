#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"


class Solution {
public:
    /**
     * first idea is to dfs tree to check path
     * this will where we should go in tree
     * then we simply make dfs and increment timer when we enter a child and when leave it as well
    */
    vector<bool>vals; // initally 0
    vector<vector<int>>g;
    int timer = 0;
    void dfs_path(int node, int parent, vector<bool>&hasApple) {
        for(int child: g[node]) {
            if(child != parent) {
                dfs_path(child, node, hasApple);
                vals[node] = vals[node] || vals[child];
            }
        }
        if(hasApple[node]) vals[node] = true;
    }
    void dfs(int node, int parent) {
        for(int child: g[node]) {
            if(child != parent and vals[child]) {
                timer++;
                dfs(child, node);
                timer++;
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        g = vector<vector<int>>(n);
        for(auto edge: edges) g[edge[0]].push_back(edge[1]), g[edge[1]].push_back(edge[0]);
        vals = vector<bool>(n, false);
        dfs_path(0, 0, hasApple);
        dfs(0, 0);
        return timer;
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