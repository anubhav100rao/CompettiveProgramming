#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
public:
	// #define ll long long
	const int mod = 1e9 + 7;
    using ll = long long;
	ll countStrings(int n) {
	    // code here
	    vector<vector<ll>>dp(n+1, vector<ll>(2, 0));
	    dp[0][0] = 1;
	    dp[0][1] = 1;
	    
	    for(int i = 1; i<=n; i++) {
	        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
	        dp[i][1] = dp[i-1][0] % mod;
	    }
	    return dp[n][0];
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