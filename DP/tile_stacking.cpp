#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int tile_stacking(int n, int m, int k) {
    if(n < 0 || m < 0)
        return 0;
    if(n == 0)
        return 1;
    int res = 0;
    for(int i = 0; i<=k; i++) {
        res += tile_stacking(n-i, m-1, k);
    }
    return res;
}

int tile_stacking_dp(int n, int m, int k) {
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i<=m; i++) {
        dp[0][i] = 1;
    }
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            for(int l = 0; l<=k; l++) {
                if(i >= l)
                    dp[i][j] += dp[i-l][j-1];
                else break;
            }
        }
    }
    return dp[n][m];
}

int tile_stacking_optimised(int n, int m, int k) {
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    vector<vector<int>>pre(m+1, vector<int>(n+1, 0));

    for(int i = 1; i<=n; i++) {
        pre[0][i] = 1;
    } 
    for(int i = 0; i<=m; i++) {
        dp[i][0] = 1;
        pre[i][0] = 1;
    }

    for(int i = 1; i<=m; i++) {
        for(int j = 1; j<=n; j++) {
            dp[i][j] = pre[i-1][j];
            if(j > k) {
                dp[i][j] -= pre[i-1][j-k-1];
            }
        }
        for(int j = 1; j<=n; j++) {
            pre[i][j] = dp[i][j] + pre[i][j-1];
        }
    }
   
    return dp[m][n];
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 3, m = 3, k = 2;
    cout << tile_stacking(n, m, k) << '\n';
    cout << tile_stacking_dp(n, m, k) << '\n';
    cout << tile_stacking_optimised(n, m, k) << '\n';
   
    return 0;
}