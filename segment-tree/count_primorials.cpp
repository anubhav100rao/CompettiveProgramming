#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define int long long
/*
Given an array consisting of N positive integers, and Q queries where each query is one of the following types:

1 l r – Requires printing the count of primorials in the range of indices [l, r].
2 p x –  Need to assign a value x at a given index p.
*/

const int N = 1e7 + 10;
vector<bool>isPrime(N, true);
unordered_set<int>primorials;
const int mod = 1e9 + 7;

void precompute() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i<N; i++) {
        for(int j = i*i; j<N; j+=i) {
            isPrime[j] = false;
        }
    }
    // for(int i = 2; i<=100; i++) if(isPrime[i]) cout << "prime " << i << "\n";
    primorials.insert(2);
    int pr = 2;
    for(int i = 3; i<N; i++) {
        if(isPrime[i]) {
            int curr = (pr * i) % mod;
            primorials.insert(curr);
            pr = curr;
            
        }
    }
}


int n;
vector<int>arr;
vector<int>tree;

void build(int treeNode, int start, int end) {
    if(start == end) {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    build(2*treeNode, start, mid);
    build(2*treeNode + 1, mid + 1, end);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
}

void update(int treeNode, int start, int end, int idx, int val) {
    if(start == end) {
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    if(idx > mid) {
        update(2*treeNode + 1, mid + 1, end, idx, val);
    } else {
        update(2*treeNode, start, mid, idx, val);
    }
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
}

int query(int treeNode, int start, int end, int left, int right) {
    if(left > end || right < start)
        return 0;
    if(start <= left and end >= right)
        return tree[treeNode];
    int mid = start + (end - start) / 2;

    return query(2*treeNode, start, mid, left, right) + query(2*treeNode + 1, mid + 1, end, left, right);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    precompute();

    cin >> n;
    arr = vector<int>(n);
    tree = vector<int>(4*n, 0);
    for(int &i: arr) {
        cin >> i;
        if(primorials.count(i)) i = 1;
        else i = 0;
    }

    build(1, 0, n-1);

    int q; cin >> q;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int left, right;
            cin >> left >> right;
            cout << query(1, 0, n-1, left, right) << "\n";
        } else {
            int x, val; cin >> x >> val;
            int flag = primorials.count(val) ? 1 : 0;
            if(arr[x] ^ flag) {
                update(1, 0, n-1, x, arr[x] ^ flag);
            }
        }
    }

    return 0;
}