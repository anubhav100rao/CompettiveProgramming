#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        /**
         * we fill our dp column wise
         * dp[i][j] = M[i][j] + max({dp[i][j-1], dp[i-1][j-1], dp[i+1][j-1]});
        */
       
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++) {
            dp[i][0] = M[i][0];
        }
        
        if(n == 1) {
            int ans = 0;
            for(int i = 0; i<m; i++) ans += M[0][i];
            return ans;
        }
        
        for(int j = 1; j<m; j++) {
            for(int i = 0; i<n; i++) {
                if(i == 0) {
                    dp[i][j] = M[i][j] + max(dp[i][j-1], dp[i+1][j-1]);
                } else if(i == n-1) {
                    dp[i][j] = M[i][j] + max(dp[i][j-1], dp[i-1][j-1]);
                } else {
                    dp[i][j] = M[i][j] + max(dp[i][j-1], max(dp[i+1][j-1], dp[i-1][j-1]));
                }
            }
        }
        int ans = dp[0][0];
        for(int i = 0; i<n; i++) {
            ans = max(ans, dp[i][m-1]);
        }
        return ans;
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