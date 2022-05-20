#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

int solve(vector<vector<vector<int>>>&arr) {
    int l = arr.size();
    int m = arr[0].size();
    int n = arr[0][0].size();

    vector<vector<vector<int>>>dp(l, vector<vector<int>>(m, vector<int>(n, 0)));

    dp[0][0][0] = arr[0][0][0];
    for(int i = 1; i<l; i++)
        dp[i][0][0] = dp[i-1][0][0] + arr[i][0][0];
    for(int i = 1; i<m; i++)
        dp[0][i][0] = dp[0][i-1][0] + arr[0][i][0];
    for(int i = 1; i<n; i++)
        dp[0][0][i] = dp[0][0][i-1] + arr[0][0][i];

    for(int i = 1; i<l; i++)
        for(int j = 1; j<m; j++)
            dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0]) + arr[i][j][0];

    for(int i = 1; i<l; i++)
        for(int k = 1; k<n; k++)
            dp[i][0][k] = min(dp[i-1][0][k], dp[i][0][k-1]) + arr[i][0][k];

    for(int j = 1; j<m; j++)
        for(int k = 1; k<n; k++)
            dp[0][j][k] = min(dp[0][j-1][k], dp[0][j][k-1]) + arr[0][j][k];

    for(int i = 1; i<l; i++)
        for(int j = 1; j<m; j++)
            for(int k = 1; k<n; k++)
                dp[i][j][k] = min({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]}) + arr[i][j][k];
    return dp[l-1][m-1][n-1];
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    vector<vector<vector<int>>>arr = { { {1, 2, 4}, {3, 4, 5}, {5, 2, 1}},
    { {4, 8, 3}, {5, 2, 1}, {3, 4, 2}},
    { {2, 4, 1}, {3, 1, 4}, {6, 3, 8}}
  };
    cout << solve(arr); 
    return 0;
}