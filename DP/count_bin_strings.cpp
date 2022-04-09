#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    int countStrings(int n, int k) {
        //code here.
        const int mod = 1e9 + 7;
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
    
        for(int i = 2; i<=n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
                dp[i][j][1] = dp[i-1][j][0];
                if(j - 1 >= 0) {
                    dp[i][j][1] += dp[i-1][j-1][1];
                    dp[i][j][1] %= mod;
                }
            }
        }
        return (dp[n][k][0] + dp[n][k][1]) % mod;
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