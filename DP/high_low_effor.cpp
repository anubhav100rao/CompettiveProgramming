#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
    public:
        int maxAmt(int n , int hi[] , int li[]) {
            int dp[n+1];
            for(int i = 0; i<=n; i++)
                dp[i] = 0;
            dp[1] = max(hi[0], li[0]);
            
            for(int i = 2; i<=n; i++) {
                dp[i] = max(dp[i-1] + li[i-1], dp[i-2] + hi[i-1]);
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