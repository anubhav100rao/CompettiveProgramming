#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<int>>adj;
vector<bool>visited;

bool dfs(int node, int parent) {
    visited[node] = true;
    for(int &child: adj[node]) {
        if(visited[child] and child != parent)
            return true;
        else if(!visited[child] and dfs(child, node)) {
            return true;
        }
    }
    return false;
}

bool detect_cycle(int n) {
    visited = vector<bool>(n+1, false);
    
    for(int i = 1; i<=n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1))
                return true;
        }
    }
    return false;
}

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