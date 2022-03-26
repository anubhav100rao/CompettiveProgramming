#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<int>>dp;

void construct_dp(string &str) {
    static int run = 0;
    if(run > 0)
        return;
    run++;
    int n = str.size();
    dp = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    vector<vector<bool>>isPalin(n+1, vector<bool>(n+1, false));
    
    for(int i = n-1; i>=0; i--) {
        isPalin[i][i] = 1;
        dp[i][i] = 1;
        for(int j = i+1; j<n; j++) {
            isPalin[i][j] = (str[i] == str[j]) && (i + 1 > j - 1 || isPalin[i+1][j-1]);
            dp[i][j] = isPalin[i][j] + dp[i+1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
}

int countPalinInRange (int n, string A, int q1, int q2) {
    construct_dp(A);
    return dp[q1][q2];
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