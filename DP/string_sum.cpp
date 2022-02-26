#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution
{
    public:
    const int mod = 1e9 + 7;
    //Function to find sum of all possible substrings of the given string.
    int toDigit(char ch) {
        return ch - '0';
    }
    long long sumSubstrings(string s) {
        int n = s.size();
        vector<long long>dp(n, 0LL);
        dp[0] = toDigit(s[0]);
        long long res = 0;
        for(int i = 1; i<n; i++) {
            int curr = toDigit(s[i]);
            dp[i] = (i + 1) * curr + 10 * dp[i-1];
            dp[i] %= mod;
            res += dp[i];
            res %= mod;
        }
        /**
         *  dp[i] = (i + 1) * curr + 10 * dp[i-1]
        */
        return res;
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