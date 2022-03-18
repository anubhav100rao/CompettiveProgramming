#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
  public:
    vector<vector<int>>dp;
    int solve(string &A, int i, int j) {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(A[i] == A[j])
            return dp[i][j] = 2 + solve(A, i+1, j-1);
        return dp[i][j] = max(solve(A, i+1, j), solve(A, i, j-1));
    }
    int longestPalinSubseq(string A) {
        int n = A.size();
        dp = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = 0; i<n; i++)
            dp[i][i] = 1;
       
       for(int len = 2; len <= n; len++) {
           for(int i = 0; i<n-len+1; i++) {
                int j = i + len - 1;
                if(A[i] == A[j] and len == 2) {
                    dp[i][j] = 2;
                } else if(A[i] == A[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
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