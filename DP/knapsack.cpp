#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<int>>memo;
int knapsack(int idx, int w, vector<int>&wt, vector<int>&val) {
    if(idx < 0) return 0;
    
    if(memo[idx][w] != -1)
        return memo[idx][w];

    int ans = knapsack(idx - 1, w, wt, val);
    if(wt[idx] <= w) {
        ans = max(ans, knapsack(idx - 1, w - wt[idx], wt, val) + val[idx]);
    }

    return memo[idx][w] = ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    int n, w; cin >> n >> w;
    vector<int>wt(n), val(n);
    for(int i = 0; i<n; i++)
        cin >> wt[i];
    for(int i = 0; i<n; i++)
        cin >> val[i];
    
    memo = vector<vector<int>>(n + 1, vector<int>(w + 1, -1));

    cout << knapsack(n-1, w, wt, val) << "\n";

    vector<vector<int>>dp(n+1, vector<int>(w + 1, 0));

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=w; j++) {
            dp[i][j] = dp[i-1][j];
            if(wt[i-1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-wt[i-1]] + val[i-1]);
            }
        }
    }

    cout << dp[n][w] << "\n";

    return 0;
}