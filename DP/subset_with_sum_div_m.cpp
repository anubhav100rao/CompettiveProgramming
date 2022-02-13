#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
	public:

		int DivisibleByM(vector<int>nums, int m){
		    // Code here
		    int n = nums.size();
		    // from pegionhole principle since each integer is distinct
		    if(n > m)
		        return true;
		    vector<bool>dp(m, false);
		    
		    for(int i = 0; i<n; i++) {
		        if(dp[0]) return true;
		        vector<int>temp(m, false);
		        for(int j = 0; j<m; j++) {
		            if(dp[j]) {
		                temp[(j + nums[i]) % m] = true;
		            }
		        }
		        for(int j = 0; j<m; j++) dp[j] = dp[j] || temp[j];
		        dp[nums[i] % m] = true;
		    }
		    return dp[0];
		    
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