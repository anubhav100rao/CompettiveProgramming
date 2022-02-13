#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl



class Solution {
  public:
    vector<vector<int>>memo;
    vector<int>dp;
    void init() {
        memo = vector<vector<int>>(3000, vector<int>(3000, -1));
        dp = vector<int>(1000, -1);
        dp[0] = 1;
    }
    long long countUniqueRecur(int S[], int len, int required) {
        if(required == 0)
            return 1;
        if(required < 0)
            return 0;
        if(len <= 0) return 0;
        if(memo[len][required] == -1)
            memo[len][required] = countUniqueRecur(S, len - 1, required) + countUniqueRecur(S, len, required - S[len-1]);
        return memo[len][required];
    }
    
    long long countAllRecur(int S[], int len, int required) {
        if(required < 0) return 0;
        if(required == 0) return 1;

        if(dp[required] != -1)
            return dp[required];

        int curr = 0;

        for(int i = 0; i<len; i++) {
            if(S[i] <= required) {
                curr += countAllRecur(S, len, required - S[i]);
            }
        }

        return dp[required] = curr;
    }

    // IMPORTANT STUFF

    long long int count(int S[], int m, int n) {

        vector<long long>dp(n+1, 0);
        dp[0] = 1;
        // unique ways
        // here we are adding the contribution of each coin in making the total
        for(int coin_idx = 0; coin_idx < m; coin_idx++) {
            for(int i = 1; i<=n; i++) {
                if(S[coin_idx] <= i) {
                    dp[i] += dp[i - S[coin_idx]];
                }
            }
        }
        
        
        // all ways
        // here we are checking for all subproblems wheather we can add current coin or not for all coins
        for(int i = 1; i<=n; i++) {
            for(int j = 0; j<m; j++) {
                if(S[j] <= i) {
                    dp[i] += dp[i - S[j]];
                }
            }
        }
        return dp[n];
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