#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(102, vector<double>(102));
        dp[0][0] = poured;
        for(int r = 0; r <= query_row; r++) {
            for(int c = 0; c <= r; c++) {
                double q = (dp[r][c] - 1.0) / 2.0;
                if(q > 0) {
                    dp[r+1][c] += q;
                    dp[r + 1][c + 1] += q;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
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