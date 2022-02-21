#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    double maxAvgPath(vector<vector<int>>&matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[0][0] = matrix[0][0];
        for(int i = 1; i<m; i++) dp[0][i] = dp[0][i-1] + matrix[0][i];
        for(int i = 1; i<n; i++) dp[i][0] = dp[i-1][0] + matrix[i][0];
        
        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                dp[i][j] = matrix[i][j] + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return (double) dp[n-1][m-1] / (n + m - 1.0);
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