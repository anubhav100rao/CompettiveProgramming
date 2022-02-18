#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int solve(vector<vector<int>>&dp, int start, int end) {
        if(start >= end) 
            return 0;
        if(dp[start][end] != -1) return dp[start][end];

        int curr = 1e9;
        for(int i = start; i<=end; i++) {
            int temp = i + max(solve(dp, start, i-1), solve(dp, i+1, end));
            curr = min(curr, temp);
        }
        return dp[start][end] = curr;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(dp, 1, n);
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