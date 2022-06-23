#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

class Solution{
public:

    // n * n approach
    int minCut(string a)
    {
        int cut[a.length()];
        bool palindrome[a.length()][a.length()];
        memset(palindrome, false, sizeof(palindrome));
        for (int i = 0; i < a.length(); i++)
        {
            int minCut = i;
            for (int j = 0; j <= i; j++)
            {
                if (a[i] == a[j] && (i - j < 2 || palindrome[j + 1][i - 1]))
                {
                    palindrome[j][i] = true;
                    minCut = min(minCut, j == 0 ? 0 : (cut[j - 1] + 1));
                }
            }
            cut[i] = minCut;
        }
        return cut[a.length() - 1];
    }

    // idea Matrix Chain Multiplication

    vector<vector<bool>>palin;
    vector<vector<int>>dp;


    int solve(int i, int j, string &str) {
        if(i >= j) return 0;

        if(palin[i][j]) return 0;

        if(j - i == 1) {
            if(str[i] == str[j]) return 0;
            return 1;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;

        for(int k = i; k < j; k++) {
            res = min(res, solve(i, k, str) + solve(k + 1, j, str) + 1);
        }
        return dp[i][j] = res;
    }


    int palindromicPartition(string str) {
        int n = str.size();
        
        palin = vector<vector<bool>>(n, vector<bool>(n, false));
        for(int len = 1; len <= n; len++) {
            for(int i = 0, j = i + len - 1; j < n; i++, j++) {
                if(i == j) palin[i][j] = true;
                else if(j - i == 1) palin[i][j] = str[i] == str[j];
                else palin[i][j] = (str[i] == str[j]) and palin[i+1][j-1];
            }
        }

        dp = vector<vector<int>>(n, vector<int>(n, n-1));

        for(int len = 1; len <= n; len++) {
            for(int i = 0, j = i + len - 1; j < n; i++, j++) {
                if(i == j) dp[i][j] = 0;
                else if(j - i == 1) dp[i][j] = !palin[i][j];
                else {
                    if(palin[i][j]) dp[i][j] = 0;
                    else {
                        for(int k = i; k<j; k++) {
                            dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k+1][j]);
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    Solution sol;
    string str; cin >> str;
    cout << sol.palindromicPartition(str) << "\n";
    return 0;
}