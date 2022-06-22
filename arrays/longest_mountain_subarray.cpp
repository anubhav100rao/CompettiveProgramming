#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int>lis_nlogn(vector<int>&arr) {
    // NlogN approach
    int n = arr.size();
    int inf = 1e9;
    vector<int>dp(n + 1, inf);
    dp[0] = -inf;

    for(int i = 0; i<n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        dp[pos] = arr[i];
    }

    return dp;

}


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