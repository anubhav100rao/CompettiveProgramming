#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {

	public:
	int minCoins(int coins[], int n, int target) { 
	    const int inf = 1e9;
	    vector<long long>dp(target + 1, inf);
	    dp[0] = 0LL;
	    for(int i = 1; i<=target; i++) {
	        for(int j = 0; j<n; j++) {
	            if(coins[j] <= i) {
	                if(dp[i - coins[j]] != inf) {
	                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
	                }
	            }
	        }
	    }
        
	    return (dp[target] >= inf) ? -1: dp[target];
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