#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution1 {
public:
    int removePalindromeSub(string s) {
        // each step we can remove a palindrome
        // calculate min steps required such that s becomes ""
        // s is composed of only 'a' and 'b': so max answer can only be 2
        // we have to check if s palindrome for answer 1
        int l = 0, r = s.size() - 1;
        while(l < r)
            if(s[l++] != s[r--])
                return 2;
        return 1;
    }
};

class Solution2 {
public:
    bool checkPalin(string &str) {
        int l = 0, r = str.size() - 1;
        while(l < r)
            if(str[l++] != str[r--])
                return false;
        return true;
    }
    bool validPalindrome(string s) {
        // we can atmost one deletion
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                break;
            }
            l++; r--;
        }

        if(l >= r) return true;

        string s1 = s.substr(0, l) + s.substr(l+1);
        string s2 = s.substr(0, r) + s.substr(r + 1);

        return checkPalin(s1) || checkPalin(s2);
    }
};

class Solution3 {
public:

    int lcs(string &str) {
        int n = str.size();
        string rstr = str;  
        reverse(rstr.begin(), rstr.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
      
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                if(str[i-1] == rstr[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }

    int maxProduct(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 1; i<(1 << n) - 1; i++) {
            string s1, s2;
            for(int j = 0; j<n; j++) {
                if(i & (1 << j)) {
                    s1.push_back(s[j]);
                } else {
                    s2.push_back(s[j]);
                }
            }
            ans = max(ans, lcs(s1) * lcs(s2));
        }
        return ans;
    }
};

class Solution4 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        int left = -1, right = -1;
        for(int len = 1; len <= n; len++) {
            for(int i = 0, j = i + len - 1; j<n; i++, j++) {
                if(len == 1) dp[i][j] = true;
                else if(len == 2) {if(s[i] == s[j]) dp[i][j] = true;}
                else if(len > 2) {
                    if(s[i] == s[j] and dp[i+1][j-1])
                        dp[i][j] = true;
                }
                if(dp[i][j]) {
                    left = i;
                    right = j;
                }
            }
        }
        if(left == -1) return "";
        return s.substr(left, right - left + 1);
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