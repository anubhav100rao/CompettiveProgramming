#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        // code here
        long long sm = accumulate(tree, tree + n, 0LL);
        if(sm < k) {
            return -1;
        }
        
        int l = 0, r = *max_element(tree, tree + n);
        int res = l;
        while(r - l >= 0) {
            int mid = l + (r - l) / 2;
            int curr = 0;
            for(int i = 0; i<n; i++) {
                if(tree[i] >= mid) {
                    curr += (tree[i] - mid);
                }
            }
            if(curr > k) {
                l = mid + 1;
            } else {
                res = mid;
                r = mid - 1;
            }
        }
        // cout << l << ' ' << r << '\n';
        sm = 0;
        for(int i = 0; i<n; i++) {
            if(tree[i] >= res) sm += tree[i] - res;
        }
        if(sm != k) return -1;
        return res;
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