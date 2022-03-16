#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int maxRevenue(int m, int position[], int revenue[], int n, int t) {
    vector<int>dp(m+1, 0);
    int next_point = 0;
    for(int i = 1; i<=m; i++) {
        if(next_point < n) {
            if(position[next_point] == i) {
                if(i <= t) {
                    dp[i] = max(dp[i-1], revenue[next_point]);
                } else {
                    dp[i] = max(dp[i-1], dp[i-t] + revenue[next_point]);
                }
                next_point++;
            } else {
                dp[i] = dp[i-1];
            }
        } else {
            dp[i] = dp[i-1];
        }
    }
    return dp[m];
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