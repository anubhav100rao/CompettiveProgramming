#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
	public:
	int maximumDifferenceSum(int arr[], int n) { 
	    vector<vector<int>>dp(n, vector<int>(2, 0));
        for(int i = 1; i<n; i++) {
            // dp[i][0] -> represents when I use the actual value of arr[i]
            dp[i][0] = max(dp[i-1][0] + abs(arr[i-1] - arr[i]), dp[i-1][1] + abs(arr[i] - 1));

            // dp[i][1] -> represents when I replace arr[i] with 1
            dp[i][1] = max(dp[i-1][0] + abs(arr[i-1] - 1), dp[i-1][1]);
        }

        return max(dp[n-1][0], dp[n-1][1]);
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