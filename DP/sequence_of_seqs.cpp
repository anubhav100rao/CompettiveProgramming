#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int count_sequences(int m, int n) {
        // find sequence of length n such that
        // each number in the sequence is atleast twice of previous number
        // and less than equal to m

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                if(i == 1) {
                    dp[i][j] = j;
                } else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j/2];
                }
            }
        }
        return dp[n][m];
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