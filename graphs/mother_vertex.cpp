#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int n, m; 
vector<vector<int>>adj;
vector<bool>visited;

/**
 * if mother vertex exists then it will remove last from dfs calls
 * else no mother vertex exist for given graph
 * 
 * algorithm
 * last = -1
 * for v in not visited nodes:
 *          dfs(v)
 *          last = v
 * this last is the candidate of mother_vertex
 * just run dfs to confirm it.
*/

void dfs(int node) {
    visited[node] = true;
    for(int &child: adj[node]) {
        if(!visited[child]) {
            dfs(child);
        }
    }
}

int find_mother() {
    visited = vector<bool>(n+1, false);
    int last = -1;
    for(int i = 1; i<=n; i++) {
        if(!visited[i]) {
            dfs(i);
            last = i;
        }
    }
    visited = vector<bool>(n+1, false);
    dfs(last);
    for(int i = 1; i<=n; i++) {
        if(!visited[i])
            return -1;
    }
    return last;
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
    visited = vector<bool>(n+1, false);
    for(int i = 0; i<m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    cout << find_mother();

    return 0;
}