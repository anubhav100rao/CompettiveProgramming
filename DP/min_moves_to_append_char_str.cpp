#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
public: 
    
    int minSteps(string str)
    {
        // Your code goes here
        int n = str.size();
        vector<int>dp(n+1, INT_MAX);

        dp[0] = 1;
        string s = "";
        s.push_back(str[0]);
        for(int i = 1; i<n; i++) {
            s.push_back(str[i]);
            string appendable = str.substr(i + 1, i + 1);
            dp[i] = min(dp[i], dp[i-1] + 1);
            if(s == appendable) {
                dp[2 * i + 1] = min(dp[2 * i + 1], dp[i] + 1);
            }
        }
        return dp[n-1];
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