#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl



class Solution {
const int mod = 1e9 + 7;
vector<int>dp;
public:
    Solution() {
        dp = vector<int>(10001, -1);
    }
    int countFriendsPairings(int n) { 
        // code here
        // if(n < 0)
        //     return 0;
        // if(n == 0)
        //     return 1;
        // if(dp[n] != -1)
        //     return dp[n];
            
        // return dp[n] = (countFriendsPairings(n - 1) % mod + ((n - 1) * 1LL * countFriendsPairings(n - 2)) % mod) %  mod;
    
        vector<long long>dp(n+1, 0LL);
        dp[0] = 1;
        if(n == 1) return 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++) {
            dp[i] = (dp[i-1] + (i - 1) * dp[i-2]) % mod;;
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