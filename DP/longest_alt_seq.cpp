#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
	public:
        int solve(vector<int>&arr) {
            int n = arr.size();
            vector<vector<int>>dp(n, vector<int>(2, 1));

            for(int i = 1; i<n; i++) {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
                if(arr[i] > arr[i-1]) {
                    dp[i][0] = dp[i-1][1] + 1;
                }
                if(arr[i] < arr[i-1]) {
                    dp[i][1] = dp[i-1][0] + 1;
                }
            }
            return max(dp[n][0], dp[n][1]);
        }
        int dpBrute(vector<int>&arr) {
            int n = arr.size();
		    vector<vector<int>>dp(n, vector<int>(2, 1));
            for(int i = 1; i<n; i++) {
                for(int j = 0; j<i; j++) {
                    if(arr[i] < arr[j]) {
                        dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                    }
                    if(arr[i] > arr[j]) {
                        dp[i][0] = max(dp[j][1] + 1, dp[i][0]);
                    }
                }
            }
            return max(dp[n-1][0], dp[n-1][1]);
        }
		int AlternatingaMaxLength(vector<int>&arr){   
            return solve(arr);
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