#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<int>>dp;

void retrace(string &a, string &b, int i, int j, string &str) {
    if(i == a.size() || j == b.size()) return;

    

    if(a[i] == b[j]) {
        str.push_back(a[i]);
        retrace(a, b, i + 1, j + 1, str);
    }
    else {
        if(dp[i][j + 1] > dp[i+1][j]) {
            retrace(a, b, i, j + 1, str);   
        } else {
            retrace(a, b, i + 1, j, str);
        }
    }
}

int lcs(string &a, string &b, int i, int j) {
    if(i == a.size() || j == b.size()) return dp[i][j] = 0;

    if(dp[i][j] != -1) 
        return dp[i][j];

    if(a[i] == b[j]) 
        return dp[i][j] = lcs(a, b, i + 1, j + 1) + 1;
    else
        return dp[i][j] = max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif

    string a, b; cin >> a >> b;
    string str = "";

    dp = vector<vector<int>>(a.size() + 1, vector<int>(b.size() + 1, -1));

    cout << lcs(a, b, 0, 0) << "\n";

    retrace(a, b, 0, 0, str);
    cout << str << '\n';

    return 0;
}