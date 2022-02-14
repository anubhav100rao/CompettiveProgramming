#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// Find the largest subset (length) such that
// for every pair of elements from subset
// the bigger number shoud be divisible by smaller number
// for example arr[] = {10, 5, 3, 15, 20} 
// output 3 -> {5, 10, 20}
class Solution {

public:
    int largest_divisible_subset(vector<int>arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int>dp(n, 0);
        // dp[i] is answer when the smallest number is arr[i]
        dp[n-1] = 1;
        for(int i = n-2; i>=0; i--) {
            int curr = 0;
            for(int j = i+1; j<n; j++) {
                if(arr[j] % arr[i] == 0) {
                    curr = max(curr, dp[j]);
                }
            }
            dp[i] = 1 + curr;
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