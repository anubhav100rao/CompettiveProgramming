#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// question -> q queries (l, r) -> elements greater than k
class MergeSortTree {
public:
    int n;
    vector<int>arr;
    vector<vector<int>>tree;

    MergeSortTree(vector<int>arr) {
        this->n = arr.size();
        this->arr = arr;
        tree = vector<vector<int>>(4*n + 10);
        build(1, 0, n - 1);
    }

    vector<int>merge(const vector<int>&a, const vector<int>&b) {
        vector<int>res;
        int i = 0, j = 0;
        while(i < a.size() and j < b.size()) {
            if(a[i] < b[j]) res.push_back(a[i++]);
            else res.push_back(b[j++]);
        }

        while(i < a.size()) res.push_back(a[i++]);
        while(j < b.size()) res.push_back(b[j++]);

        return res;
    }


    void build(int treeNode, int start, int end) {
        if(start == end) {
            tree[treeNode].push_back(arr[start]);
            return;
        }

        int mid = start + (end - start) / 2;
        build(2*treeNode, start, mid);
        build(2*treeNode + 1, mid + 1, end);

        tree[treeNode] = merge(tree[2*treeNode], tree[2*treeNode + 1]);
    }

    int _query(int treeNode, int start, int end, int l, int r, int k) {
        if(start > r || end < l) return 0;
        if(start >= l and end <= r) {
            return tree[treeNode].end() - upper_bound(tree[treeNode].begin(), tree[treeNode].end(), k);
        }
        int mid = start + (end - start) / 2;
        int ans_left = _query(2*treeNode, start, mid, l, r, k);
        int ans_right = _query(2*treeNode + 1, mid + 1, end, l, r, k);

        return ans_left + ans_right;
    }

    int query(int l, int r, int k) {
        return _query(1, 0, n - 1, l, r, k);
    }
};


// for q queries : return number of distinct elements in range(l, r)
class UniqueQueries {
public:
    int n;
    vector<int>arr;
    vector<vector<int>>tree;

    UniqueQueries(vector<int>&Arr) {
        n = Arr.size();
        arr = vector<int>(n, n);
        tree = vector<vector<int>>(4 * n + 10);
        map<int, int>next_occurence;
        for(int i = n - 1; i>= 0; i--) {
            if(next_occurence.count(Arr[i])) {
                arr[i] = next_occurence[Arr[i]];
            }
            next_occurence[Arr[i]] = i;
        }
        build(1, 0, n - 1);
    }

    vector<int>merge(const vector<int>&a, const vector<int>&b) {
        vector<int>res;
        int i = 0, j = 0;
        while(i < a.size() and j < b.size()) {
            if(a[i] < b[j]) res.push_back(a[i++]);
            else res.push_back(b[j++]);
        }

        while(i < a.size()) res.push_back(a[i++]);
        while(j < b.size()) res.push_back(b[j++]);

        return res;
    }

    void build(int treeNode, int start, int end) {
        if(start == end) {
            tree[treeNode].push_back(arr[start]);
            return;
        }

        int mid = start + (end - start) / 2;
        build(2*treeNode, start, mid);
        build(2*treeNode + 1, mid + 1, end);

        tree[treeNode] = merge(tree[2*treeNode], tree[2*treeNode + 1]);
    }

    int _query(int treeNode, int start, int end, int l, int r, int k) {
        if(start > r || end < l) return 0;
        if(start >= l and end <= r) {
            return tree[treeNode].end() - upper_bound(tree[treeNode].begin(), tree[treeNode].end(), k);
        }
        int mid = start + (end - start) / 2;
        int ans_left = _query(2*treeNode, start, mid, l, r, k);
        int ans_right = _query(2*treeNode + 1, mid + 1, end, l, r, k);

        return ans_left + ans_right;
    }

    int query(int l, int r) {
        return _query(1, 0, n - 1, l, r, r);
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