#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    struct DSU {
        vector<int>parent, sz;
        DSU(int n) {
            parent = vector<int>(n);
            iota(parent.begin(), parent.end(), 0);
            sz = vector<int>(n, 1);
        }
        int find_parent(int node) {
            if(parent[node] == node) return node;
            return parent[node] = find_parent(parent[node]);
        }
        
        void union_sets(int a, int b) {
            a = find_parent(a), b = find_parent(b);
            if(a == b) return;
            if(sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
        
        bool same_set(int a, int b) {
            return find_parent(a) == find_parent(b);
        }
    };

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dsu = DSU(n);
        for(auto &v: pairs) {
            int a = v[0], b = v[1];
            dsu.union_sets(a, b);
        }
        vector<vector<pair<char, int>>>adj(n);
        for(int i = 0; i<n; i++) {
            int p = dsu.find_parent(i);
            cout << p << " ";
            adj[p].push_back({s[i], i});
        }
        for(int i = 0; i<n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        string res = string(n, 'a');
        for(int i = 0; i<n; i++) {
            set<int>indices;
            for(auto &[a, b]: adj[i]) {
                indices.insert(b);
            }
            for(auto &[a, b]: adj[i]) {
                b = *indices.begin();
                indices.erase(indices.begin());
            }
            for(auto [a, b]: adj[i]) {
                res[b] = a;
            }
        }
        return res;
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