#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int solve(int digits, int oddSum, int evenSum, bool isOdd, int n) {

    if(digits == n)
        return (oddSum - evenSum == 1);
    int ans = 0;
    for(int i = 0; i<=9; i++) {
        if(isOdd)
            ans += solve(digits + 1, oddSum + i, evenSum, false, n);
        else
            ans += solve(digits + 1, oddSum, evenSum + i, true, n);
    }
    return ans;
}

int countNdigNums(int n) {
    int ans = 0;
    for(int i = 1; i<=9; i++) {
        ans += solve(1, i, 0, false, n);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 3;
    cout << countNdigNums(n);
    return 0;
}