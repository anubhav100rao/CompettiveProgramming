#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution
{
public:
    const int mod = 1e9 + 7;
    int solve(int x, int y, vector<vector<int>>&dp) {
        if(x == 0 || y == 0)
            return 1;
        if(dp[x][y] != -1)
            return dp[x][y];
        return dp[x][y] = (solve(x - 1, y, dp) + solve(x, y-1, dp)) % mod;
    }
    int ways(int x, int y)
    {
        //code here.
        vector<vector<int>>dp(x+1, vector<int>(y+1, -1));
        return solve(x, y, dp);
    }

    int ways_dp(int x, int y) {
        vector<vector<int>>dp(x+1, vector<int>(y+1, 0));
        for(int i = 0; i<=x; i++)
            dp[i][0] = 1;
        for(int i = 0; i<=y; i++)
            dp[0][i] = 1;
        for(int i = 1; i<=x; i++) {
            for(int j = 1; j<=y; j++) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
        return dp[x][y];
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