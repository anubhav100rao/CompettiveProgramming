#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int dp[30][130];
    int solve(int i, vector<int>&arr, int k) {
        if(i == 0) {
            if(k == 0 || k == arr[0])
                return 1;
            else
                return 0;
        }

        if(i < 0)
            return 0;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        return dp[i][k] = solve(i-1, arr, k) + solve(i-1, arr, k ^ arr[i]);
    }

    int dp_solve(vector<int>&arr, int k) {
        int n = arr.size();
        vector<vector<int>>dp(31, vector<int>(131, 0));
        dp[0][0] = 1;

        for(int i = 1; i<=n; i++) {
            for(int j = 0; j<=130; j++) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j * arr[i-1]];
            }
        }
        return dp[n][k];
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