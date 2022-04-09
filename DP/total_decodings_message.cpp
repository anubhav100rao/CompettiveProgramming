#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
	public:
	    const int mod = 1e9 + 7;
	    long long dp[100001];
	    long long solve(int idx, string &str) {
	       if(idx == str.size())
	            return 1LL;
	        if(idx > str.size())
	            return 0LL;
	       
	       if(dp[idx] != -1)
	            return dp[idx];
	       
	       
	       if(idx + 1 < str.size() and str[idx + 1] == '0')
	            return dp[idx] = solve(idx+2, str) % mod;
	       long long curr = solve(idx + 1, str) % mod;
	       assert(str[idx] != '0');
	       if(str[idx] == '1') {
	           if(idx+2<str.size()&&str[idx+2]!='0') {
	               curr += solve(idx + 2, str);
	               curr %= mod;
	           } else if(idx + 2 == str.size()) {
	               curr += solve(idx + 2, str);
	               curr %= mod;
	           }
	       }
	       if(idx+1 < str.size() and str[idx] == '2' and str[idx + 1] <= '6') {
	           if(idx+2<str.size()&&str[idx+2]!='0') {
	               curr += solve(idx + 2, str);
	               curr %= mod;
	           } else if(idx + 2 == str.size()) {
	               curr += solve(idx + 2, str);
	               curr %= mod;
	           }
	       }
	       return dp[idx] = curr % mod;
	    }
		int CountWays(string str){
		   memset(dp, -1, sizeof dp);
		   if(str.size() == 0)
		    return 1;
		   if(str[0] == '0')
		    return 0;
		   for(int i = 1; i<str.size(); i++) {
		       if(str[i] == '0' and str[i-1] == '0')
		        return 0;
		       if(str[i] == '0' and str[i-1] > '2')
		        return 0;
		   }
		   return solve(0, str);
		  // int n = str.size();
		  // vector<int>dp(n+1, 0);
		  // dp[0] = dp[1] = 1;
		  // for(int i = 2; i<=n; i++) {
		  //     if(str[i-1] != '0') {
		  //         dp[i] = dp[i-1];
		  //     }
		  //     int val = stoi(str.substr(i - 2, 2));
		  //     if(val <= 26 and str[i-2] != '0')
		  //          dp[i] += dp[i-2];
		  //      dp[i] %= mod;
		  // }
		  // return dp[n];
		  // 2 2 0
		  
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