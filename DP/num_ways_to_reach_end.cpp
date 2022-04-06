#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int>solve_jump_problem(vector<int>&arr) {
    int n = arr.size();
    vector<int>dp(n, 0);
    dp[n-1] = 0;
    for(int i = n-2; i>=0; i--) {
        if(arr[i] == 0) {
            dp[i] = -1;
        } else {
            int mx_jump = arr[i];
            if(i + mx_jump >= n-1) {
                dp[i] = 1;
            }

            for(int j = i+1; j < min(n, i + mx_jump + 1); j++) {
                if(dp[j] != -1)
                    dp[i] += dp[j];
            }
        }
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
    int n; cin >> n;
    vector<int>arr(n, 0);
    for(int &i: arr)
        cin >> i;
    vector<int>res = solve_jump_problem(arr);
    for(int i: res)
        cout << i << ' ';
    cout << '\n';
    return 0;
}