#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    int maxPathSum(vector<vector<int>>&triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i = 0; i<m; i++) dp[n-1][i] = triangle[n-1][i];
        int row_up = 1;
        for(int i = n-2; i>=0; i--) {
            for(int j = 0; j<m - row_up; j++) {
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
            row_up++;
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
    vector<vector<int>>triangle = {  {1, 0, 0},
                      {4, 8, 0},
                      {1, 5, 3} };
    Solution sol;
    cout << sol.maxPathSum(triangle);
    return 0;
}