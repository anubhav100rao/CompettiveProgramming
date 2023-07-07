#include <bits/stdc++.h> 
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif



#define debug(...) 42
class SegmentTreeMin{
    /*************************
        *take n input and just call st.init(n)
        *start => 0
        *end => arr.size() - 1
        *treesize = 4*arr.size()
        *treeNode = 1
    *************************/
public:
    int size;
    vector<int>tree;
    vector<int>arr;

    SegmentTreeMin(int n, vector<int>A) {
        size = n;
        this->arr = A;
        tree.assign(4*size, 0);
        build(1, 0, size -1);
    }

    void build(int treeNode, int start, int end) {
        if(start == end) {
            tree[treeNode] = arr[start];
            return;
        }
        int mid = start + (end - start)/2;
        build(treeNode*2, start, mid);
        build(treeNode*2 + 1, mid+1, end);
        tree[treeNode] = min(tree[treeNode*2], tree[treeNode*2 + 1]);
    }

    int sum(int treeNode, int start, int end, int left, int right) {
        if(start > right || end < left) return 0;

        if(start >= left && end <= right) {
            return tree[treeNode];
        }

        int mid = start + (end - start)/2;
        int ans_left = sum(treeNode*2, start, mid, left, right);
        int ans_right = sum(treeNode*2 + 1, mid+1, end, left, right);
        return (ans_left + ans_right);
    }

    int query(int start, int end, int treeNode, int left, int right) {
        if(start > right || end < left) {
            return INT_MAX;
        }
        if(start >= left && end <= right) {
            return tree[treeNode];
        }
        int mid = (start + end) / 2;
        int ans1 = query(start, mid, 2*treeNode, left, right);
        int ans2 = query(mid+1, end, 2*treeNode+1, left, right);
        return min(ans1, ans2);
    }

    int query(int left, int right) {
        return query(0, arr.size() - 1, 1, left, right);
    }

    void update(int treeNode, int start, int end, int idx, int val) {
        if(start == end) {
            arr[idx] = val;
            tree[treeNode] = val;
            return;
        }

        int mid = start + (end - start)/2;
        if(idx > mid) {
            update(treeNode*2 + 1, mid+1, end, idx, val);
        } else {
            update(treeNode*2, start, mid, idx, val);
        }
        tree[treeNode] = tree[treeNode*2] + tree[treeNode*2 + 1];
    }
};

class SegmentTreeSum{
    /*************************
        *take n input and just call st.init(n)
        *start => 0
        *end => arr.size() - 1
        *treesize = 4*arr.size()
        *treeNode = 1
    *************************/
public:
    int size;
    vector<int>tree;
    vector<int>arr;

    SegmentTreeSum(int n) {
        size = n;
        arr.resize(n, 0);
        tree.assign(4*size, 0);
        build(1, 0, size -1);
    }

    void build(int treeNode, int start, int end) {
        if(start == end) {
            tree[treeNode] = arr[start];
            return;
        }
        int mid = start + (end - start)/2;
        build(treeNode*2, start, mid);
        build(treeNode*2 + 1, mid+1, end);
        tree[treeNode] = tree[treeNode*2] + tree[treeNode*2 + 1];
    }

    int sum(int treeNode, int start, int end, int left, int right) {
        if(start > right || end < left) return 0;

        if(start >= left && end <= right) {
            return tree[treeNode];
        }

        int mid = start + (end - start)/2;
        int ans_left = sum(treeNode*2, start, mid, left, right);
        int ans_right = sum(treeNode*2 + 1, mid+1, end, left, right);
        return (ans_left + ans_right);
    }

    int query(int start, int end, int treeNode, int left, int right) {
        if(start > right || end < left) {
            return 0;
        }
        if(start >= left && end <= right) {
            return tree[treeNode];
        }
        int mid = (start + end) / 2;
        int ans1 = query(start, mid, 2*treeNode, left, right);
        int ans2 = query(mid+1, end, 2*treeNode+1, left, right);
        return (ans1 + ans2);
    }

    int query(int left, int right) {
        return sum(1, 0, size - 1, left, right);
    }

    void update(int treeNode, int start, int end, int idx, int val) {
        if(start == end) {
            tree[treeNode] += val;
            return;
        }

        int mid = start + (end - start)/2;
        if(idx > mid) {
            update(treeNode*2 + 1, mid+1, end, idx, val);
        } else {
            update(treeNode*2, start, mid, idx, val);
        }
        tree[treeNode] = tree[treeNode*2] + tree[treeNode*2 + 1];
    }

    void update(int idx, int val) {
        update(1, 0, arr.size() - 1, idx, val);
    }
};
class Solution {
public:



