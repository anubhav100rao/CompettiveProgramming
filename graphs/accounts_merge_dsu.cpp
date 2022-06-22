#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    struct DSU {
        vector<int>parent;
        vector<int>sz;

        DSU(int n) {
            parent = vector<int>(n, 0);
            iota(parent.begin(), parent.end(), 0);
            sz = vector<int>(n, 1);
        }

        int find_parent(int node) {
            if(node == parent[node])
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
    
    };


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int>emailGroup;

        for(int i = 0; i<n; i++) {
            int ac = accounts[i].size();
            for(int j = 1; j<ac; j++) {
                string email = accounts[i][j];
                string name = accounts[i][0];
                if(emailGroup.count(email)) {
                    dsu.union_sets(i, emailGroup[email]);
                } else {
                    emailGroup[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>>components;
        for(auto &[email, group]: emailGroup) {
            components[dsu.find_parent(group)].push_back(email);
        }

        vector<vector<string>>mergedAccounts;
        for(auto [group, emails]: components) {
            vector<string>component = { accounts[group][0] };
            set<string>hsh(emails.begin(), emails.end());
            for(string s: hsh)
                component.push_back(s);
            mergedAccounts.push_back(component);
        }

        return mergedAccounts;
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