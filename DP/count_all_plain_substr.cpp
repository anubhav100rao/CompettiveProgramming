#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<bool>>dp;
vector<vector<int>>memo;

int solve(char str[], int i, int j) {
    if(i >= j)
        return 0;
    if(i == j+1)
        return str[i] == str[j+1];
    
    if(memo[i][j] != -1)
        return memo[i][j];

    if(dp[i][j]) {
        return memo[i][j] = 1 + solve(str, i+1, j) + solve(str, i, j-1) - solve(str, i+1, j-1);
    }
    return memo[i][j] = solve(str, i+1, j) + solve(str, i, j-1) - solve(str, i+1, j-1);
    
}

int CountPS(char str[], int n) {
    dp = vector<vector<bool>>(n, vector<bool>(n, false));
    memo = vector<vector<int>>(n, vector<int>(n, -1));
    for(int i = 0; i<n; i++)
        dp[i][i] = true;
    
    for(int i = 0; i<n-1; i++) if(str[i] == str[i+1]) {
        dp[i][i+1] = true;
    }
    
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if(dp[i+1][j-1] && str[i] == str[j]) {
                dp[i][j] = true;
            }
        }
    }
    return solve(str, 0, n-1);
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