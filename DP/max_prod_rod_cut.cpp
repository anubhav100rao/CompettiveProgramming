#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
int dp[100];
int maxProductRodCutting(int n) {
    if(n <= 2)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    int ans = 0;
    for(int i = 1; i<n; i++) {
        ans = max({
            ans,
            i * (n - i),
            maxProductRodCutting(n - i) * i
        });
    }
    return dp[n] = ans;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    int n = 10;
    cout << maxProductRodCutting(n);
    return 0;
}