#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
		
	public:
	int minInsertions(int arr[], int n) { 
	    
	    vector<int>dp(n, 1);
	    for(int i = 1; i<n; i++) {
	        for(int j = 0; j<i; j++) {
	            if(arr[i] >= arr[j])
	                dp[i] = max(dp[i], dp[j] + 1);
	        }
	    }
	    
	    return n - *max_element(dp.begin(), dp.end());
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