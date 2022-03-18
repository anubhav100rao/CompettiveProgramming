#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
    private:
    const int mod = 1e9 + 7;
    public:
    using ll = long long;

    ll solve(string &str, int i, int j) {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        
        if(str[i] == str[j])
            return (1 + solve(str, i+1, j) + solve(str, i, j-1)) % mod;
        
        return (solve(str, i+1, j) + solve(str, i, j-1) - solve(str, i+1, j-1)) % mod;
    }

    long long int  countPS(string str) {
        int n = str.size();
        // return solve(str, 0, n-1);
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i = 0; i<n; i++)
            dp[i][i] = 1;
        
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i<n-len+1; i++) {
                int j = len + i - 1;
                if(str[i] == str[j]) {
                    dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % mod;
                } else {
                    dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]) % mod;
                }
            }
        }
        return dp[0][n-1];
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