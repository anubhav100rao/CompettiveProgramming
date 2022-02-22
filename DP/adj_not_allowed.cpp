#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution{
public:
    int maxSum(int n, vector<vector<int>> mat)
    {
        vector<int>dp(n, 0);
        dp[0] = max(mat[0][0], mat[1][0]);
        if(n == 1) return dp[0];
        dp[1] = max(max(mat[0][1], mat[1][1]), dp[0]);
        for(int i = 2; i<n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + max(mat[0][i], mat[1][i]));
        }
        return dp[n-1];
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