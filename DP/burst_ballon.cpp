#include <bits/stdc++.h> 
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"



class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        vector<vector<int>>dp(N + 2, vector<int>(N + 2, 0));
        vector<int>B(N + 2, 1);
        for(int i = 0; i < N; i++)
            B[i + 1] = arr[i];
        for(int len = 1; len <= N; len++) {
            for(int i = 1, j = i + len - 1; j <= N; i++, j++) {
                for(int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + B[k] * B[i - 1] * B[j + 1]);
                }
                
            }
        }    

        return dp[1][N];
    }
};



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