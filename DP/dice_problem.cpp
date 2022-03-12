#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    long long go(int n, int m, int x, vector<vector<long long>>&dp) {
        if(n == 0) {
            if(x == 0)
                return 1;
            else
                return 0;
        }
        if(x < 0)
            return 0;
        if(dp[n][x] != -1)
            return dp[n][x];
        long long res = 0;
        for(int i = 1; i<=min(m, x); i++) {
            res += go(n-1, m, x-i, dp);
        }
        return dp[n][x] = res;
    }
    /*
    n dice
    m different values from 1..m
    we to make sum x
    */
    long long numberOfWays(int n, int m, int x) {
        vector<vector<long long>>dp(n+1, vector<long long>(x+1, 0LL));
        dp[0][0] = 1LL;
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=x; j++) {
                for(int k = 1; k<=min(m, j); k++) {
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        return dp[n][x];
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