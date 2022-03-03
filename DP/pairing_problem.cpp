#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<int>dp;
    int numberOfWays(int x) {
        if(x <= 1)
            return 1;
        if(dp[x] != -1)
            return dp[x];
        return dp[x] = numberOfWays(x-1) + (x - 1) * numberOfWays(x - 2);
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