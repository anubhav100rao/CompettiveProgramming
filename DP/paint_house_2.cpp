#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    const int inf = 1e9;
    vector<vector<vector<int>>>dp;


    int solve(vector<int>&houses, vector<vector<int>>&cost, int idx, int target, int neigh, int prevColor) {
        if(idx >= houses.size()) {
            return neigh == target ? 0: inf;
        }
        
        if(neigh > target) return inf;

        if(dp[idx][neigh][prevColor] != -1) return dp[idx][neigh][prevColor];

        if(houses[idx] != 0) {
            int newNeigh = prevColor == houses[idx] ? neigh : neigh + 1;
            return solve(houses, cost, idx + 1, target, newNeigh, houses[idx]);
        }

        

        int currHouseCost = inf;

        for(int color = 1; color <= cost[0].size(); color++) {
            int newNeigh = prevColor == color ? neigh: neigh + 1;
            int currColorCost = cost[idx][color - 1] + solve(houses, cost, idx + 1, target, newNeigh, color);
            currHouseCost = min(currHouseCost, currColorCost);
        }

        return dp[idx][neigh][prevColor] = currHouseCost;
    }


    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        dp = vector<vector<vector<int>>>(houses.size(), vector<vector<int>>(target + 1, vector<int>(cost[0].size() + 1, -1)));

        int ans = solve(houses, cost, 0, target, 0, 0);

        return ans >= inf ? -1: ans;
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