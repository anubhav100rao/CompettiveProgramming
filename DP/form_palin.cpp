#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{   
public:
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i<=m; i++) {
            for(int j = 1; j<=n; j++) {
                if(X[i-1] == Y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return (m - dp[m][n]);
    }
    int findMinInsertions(string S){
        string t = S;
        reverse(S.begin(), S.end());
        return shortestCommonSupersequence(S, t, S.size(), t.size());
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