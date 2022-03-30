#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<int>>dp;

int balanced_string(string &str, int l, int r) {
    if(l >= r)
        return 0;
    
    if(dp[l][r] != -1)
        return dp[l][r];
    

    int ans = 0;
    if(str[l] == '(' and str[r] == ')') {
        ans = 2 + balanced_string(str, l+1, r-1);
    }
    for(int i = l; i<r; i++)
        ans = max(ans, balanced_string(str, l, i) + balanced_string(str, i+1, r));
    return dp[l][r] = ans;
}

int balanced_string_dp(string &str) {
    int n = str.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));
    

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i<n-len+1; i++) {
            int j = i + len - 1;
            if(str[i] == '(' and str[j] == ')') {
                dp[i][j] = 2 + dp[i+1][j-1];
            } 
            for(int k = i; k<j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
        }
    }

    return dp[0][n-1];
}


int maxLength(string &s) {
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
 
    // Considering all balanced
    // substrings of length 2
    for (int i = 0; i < n - 1; i++)
        if (s[i] == '(' && s[i + 1] == ')')
            dp[i][i + 1] = 2;
 
    // Considering all other substrings
    for (int l = 2; l < n; l++) {
        for (int i = 0, j = l; j < n; i++, j++) {
            if (s[i] == '(' && s[j] == ')')
                dp[i][j] = 2 + dp[i + 1][j - 1];
 
            for (int k = i; k < j; k++)
                dp[i][j] = max(dp[i][j],
                               dp[i][k] + dp[k + 1][j]);
        }
    }
 
    return dp[0][n - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif

    string str; cin >> str;
    int n = str.size();
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    cout << balanced_string(str, 0, n - 1) << '\n';
    cout << balanced_string_dp(str) << '\n';
    cout << maxLength(str) << '\n';
    return 0;
}