#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class BIT {
public:
    int n;
    vector<int>tree, arr;

    BIT(vector<int>&a) {
        arr.push_back(0);
        for(int i: a) arr.push_back(i);
        n = a.size();
        tree = vector<int>(n + 1, 0);

        for(int i = 1; i<=n; i++)
            update(i, arr[i]);
    }

    void update(int idx, int val) {
        while(idx <= n) {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        int ans = 0;
        while(idx > 0) {
            ans += tree[idx];
            idx -= (idx & -idx);
        }
        return ans;
    }

    int range_query(int l, int r) {
        return query(r) - query(l - 1);
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