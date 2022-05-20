#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
public:
    int solve(string &str1, string &str2, int n, int m, vector<vector<int>>&dp) {
        if(m == 0)
            return 1;
        if(n == 0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(str1[n-1] == str2[m-1])
            return dp[n][m] = solve(str1, str2, n - 1, m - 1, dp) + solve(str1, str2, n - 1, m, dp);
        else
            return dp[n][m] = solve(str1, str2, n - 1, m, dp);
    }
    int countWays(string S1, string S2){
        // code here
        int n = S1.size(), m = S2.size();
        
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        return solve(S1, S2, n, m, dp);
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