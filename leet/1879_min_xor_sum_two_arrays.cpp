#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
    int n, tot;
    vector<int>dp;
    vector<vector<int>>pre;
public:

    long long int solve(int idx, int mask) {
        if(idx >= n) return 0;

        if(dp[mask] != -1)
            return dp[mask];

        long long int ans = INT_MAX;

        for(int i = 0; i<n; i++) {
            if(mask & (1 << i)) { // if this number is present
                ans = min(ans, pre[idx][i] + solve(idx+1, (mask ^ (1 << i))));
            }
        }

        return dp[mask] = ans;
        
    }


    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        tot = (1 << n) - 1;
        dp = vector<int>(tot + 1, -1);
        pre = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                pre[i][j] = nums1[i] ^ nums2[j];
            }
        }
        return solve(0, tot);
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