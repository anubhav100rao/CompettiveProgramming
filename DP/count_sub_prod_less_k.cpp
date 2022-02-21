#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int productSubSeqCount(vector<int>&arr, int k) {
    int n = arr.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    for(int i = 1; i<=k; i++) {
        for(int j = 1; j<=n; j++) {
            dp[i][j] = dp[i][j-1];
            if(arr[j-1] <= i) {
                dp[i][j] = dp[i/arr[j-1]][j-1] + 1;
            }
        }
    }
    return dp[k][n];
}

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