#include<bits/stdc++.h>
using namespace std;

class MinRemovalToMakeMaxMinDiffK {
public:

    int solve(vector<int>&arr, int i, int j, int k, vector<vector<int>>&dp) {
        if(i >= j)
            return dp[i][j] = 0;
        if(arr[j] - arr[i] <= k)
            return dp[i][j] = 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = 1 + min(solve(arr, i+1, j, k, dp), solve(arr, i, j-1, k, dp));
    }

    int find_min_memo(vector<int>&arr, int k) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        sort(arr.begin(), arr.end());
        return solve(arr, 0, n-1, k, dp);
    }

    int find_min(vector<int>&arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        const int inf = 1e9;
        vector<vector<int>>dp(n, vector<int>(n, inf));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i >= j) {
                    dp[i][j] = 0;
                } else if(arr[j] - arr[i] <= k) {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = n-1; i>=0; i--) {
            for(int j = i+1; j<n; j++) {
                dp[i][j] = min(dp[i][j], 1 + min(dp[i+1][j], dp[i][j-1]));
            }
        }
        
        return dp[0][n-1];
    }
};

signed main() {
    int n, k; cin >> n >> k;
    vector<int>arr(n, 0);
    for(int &i: arr) cin >> i;

    MinRemovalToMakeMaxMinDiffK sol;
    cout << sol.find_min(arr, k) << ' ' << sol.find_min_memo(arr, k) << '\n';
}