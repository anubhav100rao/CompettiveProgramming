#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution{  
    vector<vector<int>>dp;
public:
    Solution() {
        dp = vector<vector<int>>(101, vector<int>(100001, -1));
    }
    bool isSubsetSumRecur(int N, int arr[], int sum){
        // code here 
        if(sum == 0)
            return true;
        if(sum < 0)
            return false;
        if(N <= 0)
            return false;
        
        if(dp[N][sum] != -1)
            return dp[N][sum];
        
        return dp[N][sum] = isSubsetSum(N-1, arr, sum) || isSubsetSum(N-1, arr, sum - arr[N-1]);
    }
    bool isSubsetSum(int N, int arr[], int sum) {
        vector<vector<int>>dp(N+1, vector<int>(sum + 1, false));
        for(int i = 0; i<=N; i++) dp[i][0] = true;
        for(int i = 1; i<=sum; i++) dp[0][i] = false;
        for(int i = 1; i<=N; i++) {
            for(int j = 1; j<=sum; j++) {
                dp[i][j] = dp[i-1][j];
                if(arr[i-1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[N][sum];
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