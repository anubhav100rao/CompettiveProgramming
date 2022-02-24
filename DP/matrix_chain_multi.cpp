#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    // i = 1, j = n-1
    int matrix_chain_recur(vector<int>&p, int i, int j, vector<vector<int>>&dp) {
        if(i >= j) return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = INT_MAX;
        for(int k = i; k<j; k++) {
            int curr =  matrix_chain_recur(p, i, k, dp)
                        + matrix_chain_recur(p, k+1, j, dp)
                        + p[i-1] * p[k] * p[j];
            dp[i][j] = min(dp[i][j], curr);
        }
        return dp[i][j];
    }
    int matrix_chain_memo(vector<int>&p) {
        int n = p.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return matrix_chain_recur(p, 1, n-1, dp);
    }

    int matrix_chain_dp(vector<int>&p) {
        int n = p.size();
        const int inf = 1e9;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int len = 2; len < n; len++) {
            for(int i = 1; i<n-len+1; i++) {
                int j = i + len - 1;
                dp[i][j] = inf;
                for(int k = i; k<j; k++) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]
                    );
                }
            }
        }
        return dp[1][n-1];
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