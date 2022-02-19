#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int lcs(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j<=m; j++) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int lcs_space_optimised(string &s1, string &s2) {
    int x = s1.size(), y = s2.size();
    vector<vector<int>>dp(2, vector<int>(y+1, 0));
    int idx = 0;
    for(int i = 0; i<=x; i++) {
        idx = i % 2;
        for(int j = 0; j<=y; j++) {
            if(i == 0 || j == 0) {
                dp[idx][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                dp[idx][j] = 1 + dp[(idx - 1 + 2) % 2][j-1];
            } else {
                dp[idx][j] = max(dp[(idx - 1 + 2) % 2][j], dp[idx][j-1]);
            }
        }
    }
    return dp[idx][y];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    string str = "ABCDGH";
    string ptr = "AEDFHR";
    cout << lcs(str, ptr);
    return 0;
}