#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


int cntNDigNumsSum(int n, int sum) {
    if(n == 0)
        return sum == 0;
    if(sum == 0)
        return 1;
    if(sum < 0)
        return 0;
    if(n < 0)
        return 0;
    
    int ans = 0;
    for(int i = 0; i<=9; i++) {
        ans += cntNDigNumsSum(n - 1, sum - i);
    }
    return ans;
}

int solve(int n, int sum) {
    int ans = 0;
    for(int i = 1; i<=9; i++) {
        ans += cntNDigNumsSum(n - 1, sum - i);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 2, sum = 5;
    cout << solve(n, sum);
    return 0;
}