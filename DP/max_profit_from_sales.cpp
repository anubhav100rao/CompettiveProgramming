#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<int>>dp;
vector<vector<int>>sell;

int solve(vector<int>&price, int i, int j, int n) {
    int year = n - (j - i);
    if(i > j)
        return 0;
    if(i == j)
        return year * price[i];

    if(dp[i][j] != -1)
        return dp[i][j];
    int x = price[i] * year + solve(price, i+1, j, n);
    int y = price[j] * year + solve(price, i, j-1, n);

    int ans = max(x, y);
    dp[i][j] = ans;

    if(x >= y)
        sell[i][j] = 0;
    else
        sell[i][j] = 1;
    
    return ans;
}

int maxProfit(vector<int>&price) {
    int n = price.size();
    dp = vector<vector<int>>(n + 1, vector<int>(n+1, -1));
    sell = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

    int ans = solve(price, 0, n-1, n);
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int>price = {2, 4, 6, 2, 5};
    cout << maxProfit(price);
    return 0;
}