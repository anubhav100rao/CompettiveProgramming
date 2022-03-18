#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

bool perfect_sum(vector<int>&arr) {
    int n = arr.size();
    int sm = accumulate(arr.begin(), arr.end(), 0);
    if((sm & 1) || n < 2)
        return false;
    
    sm /= 2;

    vector<vector<bool>>dp(n+1, vector<bool>(sm+1, false));
    for(int i = 0; i<=n; i++)
        dp[i][0] = true;
    
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=sm; j++) {
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j)
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }


    if(!dp[n][sm])
        return false;
    vector<int>res;
    int i = n, j = sm;
    while(i > 0 and j > 0) {
        if(j >= arr[i-1] and dp[i-1][j - arr[i-1]]) {
            j -= arr[i-1];
            res.push_back(i-1);
            i--;
        } else {
            i--;
        }
    }
    for(int i: res) cout << arr[i] << ' '; cout << '\n';
    return true;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    int n; cin >> n;
    vector<int>arr(n, 0);
    for(int &i: arr)
        cin >> i;
    cout << perfect_sum(arr);
    return 0;
}