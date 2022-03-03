#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n) {

        const int mod = 1e9 + 7;
        vector<int>dp(n+1, 0); dp[0] = 1;
        for(int i = 1; i<=n; i++) {
            if(i >= 1) (dp[i] += dp[i-1]) %= mod;
            if(i >= 2) (dp[i] += dp[i-2]) %= mod;
            if(i >= 3) dp[i] += dp[i-3];
            dp[i] %= mod;
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