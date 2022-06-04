#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct segment_lazy {
    vector<int>tree;
    vector<int>lazy;
    vector<int>arr;
    void init(vector<int>&arr) {
        int n = arr.size();
        this->arr = arr;
        tree = vector<int>(4*n, 0);
        lazy = tree;
    }

    void build(int t, int s, int e) {
        if(s == e) {
            tree[t] = arr[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(2*t, s, mid); build(2*t + 1, mid + 1, e);
        tree[t] = tree[2*t] + tree[2*t + 1];
    }

    void update(int t, int s, int e, int left, int right, int val) {
        if(lazy[t] != 0) {
            if(s != e) {
                lazy[2*t] += lazy[t];
                lazy[2*t + 1] += lazy[t];
            }
            tree[t] += (e - s + 1) * lazy[t];
            lazy[t] = 0;
        }
        if(right > left || left > e || right < s) return;
        if(left <= s and right >= e) {
            if(s != e) {
                lazy[2*t] += val;
                lazy[2*t + 1] += val;
            }
            tree[t] += (e - s + 1) * val;
            return;
        }
        int mid = s + (e -s) / 2;

        update(2*t, s, mid, left, right, val);
        update(2*t+1, mid + 1, e, left, right, val);
        tree[t] = tree[2*t] + tree[2*t + 1];
    }

    int query(int t, int s, int e, int left, int right) {
        if(lazy[t] != 0) {
            if(s != e) {
                lazy[2*t] += lazy[t];
                lazy[2*t + 1] += lazy[t];
            }
            tree[t] += lazy[t];
            lazy[t] = 0;
            return;
        }

        if(left > right || left > e || right < s) return 0;

        if(s >= left and e <= right)
            return tree[t];
        
        int mid = s + (e - s) / 2;
        return query(2*t, s, mid, left, right) + query(2*t + 1, mid + 1, e, left, right);
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