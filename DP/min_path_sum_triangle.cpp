#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    int minPathSum(vector<vector<int>>&triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n);
        dp[n-1] = vector<int>(triangle[n-1].size(), 0);
        for(int i = 0; i<triangle[n-1].size(); i++) {
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i = n-2; i>=0; i--) {
            dp[i] = vector<int>(triangle[i].size(), 0);
            for(int j = 0; j<triangle[i].size(); j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
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
    Solution sol;
    vector<vector<int>> A { { 2 },
                            { 3, 9 },
                            { 1, 6, 7 } };
    cout << sol.minPathSum(A);
    return 0;
}