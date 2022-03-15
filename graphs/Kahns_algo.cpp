#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int n, m;
vector<vector<int>>adj;
vector<int>inDegree, outDegree;
vector<int>topo_order;

bool kahn_algo() {

    queue<int>q;
    int visited_nodes = 0;
    
    for(int i = 1; i<=n; i++)
        if(inDegree[i] == 0) {
            visited_nodes++;
            q.push(i);
            topo_order.push_back(i);
        }
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int child: adj[node]) {
            if(inDegree[child] <= 0) continue;
            inDegree[child] -= 1;
            if(inDegree[child] == 0) {
                visited_nodes++;
                q.push(child);
                topo_order.push_back(child);
            }
        }
    }

    return visited_nodes == n;
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
    inDegree = vector<int>(n+1, 0);
    outDegree = vector<int>(n+1, 0);
    for(int i = 0; i<m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
        outDegree[a]++;
    }
    return 0;
}