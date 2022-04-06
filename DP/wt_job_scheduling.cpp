#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct Job {
    int start;
    int finish;
    int profit;
};

int findLastest(Job arr[], int i) {
    for(int j = i-1; j>=0; j--) {
        if(arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}

int findMaxProfit(Job arr[], int n) {
    sort(arr, arr + n, [&](const Job &a, const Job &b) {
        return a.finish < b.finish;
    });

    vector<int>dp(n, 0);
    dp[0] = arr[0].profit;

    for(int i = 1; i<n; i++) {
        int inc = arr[i].profit;
        int exlc = dp[i-1];
        int latest = findLastest(arr, i);
        if(latest != -1) {
            inc += dp[latest];
        }
        dp[i] = max(inc, exlc);
    }
    return dp[n-1];
}



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