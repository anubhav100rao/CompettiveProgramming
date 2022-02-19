#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int>dp(n, 1);
       for(int i = 0; i<n; i++) {
           for(int j = 0; j<i; j++) {
               if(a[i] > a[j]) {
                   dp[i] = max(dp[i], dp[j] + 1);
               }
           }
       }
       return *max_element(dp.begin(), dp.end());
    }
    int listNlogN(vector<int>&arr) {
        const int inf = 1e9;
        int n = arr.size();
        vector<int>dp(n+1, inf);
        dp[0] = -inf;
        for(int i = 0; i<n; i++) {
            int j = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            if(dp[j-1] < arr[i] and arr[i] < dp[j]) {
                dp[j] = arr[i];
            }
        }
        int ans = 0;
        for(int i = 0; i<=n; i++) {
            if(dp[i] < inf) {
                ans = i;
            }
        }
        return ans;
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