#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:

    struct DSU {
        vector<int>parent, sz;
        DSU(int n) {
            parent = vector<int>(n, 0);
            iota(parent.begin(), parent.end(), 0);
            sz = vector<int>(n, 1);
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
            if(sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }

        int components() {
            int cnt = 0;
            for(int i = 0; i<parent.size(); i++)
                if(parent[i] == i)
                    cnt++;
            return cnt;
        }
    };

    bool good(string &s, string &p) {
        int cnt = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] != p[i])
                cnt++;
        }
        return cnt < 3;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n =strs.size();
        DSU dsu(n);
        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                if(good(strs[i], strs[j]))
                    dsu.union_sets(i, j);
            }
        }
        return dsu.components();
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