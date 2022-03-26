#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution{
  public:	
	int distinctSubsequences(string str) {
        int n = str.size();
        const int mod = 1e9 + 7;
	    vector<long long>dp(n+1, 0);
        dp[0] = 1;
        vector<int>lst(500, -1);
        for(int i = 1; i<=n; i++) {
            dp[i] = dp[i-1] * 2;
            dp[i] %= mod;
            if(lst[str[i-1]] != -1) {
                dp[i] -= dp[lst[str[i-1]]];
                dp[i] = (dp[i] + mod) % mod;
            }
            lst[str[i-1]] = (i - 1);
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