#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
    public:
    int knapSack(int w, int wt[], int val[], int n) { 
        vector<vector<int>>dp(n+1, vector<int>(w+1, 0));
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=w; j++) {
                dp[i][j] = dp[i-1][j];
                if(wt[i-1] <= j) {
                    dp[i][j] = max(
                            dp[i][j],
                            dp[i-1][j-wt[i-1]] + val[i-1]
                        );
                }
            }
        }
        return dp[n][w];
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