#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int get_digits(int n) {
    int res = 0;
    while(n) {
        res++;
        n /= 10;
    }
    return res;
}

vector<vector<int>>dp;

int solve(string &num, int n, int x, bool flag) {
    if(x < 0)
        return 0;
    if(n == 1) {
        if(x >= 0 and x <= 9)
            return 1;
        return 0;
    }

    if(dp[n][x] != -1)
        return dp[n][x];

    int ans = 0;
    
    if(flag) {
        int lim = num[n-1] - '0';
        for(int i = 0; i<lim; i++) {
            ans += solve(num, n - 1, x - i, false);
        }
        ans += solve(num, n-1, x - lim, true);
    } else {
        for(int i = 0; i<=9; i++) {
            ans += solve(num, n - 1, x - i, false);
        }
    }
    return dp[n][x] = ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string l, r; int x; cin >> l >> r >> x;
    int r_s = r.size();
    reverse(r.begin(), r.end());
    l = to_string(stoi(l) - 1);
    reverse(l.begin(), l.end());
    int l_s = l.size();

    dp = vector<vector<int>>(r_s+1, vector<int>(x+1, -1));
    int top = solve(r, r_s, x, true);
    dp = vector<vector<int>>(r_s + 1, vector<int>(x+1, -1));
    int bot = solve(l, l_s, x, true);

    cout << top - bot << '\n';
    return 0;
}