#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {

public:
	const int mod = 1e9 + 7;
	
	int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        vector<vector<int>>dp(n+1, vector<int>(sum + 1, 0));
        for(int i = 0; i<=n; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i<=n; i++) {
            for(int j = 0; j<=sum; j++) {
                dp[i][j] = dp[i-1][j];
                if(arr[i-1] <= j) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-arr[i-1]]) % mod;
                }
            }
        }
        return dp[n][sum];
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