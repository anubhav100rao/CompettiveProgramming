#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int>tree, arr;

int merge(int a, int b) {
    return max(a, b);
}

void build(int t, int s, int e) {
    if(s == e) {
        assert(t < tree.size());
        tree[t] = arr[s];
    } else {
        int mid = (s + e) / 2;
        assert(2*t + 1 < tree.size());
        build(2*t, s, mid); build(2*t + 1, mid + 1, e);
        tree[t] = merge(tree[2*t], tree[2*t + 1]);
    }
}

void update(int t, int s, int e, int idx, int val) {
    if(s == e) {
        tree[t] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if(idx > mid) update(2*t + 1, mid + 1, e, idx, val);
    else update(2*t, s, mid, idx, val);
    tree[t] = merge(tree[2*t], tree[2*t + 1]);
}

int query(int t, int s, int e, int k) {
    if(s == e) {
        if(tree[t] > k) return s;
        return -1;
    }
    int mid = (s + e) >> 1;
    if(tree[2*t] > k) {
        return query(2*t, s, mid, k);
    }
    return query(2*t + 1, mid + 1, e, k);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    arr = { 1, 3, 2, 4, 6 }; int n = arr.size();
    vector<vector<int>>q = {{2, 5}, {1, 3, 5}, {2, 4}, {2, 8}};
    tree = vector<int>(4*n, 0);
    build(1, 0, n-1); cout << tree[0] << " " << tree[1] << "\n";

    for(int i = 0; i<q.size(); i++) {
        if(q[i][0] == 1) {
            update(1, 0, n-1, q[i][1], q[i][2]);
        } else {
            cout << query(1, 0, n-1, q[i][1]) << "\n";
        }
    }

    return 0;
}