#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int longestAltDiff(vector<int>&arr) {
    int n = arr.size();
    vector<int>dp(n, 1);
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<i; j++) {
            if(abs(arr[i] - arr[j]) == 1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for(int i = 0; i<n; i++) {
        cout << dp[i] << ' ';
    } cout << '\n';
    return dp[n-1];
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int>arr = {3, 10, 3, 11, 4, 5, 6, 7, 8, 12};
    cout << longestAltDiff(arr);
    return 0;
}