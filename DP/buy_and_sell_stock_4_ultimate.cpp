#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int n, k;
    vector<vector<int>>dp;
    vector<int>prices;
    int solve(int idx, int trans) {
        if(idx >= n) return 0;
        if(trans >= 2 * k) return 0;
        
        if(dp[idx][trans] != -1) return dp[idx][trans];
        
        if(trans & 1) {
            // sell this stock
            
            return dp[idx][trans] = max(solve(idx + 1, trans), solve(idx + 1, trans + 1) + prices[idx]);
        }
        
        // buy this stock
        
        return dp[idx][trans] = max(solve(idx + 1, trans), solve(idx + 1, trans + 1) - prices[idx]);
        
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        this->n = prices.size();
        this->k = k;
        dp = vector<vector<int>>(n, vector<int>(2 * k, -1));
        this->prices = prices;
        
        return solve(0, 0);
        
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