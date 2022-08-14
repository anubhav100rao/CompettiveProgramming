#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int N, W;
vector<int>wt, val;
vector<vector<int>>dp;

void retrace(int idx, int w, vector<int>&arr) {

    if(idx >= N) return;

    if(wt[idx] <= w) {
        if(val[idx]+dp[idx + 1][w - wt[idx]] > dp[idx + 1][w]) {
            cout << "getting\n";
            arr.push_back(idx);
            retrace(idx + 1, w - wt[idx], arr);
        } else {
            retrace(idx + 1, w, arr);
        }
    } else {
        retrace(idx + 1, w, arr);
    }

}

int knapsack(int idx, int w) {

    if(idx >= N) return dp[idx][w] = 0;

    
    int take = INT_MIN, not_take = INT_MIN;
    if(wt[idx] <= w) {
        take = knapsack(idx + 1, w - wt[idx]) + val[idx];
        not_take = knapsack(idx + 1, w);

        return dp[idx][w] = max(take, not_take);
    } else {
        not_take = knapsack(idx + 1, w);
        return dp[idx][w] = not_take;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    cin >> N >> W;

    val = vector<int>(N);
    wt = vector<int>(W);

    for(int &i: val) cin >> i;
    for(int &i: wt) cin >> i;

    dp = vector<vector<int>>(N + 1, vector<int>(W + 1, -1));

    cout << knapsack(0, W) << "\n";

    

    vector<int>arr;

    retrace(0, W, arr);

    for(int &i: arr) cout << i << " ";


    return 0;
}