#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int maxAlternateSum(vector<int>&arr) {
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(2, 0));
    dp[0][0] = arr[0]; //* incresing
    dp[0][1] = arr[0]; //* decreasing

    bool flag = false;

    for(int i = 1; i<n; i++) {
        dp[i][0] = arr[i];
        dp[i][1] = arr[i];
        for(int j = 0; j<i; j++) {
            if(arr[i] < arr[j]) {
                dp[i][1] = max(dp[j][0] + arr[i], dp[i][1]);
                flag = true;
            }
            if(arr[i] > arr[j] and flag) {
                dp[i][0] = max(dp[j][1] + arr[i], dp[i][0]);
            }
        }
    }
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<2; j++) {
            cout << dp[i][j] << ' ';
        } cout << '\n';
    }
    return max(dp[n-1][0], dp[n-1][1]);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int>arr(n, 0);
    for(int &i: arr) cin >> i;
    cout << maxAlternateSum(arr);
    return 0;
}