#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


int distinct_subsequences(string str) {
    vector<int>last(128, -1);
    int n = str.size();
    vector<int>dp(n+1, 1);
    for(int i = 1; i<=n; i++) {
        dp[i] = dp[i-1] * 2;
        if(last[str[i-1]] != -1) 
            dp[i] -= dp[last[str[i-1]]];
        last[str[i-1]] = i-1;
    }
    return dp[n];
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    cout << distinct_subsequences("Anubhav") << "\n";
    cout << distinct_subsequences("ggg") << "\n";
    return 0;
}