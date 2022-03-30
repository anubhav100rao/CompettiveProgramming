#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    vector<int>distinctSubsetSums(vector<int>nums) {
        int n = nums.size();
        int sm = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>>dp(n+1, vector<bool>(sm + 1, false));

        for(int i = 0; i<=n; i++)
            dp[i][0] = true;
        
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=sm; j++) {
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        vector<int>ans;
        for(int i = 0; i<=sm; i++) {
            if(dp[n][i]) {
                ans.push_back(i);
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