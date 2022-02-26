#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// prims algorithm form minimum spanning tree

class MinSpanningTree {
public:

    int n;
    vector<vector<pair<int, int>>> adj;
    vector<int> dist;
    vector<bool> visited;
    vector<int> parent;
    vector<int> ans;
    MinSpanningTree(int n) {
        this->n = n;
        adj.resize(n);
        dist.resize(n);
        visited.resize(n);
        parent.resize(n);
        ans.resize(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    void prims() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int u = top.second;
            if (visited[u]) continue;
            visited[u] = true;
            ans[u] = top.first;
            for (auto &e : adj[u]) {
                int v = e.first;
                int w = e.second;
                if (!visited[v]) {
                    pq.push({w, v});
                    parent[v] = u;
                }
            }
        }
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