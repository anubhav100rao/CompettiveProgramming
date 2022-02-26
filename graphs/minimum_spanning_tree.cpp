#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class DSU {
public:
    vector<int>parent, _size;
    DSU(int n) {
        parent = vector<int>(n+1, 0);
        _size = vector<int>(n+1, 0);
        for(int i = 0; i<=n; i++) {
            parent[i] = i;
            _size[i] = 1;
        }
    }
    int find_parent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = find_parent(parent[node]);
    }

    void union_sets(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);
        if(a == b) return;
        if(_size[a] < _size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        _size[a] += _size[b];
    }

    bool same_set(int a, int b) {
        return find_parent(a) == find_parent(b);
    }
};

class Kruskals {
public:
    int n, m;
    vector<array<int, 3>>edges;
    void readEdges() {
        cin >> n >> m;
        for(int i = 0; i<m; i++) {
            int a, b, w; cin >> a >> b >> w;
            edges.push_back({a, b, w});
        }
    }
    int mst() {
        sort(edges.begin(), edges.end(), [&](const auto &A, const auto &B) {
            return A[2] < B[2];
        });
        int total_weight = 0;
        DSU dsu = DSU(n);
        for(array<int, 3> edge: edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            if(!dsu.same_set(a, b)) {
                dsu.union_sets(a, b);
                total_weight += w;
            }   
        }
        return total_weight;
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