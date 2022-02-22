#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution
{
    public:
        int solve(int n, vector<int>&dp) {
            if(n < 2) return n;
            if(dp[n] != -1) {
                return dp[n];
            }
            return dp[n] = max(n, solve(n/2, dp) + solve(n/3, dp) + solve(n/4, dp));
        }
        int maxSum(int n)
        {
            vector<int>dp(n+1, 0);
            // return solve(n, dp);
            
            for(int i = 1; i<=n; i++) {
                dp[i] = i;
                dp[i] = max(dp[i], dp[i/2] + dp[i/3] + dp[i/4]);    
            }
            return dp[n];
            
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