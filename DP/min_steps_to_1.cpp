#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution{
    const int inf = 1e9;
	public:
	int solve(int n, vector<int>&dp) {
	    if(n <= 1) return 0;
	    if(dp[n] != -1) return dp[n];
	    return dp[n] = 1 + min({
	       solve(n-1, dp),
	       (n % 2 == 0) ? solve(n/2, dp): inf,
	       (n % 3 == 0) ? solve(n/3, dp): inf
	    });
	}
	int minSteps(int n) { 
	    // Your code goes here
	    vector<int>dp(n+1, inf);
	    dp[0] = dp[1] = 0;
	    for(int i = 2; i<=n; i++) {
	           if(i % 2 == 0) {
	               dp[i] = min(dp[i], dp[i/2] + 1);
	           }
	           if(i % 3 == 0) {
	               dp[i] = min(dp[i], dp[i/3] + 1);
	           }
	           dp[i] = min(dp[i], dp[i-1] + 1);
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