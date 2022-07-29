#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// Skyline Problem

struct SegtreeLazy {

    int n;
    vector<int>tree;
    vector<int>lazy;

    function<int(int, int)> merge;

    SegtreeLazy(int n, function<int(int, int)> merge) {
        this->n = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        this->merge = merge;
    }

    void update(int treeNode, int start, int end, int left, int right, int height) {
        if(lazy[treeNode] != 0) {
            tree[treeNode] = merge(tree[treeNode], lazy[treeNode]);
            if(start != end) {
                lazy[2 * treeNode] = merge(lazy[2 * treeNode], lazy[treeNode]);
                lazy[2 * treeNode + 1] = merge(lazy[2 * treeNode + 1], lazy[treeNode]);
            }
            lazy[treeNode] = 0;
        }
        if(start > right || end < left || start > end) return;
        if(start >= left && end <= right) {
            tree[treeNode] = merge(tree[treeNode], height);
            if(start != end) {
                lazy[2 * treeNode] = merge(lazy[2 * treeNode], height);
                lazy[2 * treeNode + 1] = merge(lazy[2 * treeNode + 1], height);
            }
            return;
        }

        int mid = start + (end - start) / 2;
        update(2 * treeNode, start, mid, left, right, height);
        update(2 * treeNode + 1, mid + 1, end, left, right, height);
    }

    int search(int treeNode, int start, int end, int idx) {
        if(lazy[treeNode] != 0) {
            tree[treeNode] = merge(tree[treeNode], lazy[treeNode]);
            if(start != end) {
                lazy[2 * treeNode] = merge(lazy[2 * treeNode], lazy[treeNode]);
                lazy[2 * treeNode + 1] = merge(lazy[2 * treeNode + 1], lazy[treeNode]);
            }
            lazy[treeNode] = 0;
        }
        if(start == end) return tree[treeNode];
        int mid = start + (end - start) / 2;
        if(idx <= mid) return search(2 * treeNode, start, mid, idx);
        else return search(2 * treeNode + 1, mid + 1, end, idx);
    }
    

};

class Solution {
public:

    map<int, int>compressed;
    map<int, int>de_compressed;
    set<int>coordinates;
    int timer = 0;

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        function<int(int, int)>merge = [](int a, int b) {
            return max(a, b);
        };

        for(auto &building: buildings) {
            int x = building[0], y = building[1];
            coordinates.insert(x);
            coordinates.insert(y);
        }
        timer = 0;
        for(auto &i: coordinates) {
            compressed[i] = timer++;
            de_compressed[timer - 1] = i;
        }

        SegtreeLazy segtree(timer, merge);

        for(auto &building: buildings) {
            int x = compressed[building[0]], y = compressed[building[1]];
            segtree.update(1, 0, timer - 1, x, y, building[2]);
        }

        vector<pair<int, int>>res;

        for(int i = 0; i<timer; i++) {
            res.push_back({i, segtree.search(1, 0, timer - 1, i)});
        }

        vector<vector<int>>ans;
        
        ans.push_back({de_compressed[res[0].first], res[0].second});

        for(int i = 1; i<res.size(); i++) {
            if(res[i].second != res[i - 1].second) {
                ans.push_back({de_compressed[res[i].first], res[i].second});
            }
        }

        return ans;

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