#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int> give_lis(vector<int>&arr) {
    int n = arr.size();
    vector<int>dp(n, 0);
    for(int i = 0; i<n; i++) {
        dp[i] = arr[i];
        for(int j = 0; j<i; j++) {
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
    return dp;
}

int maxSumBS(int a[] , int n )
{
    vector<int>arr;
    for(int i = 0; i<n; i++) {
        arr.push_back(a[i]);
    }
    vector<int>lis1 = give_lis(arr);
    reverse(arr.begin(), arr.end());
    vector<int>lis2 = give_lis(arr);
    reverse(lis2.begin(), lis2.end());
    int ans = 0;
    for(int i = 0; i<n; i++) {
        ans = max(ans, lis1[i] + lis2[i] - a[i]);
    }
    // for(int i: lis1) cout << i << ' '; cout << '\n';
    // for(int i: lis2) cout << i << ' '; cout << "\n";
    return ans;
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