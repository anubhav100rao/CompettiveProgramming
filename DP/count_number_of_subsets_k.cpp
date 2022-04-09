#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int count_subsets(int n, int k) {
    if(n == 0 || k == 0 || k > n)
        return 0;
    if(k == 1 || k == n)
        return 1; // compelete set and divide set elements into 1
    return k * count_subsets(n - 1, k) + count_subsets(n - 1, k - 1);
}

int solve(int n, int k) {
    vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=k; j++) {
            if(i == j || j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = j * dp[i-1][j] + dp[i-1][j-1];
        }
    }
    return dp[n][k];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    int n, k; cin >> n >> k;
    cout << count_subsets(n, k) << '\n';
    cout << solve(n, k) << '\n';
    return 0;
}