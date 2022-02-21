#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int maxGamesPlayedByWinner(int n) {
        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        int i = 2;
        do {
            dp[i] = dp[i-1] + dp[i-2];
        } while(dp[i++] <= n);
        return i - 2;
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