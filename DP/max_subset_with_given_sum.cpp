#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int maxSubsetWithGivenSum(vector<int>&arr, int sum) {
    int n = arr.size();
    vector<vector<bool>>dp(n+1, vector<bool>(sum + 1, false));
    vector<vector<int>>cnt(n + 1, vector<int>(sum + 1, 0));

    for(int i = 0; i<=n; i++) {
        dp[i][0] = true;
    }

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j)
                dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
            
            if(dp[i][j]) {
                cnt[i][j] = max(cnt[i-1][j], cnt[i-1][j-arr[i-1]] + 1);
            }
        }
    }
    if(dp[n][sum])
        return cnt[n][sum];
    return -1;


}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int>arr = { 2, 3, 5, 10 };

    cout << maxSubsetWithGivenSum(arr, 20);
 
    return 0;
}