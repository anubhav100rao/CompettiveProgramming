#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution{
		
    
    /**
     * UNBOUNDED knapsack main observation
     * since we use any item any number of times
     * to our transition be like
     * dp[i][j] = min(dp[i-1][j], dp[i][j-wt[i-1]] + cost[i-1]);
     * in classical knapsack problem we have
     * dp[i][j] = min(dp[i-1][j], dp[i-1][j-wt[i-1]] + cost[i-1]);
     * 
     * this i - 1 ensures that we are only picking each element once
     * 
     * so in unbounded knapsack problems we can even use 1D to solve our problem
     * dp[j] = max(dp[j], dp[j-wt[i-1]] + cost[i-1]);
     *     
    */

	public:
	int minimumCost(int cost[], int n, int w) { 
        // Your code goes here
        const int inf = 1e9;
        vector<vector<int>>dp(n+1, vector<int>(w+1, inf));
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=w; j++) {
                dp[i][j] = dp[i-1][j];
                if(cost[i-1] != -   1 and i <= j) {
                    dp[i][j] = min(dp[i][j], dp[i][j-i] + cost[i-1]);
                }
            }
        }
        if(dp[n][w] == inf) return -1;
        return dp[n][w];
	} 

    int minCost(int cost[], int n, int w) {
        const int inf = 1e9;
        vector<int>dp(w+1, inf);
        dp[0] = 0;
        for(int i = 1; i<=n; i++) {
            if(cost[i-1] != -1) {
                for(int j = 1; j<=w; j++) {
                    if(i <= j and dp[j-i] != inf)
                        dp[j] = min(dp[j], dp[j-i] + cost[i-1]);
                }
            }
                
        }
        if(dp[w] == inf) return -1;
        return dp[w];
    }

    int unbounded_knapSack(int n, int w, int cost[], int wt[]) {
        vector<int>dp(w+1, 0);
        
        dp[0] = 0;
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=w; j++) {
                if(wt[i-1] <= j) {
                    dp[j] = max(dp[j], dp[j - wt[i-1]] + cost[i-1]);
                }
            }
        }
        return dp[w];
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