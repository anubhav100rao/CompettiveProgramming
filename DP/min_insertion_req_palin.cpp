#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
  public:
    int countMin(string str){
    //complete the function here
        int n = str.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
        string s = str;
        reverse(str.begin(), str.end());
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                if(s[i-1] == str[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }  
        return n - dp[n][n];
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