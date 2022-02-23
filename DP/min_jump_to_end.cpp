#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int minJumps(vector<int>&arr) {
        int n = arr.size();
        vector<int>dp(n, INT_MAX);
        if(n == 0 || arr[0] == 0)
            return -1;

        dp[0] = 0;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(dp[j] != INT_MAX and i <= j + dp[j]) {
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        } 
        return dp[n-1];
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