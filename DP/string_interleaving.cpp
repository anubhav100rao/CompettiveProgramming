#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<vector<int>>>dp;
bool solve(string &A, string &B, string &C, int i, int j, int k) {
    if(k >= C.size()) return true;
    
    if(dp[i][j][k] != -1) return dp[i][j][k];
    
    if(A[i] == B[j] and A[i] == C[k] and i < A.size() and j < B.size()) {
        return dp[i][j][k] = solve(A, B, C, i + 1, j, k + 1) || solve(A, B, C, i, j + 1, k + 1);
    } else if(A[i] == C[k] and i < A.size()) {
        return dp[i][j][k] = solve(A, B, C, i + 1, j, k + 1);
    } else if(B[j] == C[k] and j < B.size()) {
        return dp[i][j][k] = solve(A, B, C, i, j + 1, k + 1);
    } return dp[i][j][k] = false;
}

int isInterleave(string A, string B, string C) {
    dp = vector<vector<vector<int>>>(A.size() + 1, vector<vector<int>>(B.size() + 1, vector<int>(C.size() + 1, -1)));
    return solve(A, B, C, 0, 0, 0);
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