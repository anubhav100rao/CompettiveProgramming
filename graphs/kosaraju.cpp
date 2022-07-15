#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int kosaraju(int n, vector<vector<int>> adj) {
    vector<vector<int>>transpose(n);
    for(int i = 0; i<n; i++) {
        for(int j: adj[i]) {
            transpose[j].push_back(i);
        }
    }

    vector<bool>visited(n, false);
    stack<int>topo_order;

    function<void(int, vector<vector<int>>)> dfs = [&](int node, vector<vector<int>>adj) {
        visited[node] = true;
        for(int child: adj[node]) {
            if(!visited[child]) {
                dfs(child, adj);
            }
        }
        topo_order.push(node);
    };

    for(int i = 0; i<n; i++) {
        if(!visited[i]) {
            dfs(i, adj);
        }
    }
    int cnt = 0;
    visited = vector<bool>(n, false);
    while(!topo_order.empty()) {
        int top = topo_order.top(); topo_order.pop();
        if(!visited[top]) {
            cnt++;
            dfs(top, transpose);
        }
    }

    return cnt;
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