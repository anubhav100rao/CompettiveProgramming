#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
	public:
		int LongestRepeatingSubsequence(string str) {
		    int n = str.size();
		    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
		    for(int i = 1; i<=n; i++) {
		        for(int j = 1; j<=n; j++) {
		            if(str[i-1] == str[j-1] and i!=j) {
		                dp[i][j] = 1 + dp[i-1][j-1];
		            } else {
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}
        int space_optimised(string str) {
            int n = str.size();
            vector<vector<int>>dp(2, vector<int>(n+1, 0));
            int idx = 0;
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