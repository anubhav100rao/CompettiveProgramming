#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{

    const int inf = 1e9;
	
    public:
    vector<vector<int>>dp;

    int solve_recur(int arr[], int i, int k) {
        if(i < 0)
            return inf;
        if(dp[i][k] != -1)
            return dp[i][k];
        
        if(k == 1) {
            int ans = inf;
            for(int j = 0; j<=i; j++)
                ans = min(ans, arr[j]);
            return ans;
        }

        
        int ans = inf;

        for(int j = 0; j<i; j++) {
            if(arr[i] >= arr[j]) {
                ans = min({ans, solve_recur(arr, j, k), solve_recur(arr, j, k-1) + arr[i]});
            } else {
                ans = min(ans, solve_recur(arr, j, k));
            }
        }

        return dp[i][k] = ans;
    }

	int minSum(int arr[], int n, int k) {
        dp = vector<vector<int>>(n+1, vector<int>(k+1, -1));
        return solve_recur(arr, n-1, k);
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