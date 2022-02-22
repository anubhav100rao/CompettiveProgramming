#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        vector<int>dp(n+1, 0);
        for(int i = 1; i<n; i++) {
            dp[i] = dp[i-1];
            if(arr[i] - arr[i-1] < k) {
                dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]);
            }
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
 
    return 0;
}