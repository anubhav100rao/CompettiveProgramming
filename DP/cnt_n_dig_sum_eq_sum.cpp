#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"


vector<vector<int>>dp;

int solve(int n, int sum) {

    if(n == 0 and sum == 0)
        return 1;

    if(n <= 0)
        return 0;

    int cnt = 0;
    if(n > 1)
        for(int i = 0; i<=9; i++) {
            if(sum >= i)
                cnt += solve(n - 1, sum - i);
        }
    else
        for(int i = 1; i<=9; i++) {
            if(sum >= i)
                cnt += solve(n - 1, sum - i);
        }
    return dp[n][sum] = cnt;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    int n, sum; cin >> n >> sum;
    dp = vector<vector<int>>(n+1, vector<int>(sum + 1, -1));
    cout << solve(n, sum) << '\n';
    return 0;
}