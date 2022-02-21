#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
public:
    int longestSubsequence(int n, int arr[])
    {
        // code here
        vector<int>dp(n, 0);
        for(int i = 0; i<n; i++) {
            dp[i] = 1;
            for(int j = 0; j<i; j++) {
                if(abs(arr[i] - arr[j]) == 1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
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