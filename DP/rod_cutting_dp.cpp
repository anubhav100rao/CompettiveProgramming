#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int>dp(n+1, 0);
        dp[0] = 0;
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=i; j++) {
                dp[i] = max(dp[i], dp[i-j] + price[j-1]);
            }
        }
        return dp[n];
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