#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
	public:
	int dp[101][905];
	int f(int idx, int last, string &str) {
	    if(idx < 0)
	        return 1;
	   if(dp[idx][last] != -1) {
	       // cout << "---\n";
	       return dp[idx][last];
	   }
	   int ans = 0;
	   int sum = 0;
	    for(int i = idx; i>=0; i--) {
	        sum += str[i] - '0';
	        if(sum <= last) {
	            ans += f(i - 1, sum, str);
	        } else break;
	    }
	    return dp[idx][last] = ans;
	 }
	
	int TotalCount(string str){
	    // Code here
	   memset(dp, -1, sizeof dp);
	   return f(str.size() - 1, 904, str);
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