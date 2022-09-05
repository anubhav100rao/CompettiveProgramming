#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int n;
vector<vector<pair<int, int>>>adj;

/**
 * 
 * bruteforce run dfs 'n' times
 * 
 * can we do better ?
 * I don't know for now, but I think we can :)
 * 
 * first intitution -> suppose we have an edge of weight w -> we just need to find out how many paths are there for which this edge 
 *                      is max value edge
 * how to achieve this ?
 * well I think, I have created a new problem instead of solving the previous one, it seems :)
 * 
 * 
 * 
 * Just USE DSU BABY
 * 
 * 
*/

struct Dsu {

    vector<int>parent;
    vector<int>sz;

    Dsu(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.resize(n, 0);
    }

    int find_parent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = find_parent(parent[node]); 
    }

    int union_sets(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);

        assert(a != b);
        
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        int ans = sz[a] * sz[b];
        sz[a] += sz[b];
        return ans;
    }


};


void solve() {
    int n; cin >> n;
    vector<vector<int>>edges;

    for(int i = 0; i < n - 1; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges.push_back({w, a, b});
    }

    sort(edges.begin(), edges.end());

    int ans = 0;

    Dsu dsu(n);

    for(int i = 0; i < n - 1; i++) {
        ans += dsu.union_sets(edges[i][1], edges[i][2]) * edges[i][0];
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    cin >> n;
    adj = vector<vector<pair<int, int>>>(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, b});
    }

    return 0;
}