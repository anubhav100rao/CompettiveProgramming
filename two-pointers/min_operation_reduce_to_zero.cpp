#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    /**
     * first we try brute dfs min(solve(nums, s+1, e, x - nums[s]) + 1, solve(nums, s, e-1, x - nums[e]) + 1)
     * this leads to tle
     * then we tried instead of finding min pre + suffix == x
     * we should try to find max subarray such its sum is TOTAL_SUM - X
     * we maintained a hash map for this and coded
    */
    int solve(vector<int>&nums, int s, int e, int x) {
        if(x == 0) return 0;
        if(x < 0) return 1e6;
        if(s > e) return 1e6;

        return min(solve(nums, s+1, e, x - nums[s]) + 1, solve(nums, s, e-1, x - nums[e]) + 1);

    }
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size();
        
        int res = INT_MAX;

        unordered_map<int, int>suff = {{0, n}};
        int s = 0;
        for(int i = n-1; i>=0; i--)
            s += arr[i], suff[s] = i;
        s = 0;
        if(suff.count(x))
            res = min(res, n - suff[x]);
        for(int i = 0; i<n; i++) {
            s += arr[i];
            if(s == x) res = min(res, i + 1);
            if(suff.count(x - s) and suff[x - s] > i)
                res = min(res, i + 1 + n - suff[x - s]);
        }

        return res == INT_MAX ? -1 : res;
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