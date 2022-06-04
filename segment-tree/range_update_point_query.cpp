#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


vector<int>tree;

void update(int t, int s, int e, int idx, int val) {
    if(s == e) {
        tree[t] += val;
        return;
    }
    int mid = (s + e) / 2;
    if(idx > mid) update(2*t + 1, mid + 1, e, idx, val);
    else update(2*t, s, mid, idx, val);
    tree[t] = tree[2*t] + tree[2*t + 1];
}

int query(int t, int s, int e, int l, int r) {
    if(l > e || r < s) return 0;
    if(l <= s and r >= e) {
        cout << tree[t] << " ??\n";
        return tree[t];
    }
    int mid = (s + e) / 2;
    return query(2*t, s, mid, l, r) + query(2*t + 1, mid + 1, e, l, r);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    int n = 5;
    tree = vector<int>(4*n + 5, 0);
    vector<vector<int> >
        Q = { { 1, 0, 1, 100 }, { 2, 1 } };
    for(int i = 0; i<Q.size(); i++) {
        if(Q[i][0] == 1) {
            int l = Q[i][1], r = Q[i][2], val = Q[i][3];
            update(1, 0, n-1, l, val);
            if(r+1 < n)
                update(1, 0, n-1, r + 1, -val);
        } else {
            int idx = Q[i][1];
            cout << query(1, 0, n-1, 0, idx) << "\n";
        }
    }
    return 0;
}