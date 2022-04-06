#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    using ll = long long;
    vector<vector<vector<ll>>>dp;

    ll solve(int n, int m, vector<vector<int>>&arr, int k) {
        if(n < 0 || m < 0 || k < 0)
            return 0;
        if(n == 0 and m == 0)
            return (k == arr[0][0]) ? 1: 0;
        if(dp[n][m][k] != -1)
            return dp[n][m][k];
        
        return dp[n][m][k] = solve(n - 1, m, arr, k - arr[n][m]) + solve(n, m - 1, arr, k - arr[n][m]);
        
    }

    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        dp = vector<vector<vector<ll>>>(n, vector<vector<ll>>(n, vector<ll>(k + 1, -1)));
        return solve(n - 1, n - 1, arr, k);
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