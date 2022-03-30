#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<int>>adj;
vector<int>val;
int timer = 0;
vector<int>tin;
vector<int>tout;

struct Segtree {

    vector<int>arr;
    vector<int>tree;

    void _buildtree(int treeNode, int left, int right) {
        if(left == right) {
            tree[treeNode] = arr[left];
            return;
        }

        int mid = left + (right - left) / 2;
        _buildtree(2*treeNode, left, mid);
        _buildtree(2*treeNode + 1, mid + 1, right);

        tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
    }

    void build() {
        tree = vector<int>(arr.size() * 4 + 10, 0);
        _buildtree(1, 0, arr.size()-1);
    }   

    int _query(int treeNode, int left, int right, int st, int en) {
        if(left > en || right < st)
            return 0;
        if(left >= st && right <= en)
            return tree[treeNode];
        int mid = left + (right - left) / 2;
        int ans1 = _query(2*treeNode, left, mid, st, en);
        int ans2 = _query(2*treeNode + 1, mid + 1, right, st, en);
        return (ans1 + ans2);
    }   

    int query(int st, int en) {
        return _query(1, 0, arr.size() - 1, st, en);
    }

    void _update(int treeNode, int left, int right, int idx, int val) {
        if(left == right) {
            tree[treeNode] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if(idx > mid) {
            _update(2*treeNode + 1, mid + 1, right, idx, val);
        } else {
            _update(2*treeNode, left, mid, idx, val);
        }
        tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
    }

    void update(int idx, int val) {
        _update(1, 0, arr.size() - 1, idx, val);
    }
    

};



Segtree segtree;


void dfs(int node, int parent) {
    segtree.arr.push_back(node);
    tin[node] = timer++;

    for(int child: adj[node]) {
        if(child != parent) {
            dfs(child, node);
        }
    }
    segtree.arr.push_back(node);
    tout[node] = timer;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    int n; cin >> n;
    adj = vector<vector<int>>(n+1);
    val = vector<int>(n+1, 0);
    for(int i = 1; i<=n; i++)
        cin >> val[i];
    for(int i = 0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int q; cin >> q;
    while(q--) {
        int type; cin >> type;

        if(type == 1) { // answer query
            int node; cin >> node;
            int left = tin[node], right = tout[node];
            cout << segtree.query(left, right) << '\n';
        } else { // update query
            int node, val;
            cin >> node >> val;
            int left = tin[node], right = tout[node];
            segtree.update(left, val);
            segtree.update(right, val);
        }
    }

    return 0;
}