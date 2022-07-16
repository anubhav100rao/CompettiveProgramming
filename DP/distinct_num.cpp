#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int solve(string &A, string &B, int i, int j, vector<vector<int>>&dp) {
    if(j >= B.size()) return 1;
    if(i >= A.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(A[i] != B[j]) {
        return dp[i][j] = solve(A, B, i + 1, j, dp);
    }
    return dp[i][j] = solve(A, B, i + 1, j + 1, dp) + solve(A, B, i + 1, j, dp);
}

int numDistinct(string A, string B) {
    int n = A.size(), m = B.size();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return solve(A, B, 0, 0, dp);
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