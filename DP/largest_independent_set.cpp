#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int n, m;
vector<vector<int>>adj;
vector<int>dp;

void dfs(int node, int parent) {
    for(int &child: adj[node]) if(child != parent) {
        dfs(child, node);
    }
    int taking_all_child = 0;
    int taking_all_grand_child = 0;
    for(int &child: adj[node]) if(child != parent) {
        taking_all_child += dp[child];
        for(int &grandChild: adj[child]) if(grandChild != node) {
            taking_all_grand_child += dp[grandChild];
        }
    }
    dp[node] = max(taking_all_child, 1 + taking_all_grand_child);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    dp = vector<int>(n+1, 1);
    for(int i = 0; i<m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << dp[1] << '\n';

    return 0;
}