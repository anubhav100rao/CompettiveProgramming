#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int max_square_matrix(vector<vector<int>>&matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>>dp(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++) dp[i][0] = matrix[i][0];
    for(int i = 0; i<m; i++) dp[0][i] = matrix[0][i];

    for(int i = 1; i<n; i++) {
        for(int j = 1; j<m; j++) {
            if(matrix[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}


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