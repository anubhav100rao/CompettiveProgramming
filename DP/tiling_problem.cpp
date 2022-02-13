#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
  public:
    long long numberOfWays(long long N) {
        //code here
        const int mod = 1e9 + 7;
        if(N <= 2) return N;
        long long res = 0LL;
        long long a = 1LL, b = 2LL;
        for(int i = 3; i<=N; i++) {
            res = a + b;
            res %= mod;
            a = b;
            b = res;
        }
        return res;
    }

    int countWays(int n, int m) {
        if(n < m) return 1;
        if(n == m) return 2;
        vector<int>dp(n+1, 1);
        for(int i = m+1; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i - m];
        }
        return dp[n];
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