#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{

    public:
    int findMinCost(string X, string Y, int costX, int costY)
    {
        // Your code goes here
        int n = X.size(), m = Y.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                if(X[i-1] == Y[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return (n - dp[n][m]) * costX + (m - dp[n][m]) * costY;
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