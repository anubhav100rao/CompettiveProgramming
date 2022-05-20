#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

int solve(vector<vector<int>>&matrix) {
    int n = matrix.size();
    vector<vector<int>>dp(n, vector<int>(n, 1));
    int ans = 1;
    for(int i = 1; i<n; i++) {
        for(int j = 1; j<n; j++) {
            if(matrix[i][j] == matrix[i-1][j] 
                and matrix[i][j] == matrix[i][j-1] 
                and matrix[i][j] == matrix[i-1][j-1])
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;

            ans = max(ans, dp[i][j]);

        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    vector<vector<int>>matrix = { {2, 2, 3, 3, 4, 4},
                        {5, 5, 7, 7, 7, 4},
                        {1, 2, 7, 7, 7, 4},
                        {4, 4, 7, 7, 7, 4},
                        {5, 5, 5, 1, 2, 7},
                        {8, 7, 9, 4, 4, 4}
                      };
    cout << solve(matrix);
    return 0;
}