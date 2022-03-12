#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int eggDrop(int eggs, int floors) {
        if(floors <= 1)
            return floors;
        if(eggs == 1)
            return floors;
        int res = INT_MAX;

        for(int i = 1; i<= floors; i++) {
            int curr = max(
                eggDrop(eggs - 1, i - 1), // if egg damages
                eggDrop(eggs, floors - i) // if it survives
            );
            res = min(res, curr);
        }
        return res + 1;
    }
    int eggDropDp(int eggs, int floors) {
        const int inf = 1e9;
        vector<vector<int>>dp(eggs + 1, vector<int>(floors + 1, inf));
        for(int i = 1; i<=eggs; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int i = 1; i<=floors; i++) {
            dp[1][i] = i;
        }
        for(int i = 2; i<=eggs; i++) {
            for(int j = 2; j<=floors; j++) {
                for(int x = 1; x <= j; x++) {
                    dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j - x]));
                }
            }
        }
        return dp[eggs][floors];
    }
};


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Solution sol;
    int n = 2, k = 36;
    cout << sol.eggDropDp(n, k) << '\n';
    return 0;
}