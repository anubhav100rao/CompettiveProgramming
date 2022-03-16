#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    vector<vector<int>>dp;

    bool solve(vector<int>&arr, int sm, int idx) {
        if(sm < 0 || idx < 0)
            return false;
        if(sm == 0)
            return true;
        if(dp[idx][sm] != -1)
            return dp[idx][sm];
        if(arr[idx] <= sm)
            return dp[idx][sm] = solve(arr, sm, idx - 1) || solve(arr, sm-arr[idx], idx-1);
        return dp[idx][sm] = solve(arr, sm, idx-1);
    }

    bool can_partition_dp(vector<int>&arr) {
        int sm = accumulate(arr.begin(), arr.end(), 0);
        if(sm & 1)
            return false;
        sm >>= 1;
        int n = arr.size();
        vector<vector<bool>>dp(n+1, vector<bool>(sm + 1, false));
        for(int i = 0; i<=n; i++)
            dp[i][0] = true;
        
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=sm; j++) {
                dp[i][j] = dp[i-1][j];
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][sm];
    }

    bool can_partion(vector<int>&arr) {
        int sm = accumulate(arr.begin(), arr.end(), 0);
        if(sm & 1)
            return false;
        sm >>= 1;
        dp = vector<vector<int>>(arr.size() + 1, vector<int>(sm+1, -1));
        return solve(arr, sm, arr.size() - 1);
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
    int n; cin >> n;
    vector<int>arr(n, 0);
    for(int &i: arr)
        cin >> i;
    Solution sol;
    cout << sol.can_partion(arr) << ' ' << sol.can_partition_dp(arr) << '\n';
    return 0;
}