#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int n, k;
vector<int>arr;
vector<vector<int>>tree;
vector<int>lazy;
vector<int>ans;

void build(int t, int s, int e) {
    if(s == e) {
        tree[t][arr[s] % k] = 1;
        return;
    }
    int mid = s + (e - s) / 2;
    build(2*t, s, mid); build(2*t + 1, mid + 1, e);
    for(int i = 0; i<k; i++)
        tree[t][i] = tree[2*t][i] + tree[2*t + 1][i];
}

void update(int t, int s, int e, int left, int right, int val) {
    lazy[t] %= k;
    if(lazy[t] != 0) {
        if(s != e) {
            lazy[2*t] += lazy[t]; lazy[2*t] %= k;
            lazy[2*t + 1] += lazy[t]; lazy[2*t + 1] %= k;
        }
        int incr = lazy[t];
        vector<int>temp(k);
        for(int i = 0; i<k; i++) {
            temp[i] = tree[t][i];
        }
        for(int i = 0; i<k; i++) {
            tree[t][(i + incr) % k] = temp[i];
        }
        lazy[t] = 0;
    }
    if(right < left || left > e || right < s)
        return;
    
    if(s <= left and e >= right) {
        val %= k;
        vector<int>temp(k);
        for(int i = 0; i<k; i++) {
            tree[t][(val + i) % k] = temp[i];
        }
        if(s != e) {
            lazy[2*t] += val; ;lazy[2*t] %= k;
            lazy[2*t + 1] += val; lazy[2*t + 1] %= k;
        }
        return;
    }
    int mid = s + (e - s) / 2;
    update(2*t, s, mid, left, right, val);
    update(2*t + 1, mid + 1, e, left, right, val);
    for(int i = 0; i<k; i++)
        tree[t][i] = tree[2*t][i] + tree[2*t + 1][i];
}

void query(int t, int s, int e, int left, int right) {
    lazy[t] %= k;
    if(lazy[t] != 0) {
        if(s != e) {
            lazy[2*t] += lazy[t]; lazy[2*t] %= k;
            lazy[2*t + 1] += lazy[t]; lazy[2*t + 1] %= k;
        }
        int incr = lazy[t];
        vector<int>temp(k);
        for(int i = 0; i<k; i++) {
            temp[i] = tree[t][i];
        }
        for(int i = 0; i<k; i++) {
            tree[t][(i + incr) % k] = temp[i];
        }
        lazy[t] = 0;
    }

    if(right < left || left > e || right < s)
        return;

    if(s <= left and e >= right) {
        for(int i = 0; i<k; i++)
            ans[i] += tree[t][i];
        return;
    }

    int mid = s + (e - s) / 2;
    query(2*t, s, mid, left, right);
    query(2*t + 1, mid + 1, e, left, right);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    cin >> n >> k;
    arr = vector<int>(n); for(int &i: arr) { cin >> i; i %= k; }
    tree = vector<vector<int>>(4*n, vector<int>(k, 0));
    lazy = vector<int>(4*n, 0);
    ans = vector<int>(k, 0);

    int q; cin >> q;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {

        }
    }

    return 0;
}