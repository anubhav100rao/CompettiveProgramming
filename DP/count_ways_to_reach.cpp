#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    // only 3, 5, 10 length jumps are allowed
    int count_ways_to_reach_n(int n) {
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        vector<int>jumps = {3, 5, 10};
        for(int &jump: jumps) {
            for(int i = 1; i<=n; i++) {
                if(i >= jump) {
                    dp[i] += dp[i-jump];
                }
            }
        }
        return dp[n];
    }
    int total_ways(int n) {
        vector<int>dp(n+1, 0);
        vector<int>jumps = {3, 5, 10};
        for(int i = 1; i<=n; i++) {
            for(int &jump: jumps) {
                if(i >= jump) {
                    dp[i] += dp[i-jump];
                }
            }
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