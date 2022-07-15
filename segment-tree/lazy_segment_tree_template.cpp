#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


// Lazy Segtree template

template<typename T>
class LazySegtree {
public:
    int n;
    vector<T>tree;
    vector<T>arr;
    vector<T>lazy;
    function<T(T,T)>merge;
    function<T(T,T)>oper;
    
    LazySegtree(int n, function<T(T,T)>merge, function<T(T,T)>oper) {
        this->n = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        this->merge = merge;
        this->oper = oper;
    }

    LazySegtree(int n, function<T(T, T)>merge, function<T(T,T)>oper, vector<T>& arr) {
        this->n = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        this->arr = arr;
        this->merge = merge;
        this->oper = oper;
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

    // lazy query
    T query(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return merge(T{}, T{});

        if(lazy[node] != T{}) {
            tree[node] = oper(tree[node], lazy[node]);
            if(start != end) {
                lazy[node * 2] = oper(lazy[node * 2], lazy[node]);
                lazy[node * 2 + 1] = oper(lazy[node * 2 + 1], lazy[node]);
            }
            lazy[node] = T{};
        }

        if (start >= l && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        T left = query(node * 2, start, mid, l, r);
        T right = query(node * 2 + 1, mid + 1, end, l, r);
        return merge(left, right);
    }

    // void lazy update
    void update(int node, int start, int end, int left, int right, T val) {
        if(start > end || start > right || end < left) return;
        if(lazy[node] != T{}) {
            tree[node] = oper(tree[node], lazy[node]);
            if(start != end) {
                lazy[node * 2] = oper(lazy[node * 2], lazy[node]);
                lazy[node * 2 + 1] = oper(lazy[node * 2 + 1], lazy[node]);
            }
            lazy[node] = T{};
        }

        if(start >= left and end <= right) {
            tree[node] = oper(tree[node], val);
            if(start != end) {
                lazy[node * 2] = oper(lazy[node * 2], val);
                lazy[node * 2 + 1] = oper(lazy[node * 2 + 1], val);
            }
        }

        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, left, right, val);
        update(node * 2 + 1, mid + 1, end, left, right, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
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

    vector<int>arr = {1,2,3,4,5,6,7,8,9,10};

    function<int(int,int)>merge = [&](int a, int b) {
        return a + b;
    };

    function<int(int, int)>oper = [&](int a, int b) {
        return a + b;
    };

    LazySegtree<int>segtree(arr.size(), merge, oper, arr);

    return 0;
}