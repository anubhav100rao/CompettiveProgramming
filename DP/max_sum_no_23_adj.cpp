#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n, 0);
	    dp[0] = arr[0];
	    if(n == 1) {
	        return arr[0];
	    }
	    dp[1] = max(arr[0], arr[1]);
	    
	    for(int i = 2; i<n; i++) {
	        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
	    }
	    return dp[n-1];
	}
	int findMaxNo3Adj(vector<int>&arr) {
		int n = arr.size();
		vector<int>dp(n, 0);
		dp[0] = arr[0];
		dp[1] = dp[0] + arr[1];
		for(int i = 2; i<n; i++) {
			dp[i] = max(dp[i], dp[i-1]); // exclude arr[i]
			dp[i] = max(dp[i], dp[i-2] + arr[i]); // exclude arr[i-1]
			if(i - 3 >= 0)
				dp[i] = max(dp[i], dp[i-3] + arr[i-1] + arr[i]); // exclude arr[i-2]
		}
		return dp[n-1];
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
	Solution sol;
	vector<int>arr = {1, 2, 3, 4, 5, 6, 7, 8};
	cout << sol.findMaxNo3Adj(arr);
    return 0;
}