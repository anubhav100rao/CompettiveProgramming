#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int n, m;
    vector<vector<bool>>arr;
    vector<vector<int>>dp;
    const int mod = 1e9 + 7;
	
	int solve(int i, int j) {
	    if(i > n || j > m)
	        return 0;
	    if(arr[i][j])
	        return 0;
	    if(i == n and j == m)
	        return 1;
	   
	   if(dp[i][j] != -1)
	        return dp[i][j];
	   
	    return dp[i][j] = (solve(i+1, j) + 0LL + solve(i, j+1)) % mod;
	}
	
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    // Code here
	    this->n = n;
	    this->m = m;
	    
	    
	    arr = vector<vector<bool>>(n+1, vector<bool>(m+1, false));
	    dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
	    
	    for(auto &vec: blocked_cells) {
	        int a = vec[0], b = vec[1];
	        arr[a][b] = true;
	    }
	    return solve(1, 1);
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