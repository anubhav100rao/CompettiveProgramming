#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<vector<int>>>dp;


int lcs_k_changes(vector<int>&arr, vector<int>&brr, int k, int i, int j) {
    if(i < 0 || j < 0)
        return 0;
    
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    


    if(arr[i] == brr[j]) {
        return dp[i][j][k] = 1 + lcs_k_changes(arr, brr, k, i-1, j-1);
    }

    if(k > 0) {
       return  dp[i][j][k] = max(
            {
                lcs_k_changes(arr, brr, k, i-1, j),
                lcs_k_changes(arr, brr, k, i, j-1),
                1 + lcs_k_changes(arr, brr, k-1, i - 1, j- 1),
            }
        );
    }

    return dp[i][j][k] = max(
        {
            lcs_k_changes(arr, brr, k, i-1, j),
            lcs_k_changes(arr, brr, k, i, j-1)
        }
    );

}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif

    dp = vector<vector<vector<int>>>(10, vector<vector<int>>(10, vector<int>(10, -1)));

    vector<int>arr = { 1, 2, 3, 4, 5 };
    vector<int>brr = { 1, 2, 3, 4, 5 };

    cout << lcs_k_changes(arr, brr, 1, arr.size() - 1, brr.size() - 1);
 
    return 0;
}