    int minNumberOperations(vector<int>& target) {
        
        map<int, vector<int>>occur;

        function<int(int,int)>sum_lambda = [](int a, int b) {
            return a + b;
        };

        function<int(int,int)>min_lambda = [](int a, int b) {
            return min(a, b);
        };


        int n = target.size();
        for(int i = 0; i < n; i++)
            occur[target[i]].push_back(i);

        debug(occur);

        SegmentTreeMin min_segtree(n, target);
        SegmentTreeSum sum_segtree(n);


        int res = 0;

        auto solve = [&](const int left, const int right) -> vector<pair<int, int>> {


            if(left > right) return {};
            int mn = min_segtree.query(left, right);
            int before = sum_segtree.query(0, left);

          
            int need = mn - before;

            debug(left, right); debug(mn); debug(before);
            assert(left >= 0 and right < n and left <= right);
            // assert(sum_segtree.query(0, n - 1) == 0);

            sum_segtree.update(left, need);
            if(right + 1 < n)
                sum_segtree.update(right + 1, -need);

            res += need;

            vector<pair<int, int>>sub;


            int l = left, r = right;

            if(l > r) return sub;

 
            
            int left_index = lower_bound(occur[mn].begin(), occur[mn].end(), left) - occur[mn].begin();
            int right_index = prev(upper_bound(occur[mn].begin(), occur[mn].end(), right)) - occur[mn].begin();
         



            for(int i = left_index; i <= right_index; i++) {

                int curr = occur[mn][i];
               

                assert(curr >= 0 and curr < n);

                if(curr - 1 >= l) {
                    sub.push_back({l, curr - 1});
                    l = curr + 1;
                } else {
                    l = curr + 1;
                }

            }

            if(l <= r) {
                sub.push_back({l, r});
            }

            debug(res);
            debug(sub); cerr <<"\n\n";
            return sub;
        };

        vector<pair<int, int>>ranges ={{0, n - 1}};
        while(true) {

            vector<pair<int, int>>next_layer;

            for(auto [l, r]: ranges) {
                vector<pair<int, int>>sub = solve(l, r);
                for(auto p: sub)
                    next_layer.push_back(p);
                
            }

            if(next_layer.empty()) break;

            ranges = next_layer;
        }

        return res;

    }
};

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif

    vector<int>arr = {3, 1, 1, 2};

    Solution sol;

    cout << sol.minNumberOperations(arr);
}include <bits/stdc++.h> 
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif



#define debug(...) 42
class SegmentTreeMin{
    /*************************
        *take n input and just call st.init(n)
        *start => 0
        *end => arr.size() - 1
        *treesize = 4*arr.size()
        *treeNode = 1
    *************************/
public:
    int size;
    vector<int>tree;
    vector<int>arr;

    SegmentTreeMin(int n, vector<int>A) {
        size = n;
        this->arr = A;
        tree.assign(4*size, 0);
        build(1, 0, size -1);
    }

    void build(int treeNode, int start, int end) {
        if(start == end) {
            tree[treeNode] = arr[start];
            return;
        }
        int mid = start + (end - start)/2;
        build(treeNode*2, start, mid);
        build(treeNode*2 + 1, mid+1, end);
        tree[treeNode] = min(tree[treeNode*2], tree[treeNode*2 + 1]);
    }

    int sum(int treeNode, int start, int end, int left, int right) {
        if(start > right || end < left) return 0;

        if(start >= left && end <= right) {
            return tree[treeNode];
        }

        int mid = start + (end - start)/2;
        int ans_left = sum(treeNode*2, start, mid, left, right);
        int ans_right = sum(treeNode*2 + 1, mid+1, end, left, right);
        return (ans_left + ans_right);
    }

    int query(int start, int end, int treeNode, int left, int right) {
        if(start > right || end < left) {
            return INT_MAX;
        }
        if(start >= left && end <= right) {
            return tree[treeNode];
        }
        int mid = (start + end) / 2;
        int ans1 = query(start, mid, 2*treeNode, left, right);
        int ans2 = query(mid+1, end, 2*treeNode+1, left, right);
        return min(ans1, ans2);
    }

    int query(int left, int right) {
        return query(0, arr.size() - 1, 1, left, right);
    }

    void update(int treeNode, int start, int end, int idx, int val) {
        if(start == end) {
            arr[idx] = val;
            tree[treeNode] = val;
            return;
        }

        int mid = start + (end - start)/2;
        if(idx > mid) {
            update(treeNode*2 + 1, mid+1, end, idx, val);
        } else {
            update(treeNode*2, start, mid, idx, val);
        }
        tree[treeNode] = tree[treeNode*2] + tree[treeNode*2 + 1];
    }
};

