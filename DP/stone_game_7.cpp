#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution1 {
public:

    vector<int>pre;
    int n;

    vector<vector<int>>dp;

    int solve(int i, int j) {
        if(i > j) return 0;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(((n & 1) and ((j - i - 1) & 1)) or (n % 2 == 0 and (j - i -1) % 2 == 0)) {
            return dp[i][j] = max(solve(i + 1, j) + pre[j] - pre[i], solve(i, j - 1) + pre[j - 1] - pre[i-1]);
        }

        return dp[i][j] = min(solve(i + 1, j) - (pre[j] - pre[i]), solve(i, j - 1) - (pre[j - 1] - pre[i-1]));
    }

    int stoneGameVII(vector<int>& stones) {
        n =  stones.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        pre = vector<int>(n + 1, 0);

        for(int i = 1; i<=n; i++) {
            pre[i] = pre[i-1] + stones[i-1];
        }

        return solve(1, n);
    }
};

class Solution {
public:

    int n;
    vector<int>stones;
    vector<vector<int>>dp;
    int solve(int i, int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(((n & 1) and ((j - i - 1) & 1)) or (n % 2 == 0 and (j - i -1) % 2 == 0)) {
            return dp[i][j] = max(solve(i + 1, j), solve(i, j - 1));
        }

        return dp[i][j] = min(solve(i + 1, j) + stones[i], solve(i, j - 1) +  stones[j]);
    }

    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        this->stones = stones;
        return solve(0, n-1);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif

    auto start = high_resolution_clock::now();
    
    Solution sol;
    vector<int>stones = {1, 2};
    cout << sol.stoneGameVII(stones) << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}