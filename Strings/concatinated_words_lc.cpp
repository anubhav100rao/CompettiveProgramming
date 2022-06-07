#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class BIT {
public:
    // ONE BASED INDEXING
    
    vector<int>tree;
    int n;

    BIT(vector<int>&arr) {
        n = arr.size();
        tree = vector<int>(n+1, 0);
        for(int i = 1; i<=n; i++)
            update(i, arr[i]);
    }
    
    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += tree[idx];
            idx -= (idx & (-idx));
        }
        return sum;
    }
    int range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int idx, int val) {
        while(idx <= n) {
            tree[idx] += val;
            idx += (idx & (-idx));
        }
    }

    void update_range(int l, int r, int val) { // this technique works for range_update and point query
        update(l, val);
        update(r + 1, -val);
    }

};

class Solution {
public:

    unordered_set<string>hsh;
    vector<string>res;
    vector<int>dp;

    bool solve(int idx, string &str) {
        if(idx >= str.size()) {
            return true;
        }
        if(dp[idx] != -1)
            return dp[idx];

        for(int len = 1; len<=str.size(); len++) {
            if(hsh.count(str.substr(idx, len)) and solve(idx + len, str))
                return dp[idx] = 1;
        }
        return dp[idx] = 0;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(string str: words) hsh.insert(str);

        for(string &str: words) {
            if(str.size() == 0) continue;
            hsh.erase(str);
            dp = vector<int>(str.size() + 1, -1);
            if(solve(0, str)) {
                res.push_back(str);
            }
            hsh.insert(str);
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
    vector<string>arr = {""};
    Solution sol;
    return 0;
}