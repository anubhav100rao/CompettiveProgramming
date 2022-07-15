#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


template<typename T>
class Segtree {
public:
    vector<T> tree;
    vector<T>arr;
    int n;
    function<T(T,T)>merge;

    

    Segtree(int n, function<T(T,T)>merge) {
        this->n = n;
        tree.resize(4 * n);
        this->merge = merge;
    }

    Segtree(int n, function<T(T, T)>merge, vector<T>& arr) {
        this->n = n;
        tree.resize(4 * n);
        this->arr = arr;
        this->merge = merge;
        build(1, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start > end) return;
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = merge(tree[left], tree[right]);
    }

    T query(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return merge(T{}, T{});
        if (start >= l && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        T left = query(node * 2, start, mid, l, r);
        T right = query(node * 2 + 1, mid + 1, end, l, r);
        return merge(left, right);
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start > end || start > idx || end < idx) return;
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, idx, val);
        update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[left], tree[right]);
    }

    T operator[](int idx) {
        return query(1, 0, n - 1, idx, idx);
    }

    void update(int idx, T val) {
        update(1, 0, n - 1, idx, val);
    }

    void print() {
        for (int i = 0; i < tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
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

    function<pair<int, int>(pair<int, int>, pair<int, int>)> merge = [&](pair<int, int> a, pair<int, int> b) {
        if(a.first > b.first) return a;
        else if(b.first > a.first) return b;
        else return pair<int, int>{a.first, a.second + b.second};
    };

    int n; cin >> n;
    vector<pair<int, int>>arr(n, {0, 0});
    for(int i = 0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = 1;
    }
    

    Segtree<pair<int, int>> segtree(n, merge, arr);

    int q; cin >> q;

    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int idx; cin >> idx;
            segtree.update(idx, {arr[idx].first, arr[idx].second + 1});
        }
        else {
            int l, r; cin >> l >> r;
            cout << segtree.query(1, 0, n - 1, l, r).second << endl;
        }
    }

    return 0;
}