class SegmentTreeSum{
    /*************************
        *take n input and just call st.init(n)
        *start => 0
        *end => arr.size() - 1
        *treesize = 4*arr.size()
        *treeNode = 1
    *************************/
public:
    int size;
    vector<int>tree;
    vector<int>arr;

    SegmentTreeSum(int n) {
        size = n;
        arr.resize(n, 0);
        tree.assign(4*size, 0);
        build(1, 0, size -1);
    }

    void build(int treeNode, int start, int end) {
        if(start == end) {
            tree[treeNode] = arr[start];
            return;
        }
        int mid = start + (end - start)/2;
        build(treeNode*2, start, mid);
        build(treeNode*2 + 1, mid+1, end);
        tree[treeNode] = tree[treeNode*2] + tree[treeNode*2 + 1];
    }

    int sum(int treeNode, int start, int end, int left, int right) {
        if(start > right || end < left) return 0;

        if(start >= left && end <= right) {
            return tree[treeNode];
        }

        int mid = start + (end - start)/2;
        int ans_left = sum(treeNode*2, start, mid, left, right);
        int ans_right = sum(treeNode*2 + 1, mid+1, end, left, right);
        return (ans_left + ans_right);
    }

    int query(int start, int end, int treeNode, int left, int right) {
        if(start > right || end < left) {
            return 0;
        }
        if(start >= left && end <= right) {
            return tree[treeNode];
        }
        int mid = (start + end) / 2;
        int ans1 = query(start, mid, 2*treeNode, left, right);
        int ans2 = query(mid+1, end, 2*treeNode+1, left, right);
        return (ans1 + ans2);
    }

    int query(int left, int right) {
        return sum(1, 0, size - 1, left, right);
    }

    void update(int treeNode, int start, int end, int idx, int val) {
        if(start == end) {
            tree[treeNode] += val;
            return;
        }

        int mid = start + (end - start)/2;
        if(idx > mid) {
            update(treeNode*2 + 1, mid+1, end, idx, val);
        } else {
            update(treeNode*2, start, mid, idx, val);
        }
        tree[treeNode] = tree[treeNode*2] + tree[treeNode*2 + 1];
    }

    void update(int idx, int val) {
        update(1, 0, arr.size() - 1, idx, val);
    }
};
class Solution {
public:



    int minNumberOperations(vector<int>& target) {
        
        map<int, vector<int>>occur;

        function<int(int,int)>sum_lambda = [](int a, int b) {
            return a + b;
        };

        function<int(int,int)>min_lambda = [](int a, int b) {
            return min(a, b);
        };


        int n = target.size();
        for(int i = 0; i < n; i++)
            occur[target[i]].push_back(i);

        debug(occur);

        SegmentTreeMin min_segtree(n, target);
        SegmentTreeSum sum_segtree(n);


        int res = 0;

        auto solve = [&](const int left, const int right) -> vector<pair<int, int>> {


            if(left > right) return {};
            int mn = min_segtree.query(left, right);
            int before = sum_segtree.query(0, left);

          
            int need = mn - before;

            debug(left, right); debug(mn); debug(before);
            assert(left >= 0 and right < n and left <= right);
            // assert(sum_segtree.query(0, n - 1) == 0);

            sum_segtree.update(left, need);
            if(right + 1 < n)
                sum_segtree.update(right + 1, -need);

            res += need;

            vector<pair<int, int>>sub;


            int l = left, r = right;

            if(l > r) return sub;

 
            
            int left_index = lower_bound(occur[mn].begin(), occur[mn].end(), left) - occur[mn].begin();
            int right_index = prev(upper_bound(occur[mn].begin(), occur[mn].end(), right)) - occur[mn].begin();
         



            for(int i = left_index; i <= right_index; i++) {

                int curr = occur[mn][i];
               

                assert(curr >= 0 and curr < n);

                if(curr - 1 >= l) {
                    sub.push_back({l, curr - 1});
                    l = curr + 1;
                } else {
                    l = curr + 1;
                }

            }

            if(l <= r) {
                sub.push_back({l, r});
            }

            debug(res);
            debug(sub); cerr <<"\n\n";
            return sub;
        };

        vector<pair<int, int>>ranges ={{0, n - 1}};
        while(true) {

            vector<pair<int, int>>next_layer;

            for(auto [l, r]: ranges) {
                vector<pair<int, int>>sub = solve(l, r);
                for(auto p: sub)
                    next_layer.push_back(p);
                
            }

            if(next_layer.empty()) break;

            ranges = next_layer;
        }

        return res;

    }
};

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif

    vector<int>arr = {3, 1, 1, 2};

    Solution sol;

    cout << sol.minNumberOperations(arr);
}
