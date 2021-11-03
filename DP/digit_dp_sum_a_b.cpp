#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

vector<vector<vector<int>>>dp(20, vector<vector<int>>(162, vector<int>(2, -1)));
// (numbers <= 10**20), (sum of digits <= 9 * 18 = 162), (tight = 0 or 1)

void digsum(int n, vector<int>&digits) {
    while(n) {
        digits.push_back(n%10);
        n /= 10;
    }
}

long long getDigitSum(int idx, int sm, int tight, vector<int>&digits) {
    if(idx < 0) return sm;
    if(dp[idx][sm][tight] != -1 and tight != 1) return dp[idx][sm][tight];

    long long ret = 0;
    int k = tight ? digits[idx] : 9;
    for(int i = 0; i<=k; i++) {
        int newTight = digits[idx] == i ? tight: 0;
        ret += getDigitSum(idx-1, sm + i, newTight, digits);
    }
    if(!tight) dp[idx][sm][tight] = ret;
    return ret;
}

int solve(int a, int b) {
    vector<int>dig_a;
    digsum(a-1, dig_a);

    vector<int>dig_b;
    digsum(b, dig_b);

    int ans1 = getDigitSum(dig_a.size()-1, 0, 1, dig_a);
    int ans2 = getDigitSum(dig_b.size() - 1, 0, 1, dig_b);
    return (ans2 - ans1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    int a, b; cin >> a >> b;
    cout << solve(a, b);
    return 0;
}