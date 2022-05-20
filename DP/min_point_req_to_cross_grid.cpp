#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{

    public:

    int minPoints(vector<vector<int>> points, int n, int m) 
    { 
        // Your code goes here
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[n-1][m-1] = points[n-1][m-1] > 0 ? 1 : abs(points[n-1][m-1]) + 1;


        for(int i = m-2; i>=0; i--)
            dp[n-1][i] = max(dp[n-1][i+1] - points[n-1][i], 1);
        for(int i = n-2; i>=0; i--)
            dp[i][m-1] = max(dp[i+1][m-1] - points[i][m-1], 1);

        for(int i = n-2; i>=0; i--) {
            for(int j = m - 2; j >= 0; j--) {
                int nex = max(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(nex - points[i][j], 1);
            }
        }
        return dp[0][0];
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