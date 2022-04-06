#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {

	public:
	int findWinner(int n, int x, int y) {

		vector<bool>dp(n + 1, false);
		for(int i = 1; i<=n; i++) {
		    dp[i] = !dp[i-1] || dp[i];
		    if(i >= x)
		        dp[i] = !dp[i-x] || dp[i];
		    
		    if(i >= y)
		        dp[i] = !dp[i-y] || dp[i];
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