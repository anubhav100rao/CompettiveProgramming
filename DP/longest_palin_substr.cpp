#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{   
public:
    string longestPalindrome(string str){
        int n = str.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        
        for(int i = 0; i<n; i++)
            dp[i][i] = true;

        int ans = 1;
        int start = 0;

        for(int i = 0; i<n-1; i++)
            if(str[i] == str[i+1]) {
                dp[i][i+1] = true;
                ans = 2;
                start = i;
            }
        
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if(dp[i+1][j-1] && str[i] == str[j]) {
                    dp[i][j] = true;
                    if(len > ans) {
                        ans = len;
                        start = i;
                    }
                }
            }
        }

        return str.substr(start, ans);
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
    Solution sol;
    string str; cin >> str;
    cout << sol.longestPalindrome(str);
    return 0;
}