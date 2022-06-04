#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"



int solve(int n) {
    if(n == 1)  return 10;
    vector<vector<int>>dp(n+1, vector<int>(10, 0));
    for(int i = 0; i<10; i++)
        dp[1][i] = 1;
    for(int i = 2; i<=n; i++) {
        for(int j = 0; j<10; j++) {
            if(j == 0)
                dp[i][j] = dp[i-1][j+1];
            else if(j == 9)
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = dp[i-1][j+1] + dp[i-1][j-1];
        }
    }
    int ans = accumulate(dp[n].begin(), dp[n].end(), 0) - dp[n][0]; // because we don't want our number starts with zero
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
        
    return 0;
}