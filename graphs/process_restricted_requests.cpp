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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        set<pair<int, int>>res;
        for(auto &v: restrictions) {
            res.insert({v[0], v[1]});
            res.insert({v[1], v[0]});
        }

        vector<bool>arr(requests.size(), false);
        DSU dsu = DSU(n);

        for(int i = 0; i<requests.size(); i++) {
            int a = requests[i][0], b = requests[i][1];
            a = dsu.find_parent(a);
            b = dsu.find_parent(b);
            bool flag = true;
            if(!dsu.same_set(a, b)) {
                for(auto &ban: restrictions) {
                    int x = dsu.find_parent(ban[0]), y = dsu.find_parent(ban[1]);
                    if(((x == a) and (y == b)) || ((x == b) and (y == a))) {
                        flag = false;
                        break;
                    }
                }
            }
            arr[i] = flag;
            if(flag)
                dsu.union_sets(a, b);
        }
        return arr;
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