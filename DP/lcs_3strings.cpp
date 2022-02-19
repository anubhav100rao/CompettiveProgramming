#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>>dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, 0)));
    for(int i = 1; i<=n1; i++) {
        for(int j = 1; j<=n2; j++) {
            for(int k = 1; k<=n3; k++) {
                if(A[i-1] == B[j-1] and A[i-1] == C[k-1]) {
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                } else {
                    dp[i][j][k] = max(
                            {
                                dp[i-1][j][k],
                                dp[i][j-1][k],
                                dp[i][j][k-1]
                            }
                        );
                }
            }
        }
    }
    return dp[n1][n2][n3];
}


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