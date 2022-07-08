#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    
    int n;
    vector<int>pre;

    vector<vector<vector<int>>>dp;

    int solve(int idx, bool turn, int m) {
        if(idx > n) {
            return 0;
        }

        if(dp[idx][turn][m] != -1) return dp[idx][turn][m];
        
        if(turn) {
            int curr = 0;
            for(int x = 1; x <= 2 * m and idx + x - 1 <= n; x++) {
                curr = max(curr, solve(idx + x, !turn, max(m, x)) + pre[idx + x - 1] - pre[idx - 1]);
            }
            return dp[idx][turn][m] = curr;
        }

        int curr = INT_MAX;
        for(int x = 1; x <= 2 * m and idx + x - 1 <= n; x++) {
            curr = min(curr, solve(idx + x, !turn, max(x, m)));
        }

        return dp[idx][turn][m] = curr;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        pre = vector<int>(n + 1, 0);
        for(int i = 1; i<=n; i++) {
            pre[i] = pre[i-1] + piles[i-1];
        }

        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(201, -1)));

        return solve(1, true, 1);
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