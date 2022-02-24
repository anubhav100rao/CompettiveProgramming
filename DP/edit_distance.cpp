#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
  public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>>&dp) {
        if(i == 0)
            return j;
        if(j == 0)
            return i;
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        return dp[i][j] = (s[i-1] == t[j-1]) ? solve(s, t, i-1, j-1, dp) :
                                1 + min({
                                    solve(s, t, i-1, j-1, dp),
                                    solve(s, t, i-1, j, dp),
                                    solve(s, t, i, j-1, dp)
                                });
    }
    int editDistance(string s, string t) {
        // Code here
        int n = s.size(), m = t.size();
        const int inf = 1e9;
        vector<vector<int>>dp(n+1, vector<int>(m+1, inf));
        for(int i = 0; i<=n; i++) {
            for(int j = 0; j<=m; j++) {
                if(i == 0) {
                    dp[i][j] = j;
                } else if(j == 0) {
                    dp[i][j] = i;
                } else {
                    if(s[i-1] == t[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = 1 + min({
                            dp[i-1][j-1],
                            dp[i-1][j],
                            dp[i][j-1]
                        });
                    }
                }
            }
        }
        return dp[n][m];
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